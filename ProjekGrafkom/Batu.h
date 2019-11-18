#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Batu
{
public:
	void drawBatu() {
		glBegin(GL_POLYGON);
		glColor3ub(122, 122, 122);
		glVertex2f(2.19, 0.02);
		glVertex2f(2.19, 0.27);
		glColor3ub(74, 74, 74);
		glVertex2f(2.28, 0.49);
		glVertex2f(2.54, 0.68);
		glVertex2f(2.87, 0.7);

		glVertex2f(3.14, 0.59);
		glColor3f(0, 0, 0);
		glVertex2f(3.3, 0.4);
		glVertex2f(3.35, 0.21);
		glVertex2f(3.35, 0.01);
		glEnd();

	}

}; //end of class