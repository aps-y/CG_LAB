 #include <GL/glut.h>
 #include<stdio.h>
/* initial triangle */

GLfloat v[4][2]={{-1.0, -1}, 
     {1.0, -1}, {1.0, 1.0}, {-1.0,1.0}};

int n; /* number of recursive steps */


 void triangle( GLfloat *a, GLfloat *b, GLfloat *c)

/* display one triangle */
     {
       glVertex2fv(a); 
       glVertex2fv(b); 
       glVertex2fv(c);
     }


 void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
     /* triangle subdivision using vertex numbers */
     GLfloat v00[2], v01[2], v02[2], v03[2];
     GLfloat v10[2], v11[2], v12[2], v13[2];
     int j;
     if(m>0)
     {
       for(j=0; j<2; j++) v00[j]=(a[j]+b[j])/3;
       for(j=0; j<2; j++) v01[j]=(b[j]+c[j])/3;
       for(j=0; j<2; j++) v02[j]=(c[j]+d[j])/3;
       for(j=0; j<2; j++) v03[j]=(d[j]+a[j])/3;

       for(j=0; j<2; j++) v10[j]=2*(a[j]+b[j])/3;
       for(j=0; j<2; j++) v11[j]=2*(b[j]+c[j])/3;
       for(j=0; j<2; j++) v12[j]=2*(c[j]+d[j])/3;
       for(j=0; j<2; j++) v13[j]=2*(d[j]+a[j])/3;

       float va[2], vb[2],vc[2],vd[2];
       va[0]=v00[0];
       va[1]=v03[1];

       vb[0]=v10[0];
       vb[1]=v01[1];

       vc[0]=v00[0];
       vc[1]=v03[1];

       divide_triangle(a, v00,, v1, m-1);
       divide_triangle(c, v1, v2, m-1);
       divide_triangle(b, v2, v0, m-1);
     }
     else
       triangle(a,b,c);
     /* draw triangle at end of recursion */
}


 void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_TRIANGLES);
     divide_triangle(v[0], v[1], v[2],v[3], n);
     glEnd();
     glFlush();
}

void myinit()
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
     glMatrixMode(GL_MODELVIEW);
     glClearColor (1.0, 1.0, 1.0,1.0);
     glColor3f(0.0,0.0,0.0);
}


 int main(int argc, char **argv)
{
     n=4;
     printf("enter number of recursive steps- ");
     scanf("%d",&n);
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutCreateWindow("Serpienski's Triangle");
     glutDisplayFunc(display);
     myinit();
     glutMainLoop();
}

