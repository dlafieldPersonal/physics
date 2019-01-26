/* testing git */
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
	glutInitWindowSize (500, 500);
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
	
	/* set color to square color */ 
	glColor3f(rs, gs, bs);   
	glBegin(GL_POLYGON);
		glVertex3f(-0.90, -0.20 - supBottom, 0.0);
		glVertex3f(-0.50, -0.20 - supBottom, 0.0);
		glVertex3f(-0.50, 0.20 + supTop, 0.0);
		glVertex3f(-0.90, 0.20 + supTop, 0.0);
	glEnd();  
		
	/* set color to circle color */
	glColor3f(rc, gc, bc);  
	
	GLfloat step = 0.001;  
	glBegin(GL_POINTS);

		/* draw ellipse */
		for(GLfloat x = -0.25; x <= 0.25; x += step)
			for(GLfloat y = -0.25 - supBottom; y <= 0.25 + supTop; y += step)
				if(x * x / 0.0625 + y * y / (0.0625 + 0.5 * supTop + supTop * supTop) < 1)
					glVertex2f(x, y);
	glEnd();
	
	/* set color to triangle color */
	glColor3f(rt, gt, bt); 
	glBegin(GL_POLYGON);
		glVertex3f(0.33, -0.25 - supBottom, 0.0);
		glVertex3f(0.83, -0.25 - supBottom, 0.0);
		glVertex3f(0.83, 0.25 + supTop, 0.0);
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
