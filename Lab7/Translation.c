#include <stdio.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Global variables */
char title[] = "3D Shapes";
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glOrtho(-600,600,-300,300,-500,500);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


int xT=0,yT=0,zT=0;
int val=0;
void displayPyr(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
 
   glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);     // Red
      glVertex3f( 0.0f+xT, 1.0f+yT, 0.0f+zT);
      glColor3f(0.0f+xT, 1.0f+yT, 0.0f+zT);     // Green
      glVertex3f(-1.0f+xT, -1.0f+yT, 1.0f+zT);
      glColor3f(0.0f+xT, 0.0f+yT, 1.0f+zT);     // Blue
      glVertex3f(1.0f+xT, -1.0f+yT, 1.0f+zT);
 
      // Right
       glColor3f(1.0f, 1.0f, 1.0f);     // Red
      glVertex3f(0.0f+xT, 1.0f+yT, 0.0f+zT);
      glColor3f(0.0f+xT, 0.0f+yT, 1.0f+zT);     // Blue
      glVertex3f(1.0f+xT, -1.0f+yT, 1.0f+zT);
      glColor3f(0.0f+xT, 1.0f+yT, 0.0f+zT);     // Green
      glVertex3f(1.0f+xT, -1.0f+yT, -1.0f+zT);
 
      // Back
     glColor3f(1.0f, 1.0f, 1.0f);     // Red
      glVertex3f(0.0f+xT, 1.0f+yT, 0.0f+zT);
      glColor3f(0.0f+xT, 1.0f+yT, 0.0f+zT);     // Green
      glVertex3f(1.0f+xT, -1.0f+yT, -1.0f+zT);
      glColor3f(0.0f+xT, 0.0f+yT, 1.0f+zT);     // Blue
      glVertex3f(-1.0f+xT, -1.0f+yT, -1.0f+zT);
 
      // Left
       glColor3f(1.0f, 1.0f, 1.0f);      // Red
      glVertex3f( 0.0f+xT, 1.0f+yT, 0.0f+zT);
      glColor3f(0.0f+xT,0.0f+yT,1.0f+zT);       // Blue
      glVertex3f(-1.0f+xT,-1.0f+yT,-1.0f+zT);
      glColor3f(0.0f+xT,1.0f+yT,0.0f+zT);       // Green
      glVertex3f(-1.0f+xT,-1.0f+yT, 1.0f+zT);
   glEnd();   // Done drawing the pyramid
 
   glutSwapBuffers();
}



void displayCube() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity(); 
                   // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
 
    glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);     // Green
      glVertex3f( xT+1.0f, 1.0f+yT, -1.0f+zT);
      glVertex3f(xT-1.0f, 1.0f+yT, -1.0f+zT);
      glVertex3f(xT-1.0f, 1.0f+yT,  1.0f+zT);
      glVertex3f( xT+1.0f, 1.0f+yT,  1.0f+zT);
  glEnd();
      // Bottom face (y = -1.0f)
       glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);    // Orange
      glVertex3f( xT+1.0f, -1.0f+yT,  1.0f+zT);
      glVertex3f(xT-1.0f, -1.0f+yT,  1.0f+zT);
      glVertex3f(-1.0f+xT, -1.0f+yT, -1.0f+zT);
      glVertex3f( xT+1.0f, -1.0f+yT, -1.0f+zT);
  glEnd();
      // Front face  (z = 1.0f)
       glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);     // Red
      glVertex3f( 1.0f+xT,  1.0f+yT, 1.0f+zT);
      glVertex3f(-1.0f+xT,  1.0f+yT, 1.0f+zT);
      glVertex3f(-1.0f+xT, -1.0f+yT, 1.0f+zT);
      glVertex3f( 1.0f+xT, -1.0f+yT, 1.0f+zT);
  glEnd();
      // Back face (z = -1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);    // Yellow
      glVertex3f( 1.0f+xT, -1.0f+yT, -1.0f+zT);
      glVertex3f(-1.0f+xT, -1.0f+yT, -1.0f+zT);
      glVertex3f(-1.0f+xT,  1.0f+yT, -1.0f+zT);
      glVertex3f( 1.0f+xT,  1.0f+yT, -1.0f+zT);
  glEnd();
      // Left face (x = -1.0f)
       glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);     // Blue
      glVertex3f(-1.0f+xT,  1.0f+yT,  1.0f+zT);
      glVertex3f(-1.0f+xT,  1.0f+yT, -1.0f+zT);
      glVertex3f(-1.0f+xT, -1.0f+yT, -1.0f+zT);
      glVertex3f(-1.0f+xT, -1.0f+yT,  1.0f+zT);
  glEnd();
      // Right face (x = 1.0f)
       glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 1.0f, 1.0f);     // Magenta
      glVertex3f(1.0f+xT,  1.0f+yT, -1.0f+zT);
      glVertex3f(1.0f+xT,  1.0f+yT,  1.0f+zT);
      glVertex3f(1.0f+xT, -1.0f+yT,  1.0f+zT);
      glVertex3f(1.0f+xT, -1.0f+yT, -1.0f+zT);
   glEnd();  // End of drawing color-cube

glutSwapBuffers();
}

void display()
{
    if(val==0)
    displayCube();
    else
    displayPyr();
}



void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv) {

    printf("Cube(0) or Pyramid(1)- \n");
    scanf("%d",&val);

    printf("translate by - (x,y,z)\n");
    scanf("%d%d%d",&xT,&yT,&zT);



   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1280, 600);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}