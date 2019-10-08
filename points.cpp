#include <GL/glut.h>

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,200,0,150);
}

void lineSegment(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
 glPointSize(10.0);

 glBegin(GL_POINTS);
 glVertex2i(10,75);
 glVertex2i(75,130);
 glVertex2i(75,50);
 glVertex2i(150,70);
 glVertex2i(150,130);
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

