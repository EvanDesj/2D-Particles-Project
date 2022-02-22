/*
    3GC3 A2 Particle System
    Evan Desjardine
    - MacID: desjarde
    - Email: [desjarde@mcmaster.ca](mailto:desjarde@mcmaster.ca)
    - Date: Oct 15, 2021
    - Operating System: Windows 10
 */

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <tgmath.h>
#include "mathLib2D.h"
#include "colour.h"

//GLUT CONSTANTS
#define WINDOW_TITLE "Assignment 2"

/* Global Variables */
bool animate = true;		//control whether the animation is running or not
bool leftClick = false;		//check whether left mouse is pressed
bool rightClick = false;	//check whether right mouse is pressed

float animationTime = 1.0f;		//animation time variable

int gSpeed = 5;				//global factor to control overall particle speed with up and down arrows
int gRange = 3;				//global factor to control overall particle range with - and +
int gHeight = 600;			//global window height variable
int gWidth = 800;			//global window width variable
int gParticleAmount = 300;	//global particle amount for starting and resetting screen
int particlesIndex = 0;		//global variable for particles position in particle vector

Point2D mousePos;			//global mouse position


//particle class that holds information about each instance of a particle
class Particle {
public:
	Point2D position;
	float size, range, speed;
	Colour colour;
	Vec2D direction;
	bool explode;
	int index;

	//create a particle with default values at position x and y
	Particle(float x, float y) {	
		this->position = Point2D(x, y);
		this->size = rand() % 14 + 2;
		this->range = rand() % 50 + 25;
		this->speed = ((rand() % 10) / 5000.0) + 0.0002;
		this->colour = Colour();
		this->direction = Vec2D(0.0, 0.0);
		this->explode = false;
		this->index = particlesIndex;
		particlesIndex++;
	}

	//create a particle with more custom values
	Particle(float x, float y, float size, float range, float speed, Colour colour) {
		this->position = Point2D(x, y);
		this->size = size;
		this->range = range;
		this->speed = speed;
		this->colour = colour;
		this->direction = Vec2D(0.0, 0.0);
		this->explode = false;
		this->index = particlesIndex;
		particlesIndex++;
	}

	void update() {
		//if particle is not right on the mouse and doesn't have a vector of 0,0, then update the position
		if (this->position.distanceTo(mousePos) > 3 && this->direction.mX != 0 && this->direction.mY != 0 && (leftClick || rightClick)) {	
			float xAdjust = this->direction.mX * this->speed * gSpeed;
			float yAdjust = this->direction.mY * this->speed * gSpeed;
			if (leftClick) {
				this->position = Point2D(this->position.mX - xAdjust, this->position.mY - yAdjust); //move particle towards mouse
			} else if (rightClick) {
				this->position = Point2D(this->position.mX + xAdjust, this->position.mY + yAdjust); //move particle away from mouse
			}

			if (this->position.mX > gWidth) {
				this->position.mX -= gWidth;
			} else if (this->position.mX < 0 ) {
				this->position.mX += gWidth;
			}

			if (this->position.mY > gHeight) {
				this->position.mY -= gHeight;
			} else if (this->position.mY < 0 ) {
				this->position.mY += gHeight;
			}
		} else if (this->position.distanceTo(mousePos) < 3 && this->size > 8) {
			this->explode = true;
		}
	}

	void draw() { //draw the particle using colour position and size
		glColor3f(this->colour.mR, this->colour.mG, this->colour.mB);
		glPointSize(this->size);
		glBegin(GL_POINTS);
		glVertex2f(this->position.mX, this->position.mY);
		glEnd();
	}
};


std::vector<Particle*> particles;	//vector to hold all Particle objects


//user instructions to use the particle system
void printInstructions() {
	std::cout << "\nWelcome to the 3GC3 Assignment 2 Particle System Instructions!\n" << std::endl;

	std::cout << "Here are the controls you will need to know to use the program:\n" << std::endl;
	std::cout << "q/Q: close the program\n" << std::endl;
	std::cout << "left mouse down: attract particles towards your cursor\n" << std::endl;
	std::cout << "right mouse down: deflect particles away from your cursor\n" << std::endl;
	std::cout << "a/A: add a particle at the mouse\n" << std::endl;
	std::cout << "d/D: delete the particle nearest to your mouse\n" << std::endl;
	std::cout << "+: increase the range at which your mouse effects particles\n" << std::endl;
	std::cout << "-: decrease the range at which your mouse effects particles\n" << std::endl;
	std::cout << "space: pause the program\n" << std::endl;
	std::cout << "r/R: reset the program, deleting all current particles and refilling the screen\n" << std::endl;
	std::cout << "up arrow: increase the speed particles move with\n" << std::endl;
	std::cout << "down arrow: decrease the speed particles move with\n\n" << std::endl;

	std::cout << "Besides from the controls, you will see as you use the program that if a" << std::endl;
	std::cout << "particle is large enough it will explode when it comes in contact with the " << std::endl;
	std::cout << "cursor. Similarly, if two particles are the same colour they will merge" << std::endl;
	std::cout << "together in close contact. Particles will also teleport across from one" << std::endl;
	std::cout << "side of the screen to another if they reach an edge.\n" << std::endl;
	std::cout << "That's all you need to know, have fun!\n" << std::endl;
}

void removeParticle(Particle* p) {  //remove a particle from the particles vector and update all the particles indices
	int index = p->index;
	particles.erase(particles.begin() + index);
	delete p;
	for (std::vector<Particle*>::size_type i = index; i < particles.size(); i++){
		particles[i]->index--;
	}
	particlesIndex--;
}


void directionUpdate() {
	//update the vector to mouse of each particle that is within range
	for (Particle* p : particles) {
		if (mousePos.distanceTo(p->position) <= p->range*gRange) {
			p->direction = Vec2D::createVector(mousePos, p->position);
		} else {
				p->direction = Vec2D(0.0, 0.0);
		}
	}
}


void explosionUpdate() {
	for (Particle* p : particles) {
		if (p->explode) {
			int randDistance = (rand() % 50 + 35);
			int randVariance = (rand() % 101 - 50);
			particles.push_back(new Particle(p->position.mX + randDistance, p->position.mY + randVariance, floor((p->size / 4)), p->range, p->speed, p->colour));
			particles.push_back(new Particle(p->position.mX - randDistance, p->position.mY + randVariance, floor(p->size / 4), p->range, p->speed, p->colour));
			particles.push_back(new Particle(p->position.mX + randVariance, p->position.mY + randDistance, ceil(p->size / 4), p->range, p->speed, p->colour));
			particles.push_back(new Particle(p->position.mX + randVariance, p->position.mY - randDistance, ceil(p->size / 4), p->range, p->speed, p->colour));
			removeParticle(p);
		} 
	}
}


void mergeUpdate() {
	for (std::vector<Particle*>::size_type i = 0; i < particles.size(); i++) {
		for (std::vector<Particle*>::size_type j = i+1; j < particles.size(); j++) {	//break from i+1?
			Particle* p = particles[i];
			if (p->size > 16) {
				continue;
			} else {
				Particle* q = particles[j];
				if (p->colour.isColour(q->colour) && p->position.distanceTo(q->position) < 1) {
					particles.push_back(new Particle((p->position.mX + q->position.mX)/2, (p->position.mY + q->position.mY)/2,
													p->size + q->size, (p->range + q->range)/2, (p->speed + q->speed)/2, p->colour));
					removeParticle(p);
					removeParticle(q);
				}
			}
		}
	}
}


//add the given amount of particles to the screen
void fillScreen(int pAmount) {
	for (int i = 0; i < pAmount; i++) {
		particles.push_back(new Particle(rand() % gWidth, rand() % gHeight));
	}
}


void animation(int value) {
	if (animate) {  //if animation is running update all the particles and redisplay the screen
		directionUpdate();
		explosionUpdate();
		mergeUpdate();
		for (Particle* p : particles) {
			p->update();
		}
		glutPostRedisplay();
	}
	glutTimerFunc(animationTime, animation, 0);
}


void init(void) {
	//prepare window
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(gWidth, gHeight);
	glutCreateWindow(WINDOW_TITLE);

	//set background colour and view
	glClearColor(0.0, 0.0, 0.0, 1);
	glColor3f(1, 1, 1);
	gluOrtho2D(0, gWidth, 0, gHeight);
	
	printInstructions();

	//add the given amount of particles to the screen
	fillScreen(gParticleAmount);
}


void mouse(int btn, int state, int x, int y) {
	y = gHeight - y;	//correct y for mouse coordinates
	mousePos = Point2D(x, y);	//update mouse position

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {	//update leftClick to true or false based on state
		leftClick = true;
		//std::cout << "Mouse position: " << x << "  " << y << std::endl;
	} else {leftClick = false;}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {	//update rightClick to true or false based on state
		rightClick = true;
	} else {rightClick = false;}
}


void kbd(unsigned char key, int x, int y) {
	y = gHeight - y;	//correct y for mouse coordinates
	switch(key) {		//switch the key that is pressed
		case 'q': case 'Q':		//q/Q closes the application
			exit(0);
			break;
		case 'a': case 'A':		//a/A to add a new particle at the mouse position
			particles.push_back(new Particle(x, y));
			break;
		case 'd': case 'D':		//d to delete the nearest particle
			mousePos = Point2D(x, y);
			if (particles.size() == 0) {
				break;
			} 
			else if (particles.size() == 1) {
				particles.erase(particles.begin());
				particlesIndex--;
			} else {
				int closest = 0;
				for (std::vector<Particle*>::size_type i = 1; i < particles.size(); i++){
					if (mousePos.fastDistanceTo(particles[i]->position) < mousePos.fastDistanceTo(particles[closest]->position)) {
						closest = i;
					}
				}
				removeParticle(particles[closest]);
			}
			break;
		case '-':		//- to decrease global range factor
			if (gRange > 1) {
				gRange -= 1;
			}
			break;
		case '+':		//+ to increase global range factor
			if (gRange < 5) {
				gRange += 1;
			}
			break;
		case ' ':		//space to disable particle movement
			animate = !animate;
			break;
		case 'r': case 'R':		//r/R to reset the screen
			particles.clear();
			particlesIndex = 0;
			fillScreen(gParticleAmount);
	}
	glutPostRedisplay();
}


void special(int key, int x, int y){
	switch(key) {
		case GLUT_KEY_UP:		//up arrow key to increase global speed factor
			if (gSpeed < 10) {
				gSpeed += 1;
			}
			break;
		case GLUT_KEY_DOWN:		//down arrow key to decrease global speed factor
			if (gSpeed > 1) {
				gSpeed -= 1;
			}
			break;
	}
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);	//clear the screen
	for (std::vector<Particle*>::size_type i = 0; i < particles.size(); i++){	//redraw each particle
		particles[i]->draw();
	}
	glutSwapBuffers();		//swap buffers for smoother animation
}


void motion(int x, int y) {
	y = gHeight - y;	//correct y for mouse coordinates
	mousePos = Point2D(x, y);	//update mouse position
}


void reshape(int w, int h) { 
	gWidth = w; //set global width 
	gHeight = h; //set global height
	glViewport(0, 0, w, h);
	glLoadIdentity();
	gluOrtho2D(0, gWidth, 0, gHeight);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);		//starts up GLUT    
	init();

	glutMouseFunc(mouse);
	glutKeyboardFunc(kbd);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutTimerFunc(animationTime, animation, 0);
	glutMotionFunc(motion);
	
	
	glutMainLoop();				//starts the event loop
	return(0);					//return may not be necessary on all compilers
}

