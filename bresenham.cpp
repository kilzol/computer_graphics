#include<GL/glut.h>
#include<iostream>


GLint x1=0,y1=0,x2=0,y2=0;
GLint count = 0;
GLint cas = 0;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}

void plotPoint(GLfloat x,GLfloat y)
{
 glPointSize(2);
 glBegin(GL_POINTS);
 glVertex2f(x,y);
 glEnd();
}
void setPixel(GLint x, GLint y){

switch(cas){
	case 0: //case of gentle positive
	plotPoint(x,y);
	printf("%d %d \n", x,y);
	printf("case 0\n");
	break;
	case 1: //case of gentle negative
	plotPoint(x,y);
	printf("%d %d \n", x,-y);
	printf("case 1\n");
	break;
	case 2: //case of steep positive
	plotPoint(x,y);
	printf("%d %d \n", -y,-x);
	printf("case 2\n");
	break;
	case 3: //case of steep negative
	plotPoint(x,y);
	printf("%d %d \n", y,-x);
	printf("case 3\n");
	break;

	

}
}

void bresnLine(GLint x1,GLint y1,GLint x2,GLint y2)
{
 //here we draw the axes
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
 glEnd();

 //ploting the origin
 glColor3f(0.1,1.0,0.1);
 glPointSize(6);
 glBegin(GL_POINTS);
  glVertex2i(0,0);
 glEnd();
 glColor3f(1.0,0.0,0.0);

 
 GLint dx = x2-x1, dy = y2-y1, dt=2*dy-2*dx , ds=2*dy, d=2*dy-dx, tmp;
  float x=x1, y=y1, slope=dy/dx;
if(x1 > x2)
{
tmp=x1;
x1=x2;
x2=tmp;         //gentle positive
tmp=y1;
y1=y2;
y2=tmp;
}
if((abs(dx)>abs(dy)) && slope<0) //gentle negative
{ 
	cas=1;
	y=y1, y2=-y2;
}
if((abs(dx)<abs(dy)) && slope>0) // steep +ve
{
cas = 2;
tmp=x1;
x1=y1;
y1=tmp;
x2=y2;
y2=tmp;
}  
if((abs(dx)<abs(dy)) && slope<0) // steep -ve
{
cas = 3;
tmp=x1;
x1=y1;
y1=tmp;
x2=y2;
y2=tmp;
}  


while(x<=x2){
setPixel(x, y);

 
x++;

if(d<0){
	d = d + ds;
}
else {
	y++;
	d= d + dt;
}
 glFlush();
}
 
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 bresnLine(-70,-10,-50,90); //m > 1 steep,positive
 bresnLine(-10,-70,90,-50); //m < 1 gentle positive
 bresnLine(-10,70,90,50);   //m > -1 gentle negative
 bresnLine(70,-10,50,90);   //m < -1 steep negative
}

//dont use winReshape
/*void winReshape(GLint nw, GLint nh)
{
 glViewport(0,0,nw,nh);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,GLdouble(nw),0.0,GLdouble(nh));
 ww = nw;
 wh = nh;
}*/

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,400);
 glutCreateWindow("Line Drawing: Bresnham");
 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();

 return 0;
}
