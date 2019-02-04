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
		GLfloat radius;
	public:
		/* constructer */
		Pobj(GLfloat x, GLfloat y);
		Pobj();
		
		/* destructer */
		~Pobj();

		/* get functions */
		GLfloat getXCoord() const;
		GLfloat getYCoord() const;
		
		/* set functions */
		void setXCoord(GLfloat x);
		void setYCoord(GLfloat y);
	
};

#endif
