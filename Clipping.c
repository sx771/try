//author : sarvesh ameta
//platform : Linux 
//to compile : gcc -lGL -lGLU -lglut file.c -o file
//this is openGL viewPort example
//this is tilling example
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//here i'm drawing the vertical lines
void drawLines()
{
	glBegin(GL_LINES);
		glVertex2i(100,500);
		glVertex2i(700,500);
		glVertex2i(400,500);
		glVertex2i(400,100);
	glEnd();
}



void setViewport(int x,int y,int w,int h)
{
	glViewport(x,y,w,h);
}

void render()
{
	int i,j;
	for(i=0;i<800;i+=200)
	{
		for(j=0;j<600;j+=200)
		{
			setViewport(i,j,200,200);
			drawLines();
			glFlush();
		}
	}
}


/*
void setWorldWindow(int left,int right,int bottom, int top)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}
*/

/*
void mouseMotion(int x,int y)
{
	//setWorldWindow(0,800,0,300);
	//glClearColor(0.0,0.0,0.0,0.0);
	setViewPort(0,0,200,300);
	glFlush();
	glBegin(GL_POINTS);
		glVertex2f(x,600-y);
	glEnd();
	glFlush();
}
*/

void init()
{
	glClearColor(0.0,1.0,0.0,0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0,800.0,0.0,600.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
	
}


int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800,600);
  glutCreateWindow("my view port");
  glutDisplayFunc(render);
  //glutMotionFunc(mouseMotion);
  init();
  glutMainLoop();
}
