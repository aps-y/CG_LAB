#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
static int window;
static int menu_id;
static int value = 0;
static int rot = 0;
int jj=0;

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }
  else if(num==4)
  {
      rot+=30;
      jj=1;
    }
    else if(num==5)
    {
        rot =0;
        value =0;
        jj=0;
    }
    else{
    value = num;
  }
  glutPostRedisplay();
  
} 

void createMenu(void){
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Solid", 2);
    glutAddMenuEntry("Wired", 3);
    glutCreateMenu(menu);
    glutAddSubMenu("Make", menu_id);
    glutAddMenuEntry("Quit", 0);
    glutAddMenuEntry("Rotate", 4);
    glutAddMenuEntry("Reset", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 


void display () {

    /* clear window */ 
    glClear(GL_COLOR_BUFFER_BIT);
    if(jj)
    {glRotatef(rot,0,0,1.0);jj=0; rot=0;}
    /* draw scene */
    if(value==2)
    {
        glColor3f(1.0,0,0);
    glutSolidTeapot(.5);
    }
    else if(value==3)
    {
        glColor3f(0,1.0,0);
    glutWireTeapot(.5);
    }
    /* flush drawing routines to the window */
    glFlush();

}

int main ( int argc, char * argv[] ) {

    
    glutInit(&argc,argv);

   
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    window = glutCreateWindow("Menu");
    createMenu();
    glutDisplayFunc(display);

    /* tell GLUT to wait for events */
    glutMainLoop();
}