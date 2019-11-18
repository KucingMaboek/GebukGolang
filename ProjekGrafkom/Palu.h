#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Palu
{
public:
	float angle = 15;
	void drawPalu() {
		glRotatef(angle, 0, 0, 1);
		//gagangnya
		glColor3f(0, 1, 1);
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(2.25, 8.5);
		glVertex2f(2.25, 0);
		glColor3ub(121, 60, 47);
		glVertex2f(3.75, 0);
		glVertex2f(3.75, 8.5);
		glEnd();
		//palunya
		glBegin(GL_POLYGON);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(6, 5);
		glVertex2f(0, 5);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(0, 8);
		glVertex2f(6, 8);
		glEnd();
	}
}; //end of class