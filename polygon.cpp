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
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2i(10,55);
 glVertex2i(85,55);
 glVertex2i(95,85);
 glVertex2i(75,85);
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

