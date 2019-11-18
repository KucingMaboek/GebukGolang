#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Bimo
{
public:
	int angka = 1;
	float rotasi;
	void drawBimo() {
		//BODY
		glBegin(GL_POLYGON); // BODY 1
		glColor3f(0.023, 0.482, 0.376);
		glVertex2d(-5, -5);
		glVertex2f(-5, 10);
		glVertex2f(8, 10);
		glColor3f(0.062, 0.6, 0.482);
		glVertex2f(8, -5);
		glEnd();
		glBegin(GL_POLYGON); //BODY 2
		glColor3f(0.023, 0.482, 0.376);
		glVertex2f(-5.5, -4.5);
		glVertex2f(-5.5, 9.5);
		glVertex2f(8.5, 9.5);
		glColor3f(0.062, 0.6, 0.482);
		glVertex2f(8.5, -4.5);
		glEnd();

		//FACE
		glBegin(GL_POLYGON); //muka 1
		glColor3f(0.4, 0.764, 0.690);
		glVertex2f(-3.5, 3);
		glVertex2f(-3.5, 8);
		glVertex2f(3.5, 8);
		glVertex2f(3.5, 3);
		glEnd();
		glBegin(GL_POLYGON); //muka 2
		glColor3f(0.4, 0.764, 0.690);
		glVertex2f(-4, 3.5);
		glVertex2f(-4, 7.5);
		glVertex2f(4, 7.5);
		glVertex2f(4, 3.5);
		glEnd();
		glBegin(GL_POLYGON); //mata kiri
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(-2.5, 7);
		glVertex2f(-2, 7);
		glVertex2f(-2, 6);
		glVertex2f(-2.5, 6);
		glEnd();
		glBegin(GL_POLYGON); //mata kanan
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(2, 7);
		glVertex2f(2.5, 7);
		glVertex2f(2.5, 6);
		glVertex2f(2, 6);
		glEnd();
		glBegin(GL_POLYGON); //mulut
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(-1, 5.5);
		glVertex2f(1, 5.5);
		glVertex2f(1, 5);
		glVertex2f(-1, 5);
		glEnd();
		glBegin(GL_POLYGON); //pipi kiri
		glColor3f(0.517, 0.823, 0.768);
		glVertex2f(-3.5, 5.5);
		glVertex2f(-3, 5.5);
		glVertex2f(-3, 5);
		glVertex2f(-3.5, 5);
		glEnd();
		glBegin(GL_POLYGON); //pipi kanan
		glColor3f(0.517, 0.823, 0.768);
		glVertex2f(3, 5.5);
		glVertex2f(3.5, 5.5);
		glVertex2f(3.5, 5);
		glVertex2f(3, 5);
		glEnd();

		//detail badan
		glBegin(GL_POLYGON);//detail 1
		glColor3f(0.145, 0.254, 0.196);
		glVertex2f(-4, 2);
		glVertex2f(1, 2);
		glVertex2f(1, 1.5);
		glVertex2f(-4, 1.5);
		glEnd();
		glBegin(GL_POLYGON);//detail 2
		glColor3f(0.039, 0.078, 0.450);
		glVertex2f(3, 2);
		glVertex2f(3.5, 2);
		glVertex2f(3.5, 1.5);
		glVertex2f(3, 1.5);
		glEnd();
		glBegin(GL_POLYGON);//detail 3
		glColor3f(0.686, 0.835, 0.164);
		glVertex2d(-3, 0.5);
		glVertex2f(-2.5, 0.5);
		glVertex2f(-2.5, -1);
		glVertex2f(-3, -1);
		glEnd();
		glBegin(GL_POLYGON);//detail 3.5
		glColor3f(0.686, 0.835, 0.164);
		glVertex2f(-3.5, 0);
		glVertex2f(-2, 0);
		glVertex2f(-2, -0.5);
		glVertex2f(-3.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);//detail 4
		glColor3f(0.254, 0.639, 0.745);
		glVertex2f(1.5, 0);
		glVertex2f(2, 0);
		glVertex2f(2, -0.5);
		glVertex2f(1.5, -0.5);
		glEnd();
		glBegin(GL_POLYGON);//detail 4.5
		glColor3f(0.254, 0.639, 0.745);
		glVertex2f(1, -0.5);
		glVertex2f(2.5, -0.5);
		glVertex2f(2.5, -1);
		glVertex2f(1, -1);
		glEnd();
		glBegin(GL_POLYGON); //detail 5
		glColor3f(0.031, 0.533, 0.309);
		glVertex2f(3, 0);
		glVertex2f(4, 0);
		glVertex2f(4, -1);
		glVertex2f(3, -1);
		glEnd();
		glBegin(GL_POLYGON); //detail 6
		glColor3f(0.039, 0.078, 0.450);
		glVertex2f(-4, -2.5);
		glVertex2f(-3, -2.5);
		glVertex2f(-3, -3);
		glVertex2f(-4, -3);
		glEnd();
		glBegin(GL_POLYGON); //detail 7
		glColor3f(0.039, 0.078, 0.450);
		glVertex2f(-2.5, -2.5);
		glVertex2f(-1.5, -2.5);
		glVertex2f(-1.5, -3);
		glVertex2f(-2.5, -3);
		glEnd();
		glBegin(GL_POLYGON); //detail 8
		glColor3f(0.666, 0.113, 0.078);
		glVertex2f(1.5, -2);
		glVertex2f(2.5, -2);
		glVertex2f(2.5, -3);
		glVertex2f(1.5, -3);

		glEnd();

		//detail body 2
		glBegin(GL_LINES);
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(5, -5);
		glVertex2f(5, 10);
		glEnd();
		glBegin(GL_POLYGON);//lubang 1
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(6, 9);
		glVertex2f(6.5, 9);
		glVertex2f(6.5, 8.5);
		glVertex2f(6, 8.5);
		glEnd();
		glBegin(GL_POLYGON);//lubang 2
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(7, 9);
		glVertex2f(7.5, 9);
		glVertex2f(7.5, 8.5);
		glVertex2f(7, 8.5);
		glEnd();
		glBegin(GL_POLYGON);//lubang 3
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(5.5, 8);
		glVertex2f(6, 8);
		glVertex2f(6, 7.5);
		glVertex2f(5.5, 7.5);
		glEnd();
		glBegin(GL_POLYGON); //lubang 4
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(6.5, 8);
		glVertex2f(7, 8);
		glVertex2f(7, 7.5);
		glVertex2f(6.5, 7.5);
		glEnd();
		glBegin(GL_POLYGON); //lubang 5
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(7.5, 8);
		glVertex2f(8, 8);
		glVertex2f(8, 7.5);
		glVertex2f(7.5, 7.5);
		glEnd();
		glBegin(GL_POLYGON); //lubang 6
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(6, 7);
		glVertex2f(6.5, 7);
		glVertex2f(6.5, 6.5);
		glVertex2f(6, 6.5);
		glEnd();
		glBegin(GL_POLYGON); //lubang 7
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(7, 7);
		glVertex2f(7.5, 7);
		glVertex2f(7.5, 6.5);
		glVertex2f(7, 6.5);
		glEnd();
		glBegin(GL_POLYGON); //bahu 1
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(5.7, 1.7);
		glVertex2f(7.3, 1.7);
		glVertex2f(7.3, 1.5);
		glVertex2f(5.7, 1.5);
		glEnd();
		glBegin(GL_POLYGON); //bahu 2
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(5.5, 1.5);
		glVertex2f(7.5, 1.5);
		glVertex2f(7.5, 1.3);
		glVertex2f(5.5, 1.3);
		glEnd();

		//tangan kaki
		glBegin(GL_POLYGON); //tangan kanan
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(6, 1.5);
		glVertex2f(7, 1.5);
		glVertex2f(7, -7);
		glVertex2f(6, -7);
		glEnd();
		glBegin(GL_POLYGON); //tangan kiri
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(-5, -5);
		glVertex2f(-4, -5);
		glVertex2f(-4, -7);
		glVertex2f(-5, -7);
		glEnd();
		glBegin(GL_POLYGON); //kaki kiri 1
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(-3, -5);
		glVertex2f(-2, -5);
		glVertex2f(-2, -9);
		glVertex2f(-3, -9);
		glEnd();
		glBegin(GL_POLYGON); //kaki kiri 2
		glColor3f(0.098, 0.301, 0.254);
		glVertex2f(-4, -9);
		glVertex2f(-2, -9);
		glVertex2f(-2, -10);
		glVertex2f(-4, -10);
		glEnd();
		glBegin(GL_POLYGON); //kaki kanan 1
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(4, -5);
		glVertex2f(5, -5);
		glVertex2f(5, -9);
		glVertex2f(4, -9);
		glEnd();
		glBegin(GL_POLYGON); //kaki kanan 2
		glColor3f(0.031, 0.462, 0.364);
		glVertex2f(3, -9);
		glVertex2f(5, -9);
		glVertex2f(5, -10);
		glVertex2f(3, -10);
		glEnd();
	}

	void bimoMuter() {
		rotasi += 2;
	}
}; //end of class