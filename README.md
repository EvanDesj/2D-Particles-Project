# COMPSCI 3GC3 - Assignment 2

## Evan Desjardine

This README file documents how to compile and run the particle project, what controls to use inside the project, and all the websites that helped me complete this assignment. This project was done on Windows 10 using Visual Studio Code to program and the recommended mingw64 environment to run and compile the code.

## Compiling with the makefile

To compile the particle project, navigate to folder where the makefile is kept, `cd <path to repo>/desjarde/A2`. Use the command `make` to compile all the needed files inside the folder and the particle project will run automatically. When finished, `make clean`  will remove all the files created when compiling.

## Function and Features
- Populate the screen with 
- Press Left Mouse Button to attract particles
- Press Right Mouse Button to repel particles
- If a particle is large enough, it will explode into four smaller particles when it touches the mouse
- Particles that are the same colour will merge together and grow if they get close enough to each other
- Particles pushed beyond the edge of the program window will be teleported across to the other side

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
