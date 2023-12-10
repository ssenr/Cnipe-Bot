# Cnipe-Bot
A (Possible Over-engineered) C++ Rewrite of the Snipe-Bot I wrote about a year or two ago.

[Original Snipe Bot](https://github.com/ssenr/Snipe-Bot)

# To Do

-   [x] Possibly switch from Macro to type declaration if more things are required in config.h header
-   [x] Connect to local SQLite database
-   [x] Cache Messages with dpp::cache 
-   [ ] Replace replicate dpp::message datatype in SQL 
-   [ ] Store every created message in SQL 
-   [ ] Store every deleted message in SQL 
-   [ ] Measure the disk sizes of the database vs cache 
-   [ ] Create a general "garbage collector" that handles functionality or checking size and removing elements from cache
-   [ ] Store cached messages in local database
-   [ ] Extend "garbage collector" to SQLite3
-   [ ] Finish sniping functionality
-   [ ] Deduce logic for edit sniping 

# Goals

This Bot was created to provide an interesting C++ learning exercise, as well as provide significant improvements to my old code. Improvements and new features include:

-   [ ] Faking Discord Messages (Image Processing using a Template)
-   [ ] Sniping Edited Messages
-   [ ] The Ability to Display links and Images in Embedded Messages
-   [ ] Bot does not snipe messages from Users with certain roles (BOTS)
-   [ ] Snipe doesn't work when a user leaves the server (PFP Image Grabbing)
-   [ ] Reply Snipe (Attachment/Message Handling)
-   [ ] Make a blog post

# Compilation
Using CMake:
```
./build.sh
# or 
./clean-build.sh
```
Only difference in scripts being clean-build.sh will remove all contents and force Cmake to make a new build configuration (Which may resolve some errors or weird behaviour).
# Resources

[Install and Use SQLite3](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-sqlite-on-ubuntu-20-04)
[Using SQLite3 and Python](https://www.youtube.com/watch?v=byHcYRpMgI4)
