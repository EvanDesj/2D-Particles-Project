# COMPSCI 3GC3 - Assignment 2

## Evan Desjardine

This README file documents how to compile and run the particle project, what controls to use inside the project, and all the websites that helped me complete this assignment. This project was done on Windows 10 using Visual Studio Code to program and the recommended mingw64 environment to run and compile the code.

## Compiling with the makefile

To compile the particle project, navigate to folder where the makefile is kept, `cd <path to repo>/desjarde/A2`. Use the command `make` to compile all the needed files inside the folder and the particle project will run automatically. When finished, `make clean`  will remove all the files created when compiling.

## Using particle.cpp
The program begins by populating the screen with 300 particles that have random attributes. One of those attributes is a range specific to each particle. If the left mouse button is pressed and the cursor is within range of a particle then it will be attracted towards the mouse, while if the right mouse button is pressed and a particle is within range of the cursor it will be repelled. If a particle reaches the cursor and is big enough to split, it will explode on contact with the mouse into four smaller particles. These particles, along with any other particles of the same colour, can merge back together if they get close enough to each other. Lastly, if particles reach the edge of the application window they will be teleported across to the other side.

# Keyboard Controls

- `q/Q`: Quit  
- `a/A`: Add a particle on the screen at the mouse's position  
- `d/D`: Delete the closest particle to the mouse  
- `+`: Increase the range at which your mouse effects particles  
- `-`: Decrease the range at which your mouse effects particles  
- `space`: Pause
- `r/R`: Reset, deleting all current particles and refilling the screen  
- `Arrow Key Up`: increase particles' movement speed
- `Arrow Key Down`: decrease particles' movement speed


## Sources

[Handling application resizing](http://www.swiftless.com/tutorials/opengl/reshape.html)

[Understanding header files](https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-160)

3GC3 Week 3 and 4 Slides
