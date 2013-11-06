#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void render()
{
	glClearColor(0.1,0.6,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0,600.0,0.0,400.0);
	glPointSize(5);
	glLoadIdentity();
//	glutSwapBuffers();
	glFlush();
}
void mouseFunction(int x,int y)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		glVertex2f(x,400-y);
	glEnd();
//	glutSwapBuffers();
//	glutSwapBuffers();
	glFlush();
}

void init()
{
	glClearColor(1.0,1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,600.0,0.0,400.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
}

int main(int argc ,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,400);
	glutCreateWindow("hello This is my glut program");
	glutDisplayFunc(render);
	glutMotionFunc(mouseFunction);
	init();
	glutMainLoop();
}
