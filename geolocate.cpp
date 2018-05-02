/*
 * address.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: acraun
 */

#include "geolocate.h"

GeoLocate::GeoLocate() {
    this->loadApiKey();
}

GeoLocate::~GeoLocate() {
}

void GeoLocate::loadApiKey() throw(LoadingKeyException) {
    char key[1024];
    ifstream in("google_geocode_key.txt");
    if(in.is_open()) {
        in.getline(key,1024);
    } else {
        throw LoadingKeyException();
    }
    in.close();
    geocodeApiKey = key;
}

size_t GeoLocate::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void GeoLocate::getGeoData(double lat, double lon) {
    CURL* curl;
    CURLcode response;

    curl = curl_easy_init();
    if(curl) {
        string request;
        string results;

        request = GEOCODE_URL;
        request += "latlng=" + to_string(lat) + "," + to_string(lon);
        request += "&key=" + geocodeApiKey;

        char url[1024];
        strcpy(url, request.c_str());
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &results);

        response = curl_easy_perform(curl);

        if(response != CURLE_OK) {
            cout << "curl_easy_perform() failed." << endl;
        }
        curl_easy_cleanup(curl);
//        cout << results;

        const char* json = results.c_str();
        Document d;
        d.Parse(json);
        const Value& a = d["results"][0]["address_components"];
        for(int i = 0; i < a.Size(); i++) {
            if(!strcmp(a[i]["types"][0].GetString(), "postal_code")) {
                this->setZip(a[i]["short_name"].GetString());
            } else if (!strcmp(a[i]["types"][0].GetString(), "administrative_area_level_1")) {
                this->setState(a[i]["short_name"].GetString());
            } else if (!strcmp(a[i]["types"][0].GetString(), "locality")) {
                this->setCity(a[i]["short_name"].GetString());
            } else if (!strcmp(a[i]["types"][0].GetString(), "route")) {
                this->setStreet(a[i]["short_name"].GetString());
            } else if (!strcmp(a[i]["types"][0].GetString(), "street_number")) {
                this->setStreetNumber(a[i]["short_name"].GetString());
            }

        }
    }
}

string GeoLocate::getStreetNumber() {
    return streetNumber;
}

void GeoLocate::setStreetNumber(string streetNumber) {
    this->streetNumber = streetNumber;
}

string GeoLocate::getStreet() {
    return street;
}

void GeoLocate::setStreet(string street) {
    this->street = street;
}

string GeoLocate::getCity() {
    return city;
}

void GeoLocate::setCity(string city) {
    this->city = city;
}

string GeoLocate::getState() {
    return state;
}

void GeoLocate::setState(string state) {
    this->state = state;
}

string GeoLocate::getZip() {
    return zip;
}

void GeoLocate::setZip(string zip) {
    this->zip = zip;
}

void GeoLocate::print() {
    if (!streetNumber.empty()) cout << "street #: " << streetNumber << endl;
    if (!streetNumber.empty()) cout << "street:   " << street << endl;
    cout << "city:     " << city << endl;
    cout << "state:    " << state << endl;
    cout << "zip code: " << zip << endl;

}

void GeoLocate::test() {
    try {
        GPS* pGPS = new GPS;
        pGPS->getCoordinates();
        cout << "Getting coordinates from GPS class..." << endl;
        pGPS->print();
        cout << endl;

        GeoLocate aGeoLocate;
//        aGeoLocate.getGeoData(26.372519,-80.102791);

        aGeoLocate.getGeoData(pGPS->getLattitude(), pGPS->getLongitude());
        delete pGPS;
        pGPS = 0;

        cout << "Getting location info from GeoLocate class..." << endl;
        aGeoLocate.print();
    }
    catch(BaseException& e){
        e.print();
    }

}
