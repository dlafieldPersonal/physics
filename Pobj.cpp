#include "Pobj.h"

using namespace std;

/***************************************************/
		
Pobj::Pobj(GLfloat x, GLfloat y)
{ 
	xCoord = x;
	yCoord = y;
	mass = 1.0;
	area = 4.0;
	xVel = yVel = 0.0;
} /* constructer */

/***************************************************/

Pobj::Pobj()
{ 
	xCoord = 0.5;
	yCoord = 0.5;
	mass = 1.0;
	area = 4.0;
	xVel = yVel = 0.0;
} /* constructer */

/***************************************************/

Pobj::~Pobj()
{ }

/***************************************************/

double Pobj::getMass() const { return mass; }
GLfloat Pobj::getXCoord() const { return xCoord; }
GLfloat Pobj::getYCoord() const { return yCoord; }
GLfloat Pobj::getXVel() const { return xVel; }
GLfloat Pobj::getYVel() const { return yVel; }
void Pobj::setXCoord(GLfloat x) { xCoord = x; }
void Pobj::setYCoord(GLfloat x) { yCoord = x; }

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
