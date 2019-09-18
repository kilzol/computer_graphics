#include <GL/glut.h>

void init(void)
{
glClearColor(0.0,1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,400);
}

void boat(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(0,0);
	glVertex2i(600,0);
	glVertex2i(600,150);
	glVertex2i(0,150);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.647059,0.164706,0.164706);
	glVertex2i(200,150);
	glVertex2i(400,150);
	glVertex2i(450,200);
	glVertex2i(150,200);
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.5);
	glVertex2i(280,200);
	glVertex2i(320,200);
	glVertex2i(300,240);
glEnd();



glFlush();


}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(600,400);
glutCreateWindow("Boat Program");

init();
glutDisplayFunc(boat);
glutMainLoop();
return 0;

}
