# Cnipe-Bot
A C++ Rewrite of the Snipe-Bot I wrote about a year ago. 

[Original Snipe Bot](https://github.com/ssenr/Snipe-Bot)

# Goals
This Bot was created to provide an interesting C++ learning exercise, as well as provide significant improvements to my old code. Improvements and new features include:
- [ ] Faking Discord Messages (Image Processing using a Template)
- [ ] Sniping Edited Messages
- [ ] The Ability to Display links and Images in Embedded Messages
- [ ] Bot does not snipe messages from Users with certain roles (BOTS)
- [ ] Snipe doesn't work when a user leaves the server (PFP Image Grabbing)
- [ ] Reply Snipe (Attachment/Message Handling)

# How to Build
## Requirements 
- Cmake (ver 3.15+)
- C++ Compiler

Run the commands:
```ssh
cmake -B ./build
cmake --build ./build
```
then run .exe generated in ./build folder :).
