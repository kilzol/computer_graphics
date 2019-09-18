#include<GL/glut.h>

void init(void)
{
glClearColor(0.0,1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,200,0,150);
}

void lineSegment(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,1.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(10,10);
glVertex2i(50,10);

glVertex2i(50,100);
glVertex2i(10,100);


glEnd();


glColor3f(1.0,0.0,0.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(50,10);
glVertex2i(50,100);
glVertex2i(100,100);
glVertex2i(100,10);
glEnd();

glColor3f(1.0,1.0,0.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(10,100);
glVertex2i(25,125);
glVertex2i(50,100);
glEnd();


glColor3f(1.0,0.5,1.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(50,10);
glVertex2i(50,100);
glVertex2i(100,100);
glVertex2i(100,10);
glEnd();


glColor3f(1.0,0.5,0.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(25,125);
glVertex2i(50,100);
glVertex2i(100,100);
glVertex2i(75,125);
glEnd();


glColor3f(1.0,1.0,1.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(22,10);
glVertex2i(29,10);
glVertex2i(29,45);
glVertex2i(22,45);
glEnd();


glColor3f(1.0,1.0,1.0);
glPointSize(4.0);
glBegin(GL_POLYGON);
glVertex2i(65,50);
glVertex2i(85,50);
glVertex2i(85,65);
glVertex2i(65,65);
glEnd();

glFlush();
}

int main(int argc, char** argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(400,300);
glutCreateWindow("Sample Programs");

init();
glutDisplayFunc(lineSegment);
glutMainLoop();
return 0;
}



