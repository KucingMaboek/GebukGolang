#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//
#include "Circle.h"
extern Circle circle;

class KincirAngin
{
public:
	float rotasi;
	bool muter = false;
	void baling() {
		glBegin(GL_POLYGON);
		glColor3ub(248, 156, 50);
		glVertex2f(4.54, 4.36);
		glVertex2f(4.25, 0.85);
		glColor3ub(153, 87, 54);
		glVertex2f(5.67, 0.39);
		glVertex2f(5.42, 4.4);
		glEnd();
	}
	void kipas(float kecepatanRotasi) {
		glPushMatrix();
		if (muter)
		{
			glRotatef(rotasi*kecepatanRotasi, 0, 0, 1);
		}
		glTranslatef(-5, -5, 0);
		glColor3f(1, 0, 0);
		glPushMatrix();
		baling();
		glPopMatrix();
		glPushMatrix();
		glRotatef(90, 0, 0, 1);
		glTranslatef(0, -10, 0);
		baling();
		glPopMatrix();
		glPushMatrix();
		glRotatef(180, 0, 0, 1);
		glTranslatef(-10, -10, 0);
		baling();
		glPopMatrix();
		glPushMatrix();
		glRotatef(270, 0, 0, 1);
		glTranslatef(-10, 0, 0);
		baling();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(3.4, 3.4, 0);
		glScalef(0.16, 0.16, 0);
		circle.drawCircle(0.957, 0.718, 0.325);
		glPopMatrix();

		glPopMatrix();
	}
	void drawKincirAngin(float kecepatanRotasi) {
		glPushMatrix();
		glTranslatef(-5, -6.3, 0);
		//bangunan utama
		glPushMatrix();
		glColor3f(1, 0, 1);
		glBegin(GL_POLYGON);
		glColor3ub(237, 50, 55);
		glVertex2f(2, 0);
		glVertex2f(2.5, 4);
		glVertex2f(3, 10);
		glColor3ub(101, 45, 13);
		glVertex2f(7, 10);
		glVertex2f(7.5, 4);
		glVertex2f(8, 0);
		glEnd();
		glPopMatrix();
		//pintu
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3ub(66, 2, 0);
		glVertex2f(4, 0);
		glVertex2f(6, 0);
		glColor3ub(36, 0, 0);
		glVertex2f(6, 3);
		glVertex2f(4, 3);
		glEnd();
		glPopMatrix();
		//gelang
		glColor3f(0, 0, 0);
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3ub(211, 203, 57);
		glVertex2f(2.2, 3.8);
		glVertex2f(7.8, 3.8);
		glColor3ub(245, 136, 52);
		glVertex2f(7.8, 4.2);
		glVertex2f(2.2, 4.2);
		glEnd();
		glPopMatrix();
		//atap
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3ub(238, 165, 52);
		glVertex2f(1, 8);
		glVertex2f(9, 8);
		glColor3ub(123, 81, 50);
		glVertex2f(5, 12);
		glEnd();
		glPopMatrix();
		glPopMatrix();
		//kincir
		glPushMatrix();
		kipas(kecepatanRotasi);
		glPopMatrix();
	}
}; //end of class