# Cnipe-Bot
A C++ Rewrite of the Snipe-Bot I wrote about a year or two ago.

[Original Snipe Bot](https://github.com/ssenr/Snipe-Bot)

# To Do

-   [ ] (Possibly) switch from Macro to type declaration if more things are required in config.h header
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
Using g++ 
```bash 
g++ ./src/main.cpp -o cnipe-bot -ldpp
```

# Cache/Database Structure
```
├── message_delete_cache
│   ├── Stores All Messages Sent In A Server
│   └── Multi-threaded for cache cleaning purposes
├── message_edit_cache
│   ├── Retries Message Object From message_delete_cache with ID
│   └── Multi-threaded for cache cleaning purposes
```
