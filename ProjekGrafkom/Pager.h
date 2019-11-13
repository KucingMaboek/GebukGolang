#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

class Pager
{
public:
	void drawPager() {
		//vertical
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(1, 6);
		glVertex2f(1, 0);
		glColor3ub(121, 60, 47);
		glVertex2f(2.75, 0);
		glVertex2f(3, 6);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(4.5, 6);
		glVertex2f(4.85, 0);
		glColor3ub(121, 60, 47);
		glVertex2f(6.5, 0);
		glVertex2f(6.5, 6);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(8.5, 6);
		glVertex2f(9, 0);
		glColor3ub(121, 60, 47);
		glVertex2f(10.35, 0);
		glVertex2f(10.5, 6);
		glEnd();
		//horizontal
		glColor3f(1, 0, 1);
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(0, 5.5);
		glVertex2f(0, 4);
		glColor3ub(121, 60, 47);
		glVertex2f(12, 4.3);
		glVertex2f(12, 5.5);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(224, 138, 53);
		glVertex2f(0, 2.5);
		glVertex2f(12, 2.7);
		glColor3ub(121, 60, 47);
		glVertex2f(12, 1.5);
		glVertex2f(0, 1.5);
		glEnd();
	}
};