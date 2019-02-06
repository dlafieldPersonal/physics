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
		Pobj(GLfloat x, GLfloat y, GLfloat dx, GLfloat dy);
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
	
		/* other prototypes */
		void move(float timeElapse);
};

#endif
