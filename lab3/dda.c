#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y11,y2;
 
void display(void)
{
float dy,dx,step,x,y,i,Xin,Yin;
dx=x2-x1;
dy=y2-y11;
 
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;
 
x= x1;
y=y11;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
 
for (i=1 ;i<=step;i++)
{
x= x + Xin;
y= y + Yin;
 
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
 
 
glFlush();
}
 
void init(void)
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) {
printf("Enter  x1 : ");
scanf("%f",&x1);
printf("Enter  y1 : ");
scanf("%f",&y11);
printf("Enter x2 : ");
scanf("%f",&x2);
printf("Enter y2 : ");
scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}