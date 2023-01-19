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

# How to Build

## Requirements

-   Cmake (ver 3.15+)
-   C++ Compiler

Run the commands:

```ssh
cmake -B ./build
cmake --build ./build
```

then run .exe generated in ./build folder :).

## Git Conflicts

In the case of pull conflicts such as divergent branches. Feel free to run the command

```ssh
git config pull.rebase true
```

This enables rebase on pulls. Rebase merges local unpublished changes with ones in the repository. However, with proper care you should not need to do this as long as you have aware and up to date.

## OpenSSL Errors

On Mac, with CMAKE you may run into an error in which OpenSS, specifically the root folder (or some modules) are not found. If you are using homebrew, run:

```ssh
brew link openssl --force
```

which will force syslinks and will likely make the CMAKE build work.

On WSL2 (Ubuntu Distro) run:

``ssh
sudo apt-get install libssl-dev
```
