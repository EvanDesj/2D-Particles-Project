# README for 3GC3 A2

This README file documents how to compile and run the particle project, what controls to use inside the project, and all the websites that helped me complete this assignment. This project was done on Windows 10 using Visual Studio Code to program and the recommended mingw64 environment to run and compile the code.

## Compiling with the makefile

To compile the particle project, navigate to folder where the makefile is kept, `cd <path to repo>/desjarde/A2`. Use the command `make` to compile all the needed files inside the folder and the particle project will run automatically. When finished, `make clean`  will remove all the files created when compiling.

## Using particle.cpp
The program begins by populating the screen with 300 particles that have random attributes. One of those attributes is a range specific to each particle. If the left mouse button is pressed and the cursor is within range of a particle then it will be attracted towards the mouse, while if the right mouse button is pressed and a particle is within range of the cursor it will be repelled. If a particle reaches the cursor and is big enough to split, it will explode on contact with the mouse into four smaller particles. These particles, along with any other particles of the same colour, can merge back together if they get close enough to each other. Lastly, if particles reach the edge of the application window they will be teleported across to the other side.

Keyboard Controls for particle.cpp:

q/Q: close the program
a/A: add a particle on the screen at the mouse's position
d/D: delete the particle nearest to the mouse
+: increase the range at which your mouse effects particles
-: decrease the range at which your mouse effects particles
space: pause the program
r/R: reset the program, deleting all current particles and refilling the screen
up arrow: increase the speed particles move with
down arrow: decrease the speed particles move with


## Sources

[Handling application resizing](http://www.swiftless.com/tutorials/opengl/reshape.html)

[Understanding header files](https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-160)

3GC3 Week 3 and 4 Slides