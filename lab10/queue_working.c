#include<stdio.h>
#include<string.h>
#include<GL/glut.h>


int n=0, l=0;
int arr[10];
void DisplayString(char string[], float x, float y)
{
    
    int w;
    w = glutBitmapLength(GLUT_BITMAP_9_BY_15, string);
    
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(x-(float)w/2, y);
    for (int i = 0; string[i] != '\0'; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
     glFlush();
}

void CreateStack()
{
    int k=-200;

    for(int i=0;i<10;i++)
    {
        glBegin(GL_LINE_STRIP);
            glVertex2d(50,k);
            glVertex2d(50,k+40);
            glVertex2d(-50,k+40);
            glVertex2d(-50,k);
        glEnd();
        k+=40;
    }
    glFlush();
}

void mydisplay()
{
     glClear(GL_COLOR_BUFFER_BIT);
     unsigned char string[] = "Press Key 'I' to insert elements into queue";
     unsigned char str[] = "Press Key 'D' to pop elements from queue";
     DisplayString("Queue Demo",0,340);
      DisplayString(string, 0, 320);
      DisplayString(str, 0, 300);

     glBegin(GL_LINES);
        glVertex2d(-50,-200);
        glVertex2d(50,-200);
        glEnd();
    
    CreateStack();
     
}


void myinit()
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-350.0, 350.0, -350.0, 350.0);
     glMatrixMode(GL_MODELVIEW);
     glClearColor (0.0, 0.0, 0.0,0.0);
     glColor3f(1.0,1.0,1.0);
}
void drawTriangle(int y)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(-60,y);
        glVertex2f(-80,y+20);
        glVertex2f(-80,y-20);
    glEnd();
    glFlush();
}

void push()
{
    mydisplay();
    int i=0;
     char str[3];
    int y = -180;
    if(n==10){
    DisplayString("Queue Overflow",0,-220);
     for(;i<n;i++)
    {
        if(i>=l) {
        snprintf(str,3,"%d",arr[i]);
       // printf("%s\n",str);
        DisplayString(str,0,y);
    }
        y+=40;
    }
    drawTriangle(y-40);
    return;
    }
    int a = rand()%100;
    arr[n++]=a;
   
    for(;i<n;i++)
    {
        if(i>=l) {
        snprintf(str,3,"%d",arr[i]);
       // printf("%s\n",str);
        DisplayString(str,0,y);
    }
        y+=40;
    }
    drawTriangle(y-40);
   
}
void pop()
{
     mydisplay();
     if(l==n)
     {
         DisplayString("Queue Empty",0,-220);
         return;
     }
    char str[3];
    int y=-180;
    l++;
     for(int i=0;i<n;i++)
    {   if(i>=l) {
        snprintf(str,3,"%d",arr[i]);
        //printf("%s\n",str);
        DisplayString(str,0,y);
    }
        y+=40;
    }
    drawTriangle(y-40);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'i' | 'I': push();
        break;

    case 'd' | 'D': pop();
        break;
    case 'q' | 'Q': exit(0);
    }
}


 int main(int argc, char **argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(700, 700);
     glutCreateWindow("Stack Demo");
     glutKeyboardFunc(keyboard);
     glutDisplayFunc(mydisplay);
     myinit();
     glutMainLoop();
}
