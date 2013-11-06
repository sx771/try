#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace::std;

int ra=0,rb=0;
void drawCube(void);

void init(void)
{
	cout<<"init initialization...\n";
	glClearColor(0.2,0.7,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void render(void)
{
	cout<<"rendering the cube...\n";
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	gluOrtho2D(-300,300,-300,300);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(300,0);
		glVertex2f(300,600);
		glVertex2f(0,300);
		glVertex2f(600,300);
	glEnd();
	drawCube();
	glFlush();

}

void drawCube(void)
{
	//glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();
	glTranslatef(0.0,0.0,-10.0);
	glRotatef(ra,0.5,0.5,0.0);
	glRotatef(rb,0.0,0.0,1.0);
	glBegin(GL_QUADS);
		//front
		glColor3f(1.0,0.0,0.0);
		glVertex3f(1,1,1);
		glVertex3f(-1,1,1);
		glVertex3f(-1,-1,1);
		glVertex3f(1,-1,1);

		//rare
		glColor3f(0.3,0.0,0.0);
		glVertex3f(1,1,-1);
		glVertex3f(-1,1,-1);
		glVertex3f(-1,-1,-1);
		glVertex3f(1,-1,-1);

		//upper
		glColor3f(0.0,0.0,1.0);
		glVertex3f(1,1,1);
		glVertex3f(1,1,-1);
		glVertex3f(-1,1,-1);
		glVertex3f(-1,1,1);

		//bottom
		glColor3f(1.0,1.0,0.0);
		glVertex3f(1,-1,1);
		glVertex3f(1,-1,-1);
		glVertex3f(-1,-1,-1);
		glVertex3f(-1,-1,1);
		
		//left
		glColor3f(1.0,0.0,1.0);
		glVertex3f(-1,1,1);
		glVertex3f(-1,1,-1);
		glVertex3f(-1,-1,-1);
		glVertex3f(-1,-1,1);
		
		//right
		glColor3f(1.0,1.0,1.0);
		glVertex3f(1,1,1);
		glVertex3f(1,-1,1);
		glVertex3f(1,-1,-1);
		glVertex3f(1,1,-1);

		glEnd();
		glFlush();
}

void reshape(int w, int h)
{
	cout<<"reshaping...\n";
	if(w==0 || h==0)
		return ;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0,(GLdouble)w/(GLdouble)h,0.5,20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);
}

/*
void animation()
{
	glClear(GL_COLOR_BUFFER_BIT);
	ra+=1;
	rb+=1;
	//sleep(100);
	drawCube();
	glFlush();
	
}
*/
void keyStroke(unsigned char key,int x,int y)
{
	switch(key)
	{
		case '4' :
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glClear(GL_COLOR_BUFFER_BIT);
			ra++;
	//		glRotatef(ra,0.0,0.0,1.0);
	//		glRotatef(rb,0.0,1.0,0.0);
			drawCube();
			glPointSize(7);
			glColor3f(0.0,0.0,0.0);
//			glBegin(GL_POINTS);
//				glVertex3f(0.0,0.0,0.0);
//			glEnd();
			glFlush();
			break;
		case '6' :
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glClear(GL_COLOR_BUFFER_BIT);
			rb++;
//			glRotatef(ra,0.0,0.0,0.1);
//			glRotatef(rb,1.0,1.0,0.0);
			drawCube();
			glFlush();
			break;
		default :
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("3D quad rotating");

	init();
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyStroke);
//	glutIdleFunc(animation);
	glutMainLoop();

	return 0;
}
