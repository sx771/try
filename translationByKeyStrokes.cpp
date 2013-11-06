#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace::std;

void drawImage()
{
       glBegin(GL_LINES);
                glVertex2i(-300,0);
                glVertex2i(300,0);
                glVertex2i(0,300);
                glVertex2i(0,-300);
        glEnd();
        glLineWidth(2);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_LINES);
                glVertex2i(-70,-10);
                glVertex2i(70,-10);
                glVertex2i(-70,-10);
                glVertex2i(-70,60);
                glVertex2i(70,-10);
                glVertex2i(70,60);
                glVertex2i(70,60);
                glVertex2i(0,80);
                glVertex2i(-70,60);
                glVertex2i(0,80);
        glEnd();
}

void render()
{
       // glTranslatef(20,0,0);
        //drawImage();
        glFlush();
}

void keyStroke(unsigned char key,int x,int y)
{
        int x_cen=0,y_cen=0;
        switch(key)
        {
                case 'w' :
                        glClear(GL_COLOR_BUFFER_BIT);
                        y_cen+=5;
                        glTranslatef(x_cen,y_cen,0);
                        drawImage();
                        glFlush();
                        cout<<"w pressed\n";
                        break;
                case 's' :
                        glClear(GL_COLOR_BUFFER_BIT);
                        y_cen-=5;
                        glTranslatef(x_cen,y_cen,0);
                        drawImage();
                        glFlush();
                        cout<<"s pressed\n";
                        break;
                case 'a' :
                        glClear(GL_COLOR_BUFFER_BIT);
                        x_cen-=5;
                        glTranslatef(x_cen,y_cen,0);
                        drawImage();
                        glFlush();
                        cout<<"a pressed\n";
                        break;
                case 'd' :
                        glClear(GL_COLOR_BUFFER_BIT);
                        x_cen+=5;
                        glTranslatef(x_cen,y_cen,0);
                        drawImage();
                        glFlush();
                        cout<<"d pressed\n";
                        break;
                default :
                        break;
        }
}

void init()
{
        glClearColor(0.3,0.6,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(0.6,0.3,0.0);
        glPointSize(5);
        glLineWidth(3);
        glMatrixMode(GL_MODELVIEW);
        gluOrtho2D(-300.0,300.0,-300.0,300.0);
}

int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(600,600);
        glutCreateWindow("transformation");
        glutDisplayFunc(render);
       glutKeyboardFunc(keyStroke);
        init();
        glutMainLoop();
}
