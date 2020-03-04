	#include<stdio.h>
	#include<GL/glut.h>
	#define LINE 0
	#define POLY 1
	#define CIRCLE 2

	int trans[3][3] = {
	    {1, 0, 0},
	    {0, 1, 0},
	    {0, 0, 1}
	};

	int flag= 0;
	int x1, y11, x2, y2, xa, ya, r, points[100][2],n, tx, ty;
	int result[3][1]={0,0,0};


	// glutPostRedisplay();


	void drawCircle (int xa, int ya, int r)
	{
	int p = 3-2*r;
	int x=0,y=r;
	 
	//glClear (GL_COLOR_BUFFER_BIT);
	 
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_POINTS);

		while(x <= y){
			//draw all points
			glVertex2i(x+xa,y+ya);
			glVertex2i(x+xa,-1*y+ya);
			glVertex2i(-1*x+xa,y+ya);
			glVertex2i(-1*x+xa,-1*y+ya);

			glVertex2i(y+xa,x+ya);
			glVertex2i(y+xa,-1*x+ya);
			glVertex2i(-1*y+xa,x+ya);
			glVertex2i(-1*y+xa,-1*x+ya);
			x++;
			if( p < 0){
				p = p + 4*x + 6;
			}
			else{
				p = p + 4*(x-y) + 10;
				y--;
			}
		}

	glEnd();
	glFlush();
	}

	void translate(int x1, int x2, int tx, int ty){

		result[1][0] = x1 + tx;
		result[2][0] = x2 + ty;
		// trans[0][2] = tx;
		// trans[1][2] = ty;

		// int point[3][1]={x1,x2,1};
		
		// int c, d, k, tot= 0;

		// for (c = 0; c < 3; c++) {
	 //      for (d = 0; d < 1; d++) {
	 //        for (k = 0; k < 3; k++) {
	 //          tot = tot + trans[c][k] * point[k][d];
	 //        }
	 //        result[c][d] = tot;
	 //        tot = 0;
	 //      }
	 //    }
	}

	void resetResult(){
		result[0][1]  = 0;
		result[0][2]  = 0;
		result[0][3]  = 0;
	}


	void display(){
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(1.0, 1.0, 1.0);

		if(flag == LINE){
			glBegin(GL_LINES);
				glVertex2i(x1, y11);
				glVertex2i(x2, y2);
			glEnd();

			
			
			

			glBegin(GL_LINES);
				translate(x1, y11, tx ,ty);
				glVertex2i(result[1][0], result[2][0]);
				resetResult();

				translate(x2, y2, tx ,ty);
				glVertex2i(result[1][0], result[2][0]);
				resetResult();
			glEnd();

		}

		if(flag == POLY){
			glBegin(GL_POLYGON);
				for(int i=0; i <n; i++ ){
					glVertex2i(points[i][0], points[i][1]);
				}
				
			glEnd();


			glBegin(GL_POLYGON);

				for(int i=0; i <n; i++ ){
					translate(points[i][0], points[i][1], tx ,ty);
					glVertex2i(result[1][0], result[2][0]);
					resetResult();
					
				}
			glEnd();

		}

		if(flag == CIRCLE){

			drawCircle(xa, ya, r);
			translate(xa, ya, tx ,ty);
			drawCircle(result[1][0], result[2][0], r);
			resetResult();


		}

		glFlush();
	}

	void init()
	{
		glClearColor(0, 0, 0, 0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 500, 0, 500, -1, 1);
	}
	void main(int argc, char** argv)
	{
		int op = 0;

		
		// do{

			printf("Translation: \n");
			printf("1. line\n");
			printf("2. polygon\n");
			printf("3. circle\n");
			printf("Enter option: ");
			scanf("%d", &op);

			switch(op){
				case 1: printf("Enter the endpoints of the line: ");
						scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
						flag = LINE;
						break;
				case 2: printf("No of points: ");
						scanf("%d", &n);

						printf("Enter the points: ");
						for( int i =0; i < n; i++){
							for( int j =0; j < 2; j++){
								scanf("%d", &points[i][j]);	
							}
						}
						flag = POLY;
						break;
				case 3: printf("Enter the center, radius: ");
						scanf("%d %d %d", &xa, &ya, &r);
						flag = CIRCLE;
						break;
						

			}

			printf("translation vector(x,y): ");
			scanf("%d %d",&tx, &ty );

		// }while(op!= 4);

			glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(0, 0);

		glutCreateWindow("Smiley");
		init();
		glutDisplayFunc(display);
		// glutTimerFunc(25, update, 0);
		glutMainLoop();
		
		
	}