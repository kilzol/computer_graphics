#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
GLint ww=400, wh=400;
GLint count = 0, x1=0, y11=0, x2=0, y2=0;
void init(void)
{ 
glClearColor(1.0,0.0,0.0,0.0); 
gluOrtho2D(0.0,400.0,0.0,400.0);
}
void display(void)
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glPointSize(5.0); 
glFlush(); 
}
void plotpoint(GLint x,GLint y)
{
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_POINTS);  
glVertex2i(x,y); 
glEnd();
}
void circle()
{
 GLint q = (y2-y11)*(y2-y11);
 GLint s = (x2-x1)*(x2-x1);
 GLint r = sqrt(q + s);
 printf("r = %d\n",r);
 GLint x_centre=x1, y_centre=y11, x = r, y = 0;
 plotpoint(x_centre,y_centre);
 plotpoint(x + x_centre, y + y_centre);
   GLint P = 1 - r;
     while (x > y)
     {
          y++;
         if (P <= 0)
             P = P + 2*y + 1; 
        else
        { 
                x--;
                 P = P + 2*y - 2*x + 1;
         } 
        plotpoint(x + x_centre, y + y_centre); 
        plotpoint(-x + x_centre, y + y_centre); 
        plotpoint(x + x_centre, -y + y_centre); 
        plotpoint(-x + x_centre, -y + y_centre); 
        plotpoint(y + x_centre, x + y_centre); 
        plotpoint(-y + x_centre, x + y_centre); 
        plotpoint(y + x_centre, -x + y_centre);
        plotpoint(-y + x_centre, -x + y_centre); 
    }   
}
void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
 {
  if(!count)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   x1=xMouse;
   y11=wh-yMouse;
   count = 1;
   plotpoint(x1,y11);
   printf("First point %d, %d entered.\n",x1,y11);
  }
  else
  {
   x2=xMouse;
   y2=wh-yMouse;
   printf("Second point %d, %d entered.\n",x2,y2);
   plotpoint(x2,y2);
   circle();
   count=0;
   printf("Points reset.\n");
  }
 }
 glFlush();
 //printf("%d %d\n",xMouse,yMouse);
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 
 glutInitWindowSize(ww,wh);
 glutCreateWindow("mouse demo1");

 init();
 glutDisplayFunc(display);
 glutMouseFunc(mousePtPlot);

 glutMainLoop();
 return 0;
}
