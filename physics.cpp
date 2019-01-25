#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

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

/***************************************************/

/* prototypes */
void adjustColor(GLfloat &r, GLfloat &g, GLfloat &b);
void display();
void keyboard (unsigned char key, int x, int y);
void reshape(int w, int h);

/***************************************************/

int main(int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (000, 000);
	glutCreateWindow ("Change colors by pressing c, s, and t.");
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutMainLoop();

	cout << "Done" << endl;
	return 0;
} /* main */

/***************************************************/

void keyboard (unsigned char key, int x, int y)
{
	//cout << "key: [" << key << "]" << endl;
	switch (key) 
	{
		case 't':
			d = 't';
			adjustColor(rt, gt, bt);
			glutPostRedisplay ();
			break;
		case 'c':
			d = 'c';
			adjustColor(rc, gc, bc);
			glutPostRedisplay ();
			break;
		case 's':
			d = 's';
			adjustColor(rs, gs, bs);
			glutPostRedisplay();
			break;
		case '+': 
			d = '+';
			/* grow */
			if(supTop < 0.25)
			{
				supTop += 0.05;
				supBottom += 0.05;
			}
			glutPostRedisplay();
			break;
		case '-':
			d = '-';
			/* shrink */
			if(supTop > -0.15)
			{
				supTop -= 0.05;
				supBottom -= 0.05;
			}
			glutPostRedisplay();
			break;
		default:
			break;
	} /* switch */
	
} /* keyboard */

/***************************************************/

void display()
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* set color white for lines */ 
	glColor3f(1.0, 1.0, 1.0);   
	glBegin(GL_LINES);
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, -1.0, 0.0);
		glVertex3f(-1.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(-1.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
	glEnd();  
	GLfloat step = 0.1;
	/* set color white for lines */
	glColor3f(1.0, 1.0, 1.0);   
	glBegin(GL_LINES);
		
		for(GLfloat i = 0.0; i <= 1.0; i += step)
		{
			glVertex3f(i, i, 0.0);
			glVertex3f(i - 1.0, 1.0 - i, 0.0);
			cout << "(" << i << ", " << i << ") (" << i - 1.0 << ", " << 1.0 - i << ")" << endl;
		}
	glEnd();  
	
	if(false)
	{
		/* set color white for lines */
		glColor3f(1.0, 1.0, 1.0);   
		glBegin(GL_LINES);
			
			for(GLfloat i = 0.0; i <= 1.01; i += step)
			{
				glVertex3f(i, 0.0, 0.0);
				glVertex3f(0.0, 1.0 - i, 0.0);
			}
		glEnd();  
	}

	/* set color yellow for step points */
	GLfloat offset = 0.01;
	glColor3f(1.0, 1.0, 0.0);   
	glBegin(GL_POINTS);
		/* x axis */
		for(GLfloat y = -1.0; y <= 1.0; y += 0.1)
			glVertex3f(offset, y, 0.0);
			
		/* y axis */
		for(GLfloat x = -1.0; x <= 1.0; x += 0.1)
			glVertex3f(x, offset, 0.0);
	glEnd();  
	
	glFlush();
} /* display */
    
/***************************************************/

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
} /* reshape */

/***************************************************/

void adjustColor(GLfloat &r, GLfloat &g, GLfloat &b)
{
	/**
	 * flip blue
	 * if blue flips to 0, flip green
	 * if green flips to 0, flip red
	 * */
	 
	if(b == 0.0)
		b = 1.0;
	else
	{
		b = 0.0;
		if(g == 0.0)
			g = 1.0;
		else
		{
			g = 0.0;
			r = 1.0 - r;
		}
	}
} /* adjustColor */

/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
