#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Circle
{
public:
	void drawCircle(float r, float g, float b) {
		glTranslatef(10, 10, 0);
		glColor3f(r, g, b);

		for (int i = 0; i < 360; i++) {
			glRotated(1, 0, 0, 1);
			glBegin(GL_POLYGON);
			glVertex2f(3.1, 0);
			glVertex2f(0, 0);
			glVertex2f(0, 3.1);
			glVertex2f(3.1, 3.1);
			glEnd();
		}
	}
};