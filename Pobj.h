#ifndef _POBJ
#define _POBJ 1

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Pobj
{
	private:
		GLfloat xCoord;
		GLfloat yCoord;
		GLfloat area;
		double mass;
		GLfloat xVel;
		GLfloat yVel;
	public:
		/* constructer */
		Pobj(GLfloat x, GLfloat y);
		Pobj();
		
		/* destructer */
		~Pobj();

		/* get functions */
		double getMass() const;
		GLfloat getXCoord() const;
		GLfloat getYCoord() const;
		GLfloat getXVel() const;
		GLfloat getYVel() const;
		
		/* set functions */
		void setXCoord(GLfloat x);
		void setYCoord(GLfloat y);
	
};

#endif
