/* testing git */
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <ctime>
#include "Pobj.h"

#define NUM_OF_FLOATS 5

using namespace std;

/***************************************************/

/* global variables */
static char d = ' ';

/* color for triangle */
GLfloat rt = 0.0, gt = 1.0, bt = 0.0;

/* color for square */
GLfloat rs = 1.0, gs = 0.0, bs = 0.0;

/* color for circle */
GLfloat rc = 0.0, gc = 0.0, bc = 1.0;

/* top and bottom suppliments */
GLfloat supTop = 0.0, supBottom = 0.0;

/* boundry variables */
GLfloat bTop = -0.9, bBottom = 0.9, bLeft = -0.9, bRight = 0.9, bThickness = 0.01;

/* floating objects */
Pobj listOfFloats[NUM_OF_FLOATS];

/***************************************************/

/* prototypes */
void adjustColor(GLfloat &r, GLfloat &g, GLfloat &b);
void display();
void keyboard (unsigned char key, int x, int y);
void reshape(int w, int h);

/***************************************************/

int main(int argc, char** argv)
{
	random_device rd;
	mt19937 e2(rd());
	uniform_real_distribution<> dist(-0.9, 0.9);
	
	for(int i = 0; i < NUM_OF_FLOATS; i++)
		listOfFloats[i] = Pobj(dist(e2), dist(e2), dist(e2), dist(e2));

	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_RGB);
	glutInitWindowSize (900, 500);
	glutInitWindowPosition (000, 000);
	glutCreateWindow ("Moving around");
	glutDisplayFunc (display);
	glutKeyboardFunc (keyboard);
	glutMainLoop();

	cout << "Done" << endl;
	return 0;
} /* main */

/***************************************************/

void keyboard (unsigned char key, int x, int y)
{
	
} /* keyboard */

/***************************************************/

void display()
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* draw boundries */
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(bTop, bLeft, 0.0);
		glVertex3f(bTop, bRight, 0.0);
		glVertex3f(bBottom, bRight, 0.0);
		glVertex3f(bBottom, bLeft, 0.0);
	glEnd();  
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(bTop + bThickness, bLeft + bThickness, 0.0);
		glVertex3f(bTop + bThickness, bRight - bThickness, 0.0);
		glVertex3f(bBottom - bThickness, bRight - bThickness, 0.0);
		glVertex3f(bBottom - bThickness, bLeft + bThickness, 0.0);
	glEnd();  
	
	/* draw floaties */
	for(int t = 0; t < 10; t++)
	{
		/*
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex3f(bTop + bThickness, bLeft + bThickness, 0.0);
			glVertex3f(bTop + bThickness, bRight - bThickness, 0.0);
			glVertex3f(bBottom - bThickness, bRight - bThickness, 0.0);
			glVertex3f(bBottom - bThickness, bLeft + bThickness, 0.0);
		glEnd();  
		* */
		glColor3f(1.0, 1.0, 1.0);
		for(int flIndex = 0; flIndex < NUM_OF_FLOATS; flIndex++)
		{
			glBegin(GL_POLYGON);
				glVertex3f(listOfFloats[flIndex].getXCoord(), listOfFloats[flIndex].getYCoord(), 0.0);
				glVertex3f(listOfFloats[flIndex].getXCoord() - .01, listOfFloats[flIndex].getYCoord(), 0.0);
				glVertex3f(listOfFloats[flIndex].getXCoord() - .01, listOfFloats[flIndex].getYCoord() - .01, 0.0);
				glVertex3f(listOfFloats[flIndex].getXCoord(), listOfFloats[flIndex].getYCoord() - .01, 0.0);
			glEnd();  
			listOfFloats[flIndex].move(1.0);
		} /* for each floatie */
		
		/* pause for time */
		clock_t start_time = clock();
		clock_t end_time = 1000 + start_time;
		while(clock() != end_time);
		cout << "time delayed " << t << endl;
		
	}
	
	glFlush();
	
} /* display */
    
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
