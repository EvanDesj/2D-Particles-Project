# COMPSCI 3GC3 - Assignment 2

## Evan Desjardine

This README file documents how to compile and run the particle project, what controls to use inside the project, and all the websites that helped me complete this assignment. This project was done on Windows 10 using Visual Studio Code to program and the recommended mingw64 environment to run and compile the code.

## Compiling

To compile the particle project, use the command `make` wherever this repo has been cloned. When finished, `make clean`  will remove all the object files created.

## Function and Features
- Populate the screen with 300 particles with random colour, size and speed
- Press Left Mouse Button to attract particles
- Press Right Mouse Button to repel particles
- Large particles will explode into four smaller particles if touching the mouse
- Particles that are the same colour will merge together if touching
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
