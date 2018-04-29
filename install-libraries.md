# Install Libraries

## Mac

1. Make sure you pull the latest version.  There is a file called "libtwitcurl.dylib" in the "lib" folder.
2. Go to Codelite and click on the project settings:

  ![alt text](https://github.com/nazik5/The-Atlantic-0101-Safe-Roads/raw/master/common/codelite.png "Codelite")

  Under Library Path:

  ```
  Add the path to the "lib" folder in your local project.
  ```

  Under Libraries, add:

  ```
  curl;twitcurl
  ```

3. Try and compile the project.