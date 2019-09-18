




#include <GL/glut.h>

float x_pos = 0;
int state =1;

void init(void)
{
glClearColor(0.0,1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,1000,0,700);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    switch(state)
    {
    case 1:
        if(x_pos<700)
        {
            x_pos+=3;
        }
        else
        {
            state = 0;
        }
        break;
    case 0:
        if(x_pos>0)
        {
            x_pos-=3;
        }
        else
        {
            state = 1;
        }
        break;
    }
}

void boat(void)
{
glClear(GL_COLOR_BUFFER_BIT);
//water
glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,150);
	glVertex2i(0,150);
glEnd();
//boat
glBegin(GL_QUADS);
	glColor3f(0.647059,0.164706,0.164706);
	glVertex2i(x_pos+50,150);
	glVertex2i(x_pos+250,150);
	glVertex2i(x_pos+300,200);
	glVertex2i(x_pos,200);
glEnd();
//flagbase
glBegin(GL_TRIANGLES);
	glColor3f(0.5,1.0,0.5);
	glVertex2i(x_pos+130,200);
	glVertex2i(x_pos+170,200);
	glVertex2i(x_pos+150,240);
glEnd();

/*
glBegin(GL_LINES);
	glColor3f(0.647059,0.164706,0.164706);
	glVertex2i(x_pos+150,239);
	glVertex2i(x_pos+150,290);
glEnd();
//flag
glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x_pos+150,290);
	glVertex2i(x_pos+150,270);
	glVertex2i(x_pos+170,280);
glEnd();
*/
/*
int i,j;
for(i=20;i<1000;i+=40)
{	for(j=130;j>0;j-=60)
	{
	glBegin(GL_LINES);
		glColor3f(0,0,1.0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}
}

for(i=0;i<980;i+=40)
{	for(j=100;j>0;j-=60)
	{
	glBegin(GL_LINES);
		glColor3f(0,0,1.0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}
}*/
glutSwapBuffers();
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(600,400);
glutCreateWindow("Boat Program");

init();
glutDisplayFunc(boat);
glutTimerFunc(0,timer,0);
glutMainLoop();
return 0;
}
