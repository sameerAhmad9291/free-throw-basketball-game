
#include "Texture.h"
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <math.h>

Texture theTexture;

float tx=0,ty=0.5,tz=3.8,sx=0.12,sy=0.2,sz=0.2,speed=0.015,speedx;
int uflag=1,tmp=0;
int x,y;
int r,g,b;
int count=0;

void text()
{
bool a = theTexture.Initialize();
printf("%i", a);
	
}	
void ball (void) 
{
	glPushMatrix();
	
			glColor3f(0,0,1);
			glTranslatef(tx,ty,tz);// (0,0.5,3.2) -----> (0,2.4,0.95) ball position at ring	
			glScalef(sx,sy,sz);		
			glutSolidSphere (1.0, 50, 50);

	glPopMatrix();
}
void ground()
{	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(-1,1);			glVertex3f(-1,-0.8,-1);
	glTexCoord2f(-1,-1);		glVertex3f(-1,-0.8,4.5);
	glTexCoord2f(1,-1);			glVertex3f(1,-0.8,4.5);
	glTexCoord2f(1,1);			glVertex3f(1,-0.8,-1);
	glEnd();
}

void shape (void)
{

	glEnable(GL_LIGHTING);
	GLfloat Light[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv (GL_LIGHT0, GL_DIFFUSE, Light);
	GLfloat LightPosition1[] = {1.0, 1.0, 1.0, 0.0};
	glLightfv (GL_LIGHT0, GL_POSITION, LightPosition1); 
	
	glDisable(GL_LIGHTING);
	
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, theTexture.textures[3]); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Sets the wrap parameter for texture coordinate t
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}


void cylinder()
{
	glColor3f(1,0.2,0.2);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glRotatef(-85.0f, 1.0f, .0f, 0.0f);
	glTranslatef(0,-1.0,0);
	gluCylinder(quadratic,0.1f,0.1f,2.85f,32,32);
	
	glRotatef(75.0f, 1.0f, .0f, 0.0f);
	glTranslatef(0,2.7,0.5);
	gluCylinder(quadratic,0.1f,0.1f,0.7f,32,32);
}
void rect3d(float x,float y ,float z,float x1,float y1,float z1)
{
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z);
	glVertex3f(x,y1,z1);
	glVertex3f(x1,y1,z1);
	glVertex3f(x1,y,z);
	glEnd();
}

void structure()
{
	glPushMatrix();
		glTranslatef(0,-0.5,-1);
		shape();
			ground();

			GLfloat ambic[]={0.2f,0.2f,0.2f,1.0f};
			glLightfv(GL_LIGHT0,GL_AMBIENT,ambic);
			GLfloat postion[]={2.0f,4.0f,6.0f,1.0f};
			glLightfv(GL_LIGHT0,GL_POSITION,postion);
	
			cylinder();

			glTranslatef(0,0.2,0);
			////front Boad

			glEnable(GL_BLEND);
			glBlendFunc (GL_ONE, GL_ONE); 
			glColor4f(.9,.9,.9,0.5);
			
			//rect3d(-0.5,-0.35,0.7,0.5,0.35,0.7);

			glBegin(GL_POLYGON);
			glVertex3f(-0.5,-0.35,0.7);
			glVertex3f(-0.5,0.35,0.7);
			glVertex3f(0.5,0.35,0.7);
			glVertex3f(0.5,-0.35,0.7);
			glEnd();
			glDisable (GL_BLEND);

			////// Border start
			glBegin(GL_POLYGON);
			glColor3f(0,0,0);
			glVertex3f(-0.5,-0.35,0.71);
			glVertex3f(-0.5,-0.33,0.71);
			glVertex3f(0.5,-0.33,0.71);
			glVertex3f(0.5,-0.35,0.71);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-0.5,0.35,0.71);
			glVertex3f(-0.5,0.33,0.71);
			glVertex3f(0.5,0.33,0.71);
			glVertex3f(0.5,0.35,0.71);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-0.5,-0.35,0.71);
			glVertex3f(-0.48,-0.35,0.71);
			glVertex3f(-0.48,0.35,0.71);
			glVertex3f(-0.5,0.35,0.71);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(0.5,-0.35,0.71);
			glVertex3f(0.48,-0.35,0.71);
			glVertex3f(0.48,0.35,0.71);
			glVertex3f(0.5,0.35,0.71);
			glEnd();
			///Border End

			glColor3f(1,0.2,0.2);
			glBegin(GL_POLYGON);
			glVertex3f(-0.1,-0.25,0.71);
			glVertex3f(0.1,-0.25,0.71);
			glVertex3f(0.1,-0.25,0.77);
			glVertex3f(-0.1,-0.25,0.77);
			glEnd();

		/// inner box
			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(-0.25,-0.28,0.71);
			glVertex3f(-0.25,-0.25,0.71);
			glVertex3f(0.25,-0.25,0.71);
			glVertex3f(0.25,-0.28,0.71);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-0.23,-0.25,0.71);
			glVertex3f(-0.25,-0.25,0.71);
			glVertex3f(-0.25,0.1,0.71);
			glVertex3f(-0.23,0.1,0.71);
			glEnd();

			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(-0.25,0.1,0.71);
			glVertex3f(-0.25,0.12,0.71);
			glVertex3f(0.25,0.12,0.71);
			glVertex3f(0.25,0.1,0.71);
			glEnd();

			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(0.25,0.12,0.71);
			glVertex3f(0.23,0.12,0.71);
			glVertex3f(0.23,-0.28,0.71);
			glVertex3f(0.25,-0.28,0.71);
			glEnd();
		///inner boxes Ends

			glColor3f(0,1,1);
			glTranslatef(0,-0.25,0.95);
			glScalef(0.006,0.006,0.006);
			glRotatef(-75,1,0,0);
			glutSolidTorus(2.5, 30.0, 50, 50);
			
			
			/*glBegin(GL_POLYGON);
			for(float a=0.0;a<6.2;a+=0.01)
			{
				glColor3f(1,0.3,0.1);
				glVertex2f(x+sin(a)*r1,y+cos(a)*r2);
			}*/
	glPopMatrix ();
}
void Panel(void)
{
  	glClearColor(0.9,0.9,0.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		structure();
		ball();

	glutSwapBuffers();

}

void animationFcn()
{	
		
	//tx=0,ty=0.5,tz=3.2
	
	//glTranslatef(0,2.8,0.95); // ball position at ring
    if( tx>-0.65 && tx<0.65 )
		tx+=speedx;
	
	if(tz>=0.95)
	   tz-=speed+0.001;

	if(uflag==1)
	{
		if(ty<=3.0)		
		{	
			ty+=speed+0.002;
			uflag=1;
		}

		else
			uflag=2;
	}
	else if(uflag==2)	
		{
				if(ty>=-0.3)
					ty-=speed;
				else
					uflag=3;
		}
	else if(uflag==3)
			{
				if(ty<=0.9)
					ty+=speed;
				else
					uflag=4;
			}
	else if(uflag==4)
			{
				if(ty>=-0.3)
					ty-=speed;
				else
					uflag=5;
			}
	else if(uflag==5)
			{
				if(ty<=0.5)
					ty+=speed;
				else		
					uflag=6;;
			}
	else if(uflag==6)
		{
				if(ty>=-0.3)
					ty-=speed;
				else		
					uflag=7;
		}
	else if(uflag==7)
		{
				if(ty<0.0)
					ty+=speed;
				else		
					uflag=8;
		}
	else if(uflag==8)
		{
				if(ty>=-0.3)
					ty-=speed;
				else		
					uflag=9;
		}
	else if(uflag==9)
		{
				if(ty<=-0.2)
					ty+=speed;
				else		
					uflag=10;
		}
	else if(uflag==10 && count==2)
	{
			if(ty>=-0.3)
					ty-=speed;
				else		
					uflag=9;
			count++;
	}
	else
	{
			glutIdleFunc(NULL);
	}
   glutPostRedisplay();


}

void mousecontrol(int button, int state, int x3, int y3)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		x=x3;
		y=y3;	
	}
	if( button==GLUT_LEFT_BUTTON && state==GLUT_UP)
		{
			printf("u x: %d , y: %d ",x3,y3);

			if( y>480 && y<560 && x>550 && x<643)
			{
				if (x3>623)
						speedx=0.001;
					else if(x3<573)
							speedx=-0.001;
						else
							speedx=0.0;
					uflag=1;
				glutIdleFunc(animationFcn);
			}
		}
	else if(button==GLUT_RIGHT_BUTTON&&uflag==10)
	{
		tx=0;
		ty=0.5;
		tz=3.8; 
		y=x=0;
	}
	glutPostRedisplay();
}

void init()
{
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glFrustum(-1,1,-1,1,1,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,2.2,5, 0,0,0, 0,1,0);
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1200,650);
	glutInitWindowPosition(80,50);
    glutCreateWindow ("Basket Ball");

    init(); //Call the function defined above
	text();	
   glutMouseFunc(mousecontrol);
	glutDisplayFunc(Panel); 
   glutMainLoop();

   return 0;
}