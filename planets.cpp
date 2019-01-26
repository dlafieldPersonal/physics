/**
 * Walter Douglas Lafield
 * CSC 7443
 * Homework 1
 * Question 2
 * */

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static GLfloat 
	year = 0.0, day = 0.0, mYear = 0.0, 
	lunaMonth = 0.0, phobosMonth = 0.0, deimosMonth = 0.0, 
	mDay = 0.0;

/**************************************************************/

/* prototypes */
void display (void);
void init(void);
void keyboard (unsigned char key, int x, int y);
void reshape(int w, int h);
void yearDisplay (void);

/**************************************************************/

int main(int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Animation: solar system");
    init ();
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutMainLoop();
    
    return 0;
    
} /* main */

/**************************************************************/

void init(void)
{
    GLfloat mat_specular[] = {1.0,1.0,1.0,0.15};
    GLfloat mat_shininess[] = {100.0};
    GLfloat light0_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light0_position[] = {1.0,1.0,1.0,0.0};
    
    glClearColor (0.1, 0.1, 0.2, 0.0);
    glShadeModel (GL_SMOOTH);    
    
    glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv (GL_LIGHT0, GL_POSITION, light0_position);
    
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);
    
} /* init */
    
/**************************************************************/

void display (void)
{ 
    GLfloat mat_solid[] = 
    {
		0.9, 
		0.75, 
		0.0, 
		1.0
	};
	
    GLfloat mat_zero[] = 
    {
		0.0,
		0.0,
		0.0,
		1.0
	};
	
	GLfloat mat_white[] = 
    {
		1.0,
		1.0,
		1.0,
		1.0
	};
	
    GLfloat mat_transparent[] = 
    {
		0.0,
		0.8,
		0.8,
		0.6
	};
	
    GLfloat mat_emission[] = 
    {
		0.9,
		0.1,
		0.0,
		0.8
	};

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_DEPTH_TEST);
    
    glColor3f (1.0, 1.0, 1.0);
    glPushMatrix ();
    
		/* sun */
        glRotatef (year, 0.0, 1.0, 0.0);   
        /*     
        glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_transparent);        
        * */
        glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
        //glutSolidSphere (1.0, 80, 64);
        glutSolidSphere (0.3, 80, 64);
        
        
        /* mars */
        glPushMatrix();
			glTranslatef (2.0, 0.0, 0.0);
			glRotatef (mYear, 0.0, 1.0, 0.0);
			/*
			glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
			* */
			glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_transparent);     
			glEnable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			//glutSolidSphere (0.2, 160, 160);
			glutSolidSphere (0.1, 100, 100);
			glPushMatrix();
				glTranslatef (.25, 0.0, 0.0);
				glRotatef (phobosMonth, 0.0, 1.0, 0.0);
				/*
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
				* */
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_solid);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);     
				glEnable(GL_BLEND);
				glDepthMask(GL_TRUE);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glutSolidSphere (0.03, 5, 5);
				//glutSolidSphere (0.2, 200, 200);
			glPopMatrix();
			glPushMatrix();
				glTranslatef (0.5, 0.0, 0.0);
				glRotatef (deimosMonth, 0.0, 1.0, 0.0);
				/*
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
				* */
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_solid);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);     
				glEnable(GL_BLEND);
				glEnable(GL_DEPTH_TEST);
				glDepthMask(GL_TRUE);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glutSolidSphere (0.04, 6, 6);
				//glutSolidSphere (0.2, 200, 200);
			glPopMatrix();
        glPopMatrix();
        
        /* earth */
        glPushMatrix();
			
			glTranslatef (1.0, 0.0, 0.0);
			glRotatef (day, 0.0, 1.0, 0.0);
			/*
			glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
			* */
			glMaterialfv(GL_FRONT,GL_EMISSION,mat_transparent);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_transparent);     
			glEnable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			glutSolidSphere (0.2, 160, 160);
			//glutSolidSphere (0.2, 200, 200);
			
			/* moon */
			glPushMatrix();
				glTranslatef (0.3, 0.0, 0.0);
				glRotatef (lunaMonth, 0.0, 1.0, 0.0);
				/*
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
				* */
				glMaterialfv(GL_FRONT,GL_EMISSION,mat_white);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);     
				glEnable(GL_BLEND);
				glEnable(GL_DEPTH_TEST);
				glDepthMask(GL_TRUE);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glutSolidSphere (0.05, 5, 10);
				//glutSolidSphere (0.2, 200, 200);
			glPopMatrix();
			
        glPopMatrix();
        
        /*
        glRotatef (mYear, 0.0, 1.0, 0.0);
        glutSolidSphere (0.1, 200, 200);
        */
        
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
        
        //cout << year << "\t" << mYear << endl;

    glPopMatrix ();
    glutSwapBuffers ();
    
} /* display */

/**************************************************************/

void yearDisplay (void)
{
    year = year + 0.2; 
    if (year > 360.0)
        year = year - 360.0;
        
    
    mYear = mYear + 0.1;
    if(mYear > 360.0)
		mYear -= 360.0;
    
    day = day + 0.5; 
    if (day > 360.0)
        day = day - 360.0;
        
    mDay = mDay + 0.5; 
    if (mDay > 360.0)
        mDay = mDay - 360.0;
        
    lunaMonth += (360.0 / 13.0) / 0.2;
    if(lunaMonth > 360.0)
		lunaMonth -= 360.0;
	phobosMonth += 0.6;
	deimosMonth += 1.2;
	if(phobosMonth > 360.0)
		phobosMonth -= 360.0;
	if(deimosMonth > 360.0)
		deimosMonth -= 360.0;
    glutPostRedisplay ();
    
} /* yearDisplay */

/**************************************************************/

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, -0.2, 1.0, 0.0);
    
} /* reshape */

/**************************************************************/

void keyboard (unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 'y':
            glutIdleFunc (yearDisplay);
            break;
        case 'n':
            glutIdleFunc (NULL);
            break;
        default:
            break;
    } /* switch key */
    
} /* keyboard */

/**************************************************************/

