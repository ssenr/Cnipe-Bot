# Cnipe-Bot

A C++ Rewrite of the Snipe-Bot I wrote about a year ago.

[Original Snipe Bot](https://github.com/ssenr/Snipe-Bot)

# To Do
-   [ ] Add a more general "garbage collector" that syncs queues with cache status

# Goals

This Bot was created to provide an interesting C++ learning exercise, as well as provide significant improvements to my old code. Improvements and new features include:

-   [ ] Faking Discord Messages (Image Processing using a Template)
-   [ ] Sniping Edited Messages
-   [ ] The Ability to Display links and Images in Embedded Messages
-   [ ] Bot does not snipe messages from Users with certain roles (BOTS)
-   [ ] Snipe doesn't work when a user leaves the server (PFP Image Grabbing)
-   [ ] Reply Snipe (Attachment/Message Handling)
-   [ ] Make a blog post

# How to Build

## Requirements

-   Cmake (ver 3.15+)
-   C++ Compiler

Run the commands:

```bash
cmake -B ./build
cmake --build ./build
```

then run .exe generated in ./build folder :).

# Cache/Database Structure
```
├── message_delete_cache
│   ├── Stores All Messages Sent In A Server
│   └── Multi-threaded for cache cleaning purposes
├── message_edit_cache
│   ├── Retries Message Object From message_delete_cache with ID
│   └── Multi-threaded for cache cleaning purposes
```
