#include <GL/glut.h>

int x,y;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);//background colour (r,g,b,a) a-> alpha bending parameter    a==0 means transparent object and a==1 means opaque object
 glMatrixMode(GL_PROJECTION);//projecting the object on the screen 
 gluOrtho2D(0,600,0,550);//if image is out of this bound it wont be displayed(min,max,min,max)
}
void house(void)
{
 glClear(GL_COLOR_BUFFER_BIT);//glclearcolour assigns a colour to be displayed it is not displayed till this function called 
 
 glPointSize(4.0);

glBegin(GL_QUADS);
	glColor3f(0.0,1.0,0.0);//3 means rgb colour standard and f for float values
	glVertex2i(150,20);//i for integer
	glVertex2i(450,20);
	glVertex2i(450,250);
	glVertex2i(150,250);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex2i(80,250);
	glVertex2i(520,250);
	glVertex2i(430,380);
	glVertex2i(170,380);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.8,0.0,0.0);
	glVertex2i(200,20);
	glVertex2i(270,20);
	glVertex2i(270,165);	
	glVertex2i(200,165);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(330,130);
	glVertex2i(400,130);
	glVertex2i(400,200);	
	glVertex2i(330,200);
glEnd();

glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2i(365,130);
	glVertex2i(365,200);
glEnd();

glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2i(330,165);
	glVertex2i(400,165);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.3);
	glVertex2i(380,380);
	glVertex2i(400,380);
	glVertex2i(400,400);
	glVertex2i(380,400);
glEnd();

glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2i(110,20);
glVertex2i(110,10);

glVertex2i(120,10);
glVertex2i(120,20);

glEnd();
 glFlush(); //to free up the memory 
}

void mouse(int button, int state, int mousex, int mousey)
{
x=mousex-0;
y=550-mousey;


glBegin(GL_QUADS);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(200,20);
	glVertex2i(270,20);
	glVertex2i(270,165);	
	glVertex2i(200,165);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.3);
	glVertex2i(380,380);
	glVertex2i(400,380);
	glVertex2i(400,400);
	glVertex2i(380,400);
glEnd();
glFlush();

}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//colour mode and specify buffer mode  for buffer size
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,300);
 glutCreateWindow("House Design");
 
 init();
 glutDisplayFunc(house);//specify what we are making house is user defined function
glutMouseFunc(mouse);
 glutMainLoop();//untill this is called nothing is displayed
 return 0;
}
