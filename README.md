# Cnipe-Bot

A C++ Rewrite of the Snipe-Bot I wrote about a year ago.

[Original Snipe Bot](https://github.com/ssenr/Snipe-Bot)

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
│
```

# OpenSSL Errors

On Mac, with CMAKE you may run into an error in which OpenSS, specifically the root folder (or some modules) are not found. If you are using homebrew, run:

```bash
brew link openssl --force
```

which will force a symlink and will likely make the CMAKE build work.

On Linux:

```bash
sudo apt-get install libssl-dev
```
substitute apt-get with any other package manager that is relevant. Or conversely,

```bash
ln -s <openssl path> <work folder>
```
to create a symlink yourself (linux/unix like systems).
