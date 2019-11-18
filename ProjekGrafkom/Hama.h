#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Circle.h"

extern Circle circle;

class Hama
{
public:
	void drawHama(int spawn) {
		//hama
		if (spawn == 1) {
			glColor3ub(105, 215, 228);
			glPushMatrix(); //telinga kiri
			glBegin(GL_POLYGON);
			glVertex2f(2, 3.88);
			glVertex2f(1.83, 3.96);
			glVertex2f(1.68, 3.98);
			glVertex2f(1.47, 3.93);
			glVertex2f(1.27, 3.82);
			glVertex2f(1.14, 3.59);
			glVertex2f(1.13, 3.42);
			glVertex2f(1.18, 3.25);
			glVertex2f(1.32, 3.13);
			glVertex2f(1.66, 2.99);
			glVertex2f(1.93, 3.42);
			glVertex2f(2.09, 3.75);
			glEnd();
			glPopMatrix();

			glPushMatrix(); // telinga kiri dalam
			glScalef(0.05, 0.05, 0);
			glTranslatef(23, 60, 0);
			circle.drawCircle(0, 0, 0);
			glPopMatrix();

			glColor3ub(105, 215, 228);
			glPushMatrix(); //telinga kanan
			glBegin(GL_POLYGON);
			glVertex2f(5.42, 3.97);
			glVertex2f(5.73, 4.09);
			glVertex2f(6.01, 4.04);
			glVertex2f(6.22, 3.89);
			glVertex2f(6.3, 3.64);
			glVertex2f(6.29, 3.41);
			glVertex2f(5.81, 3.11);
			glVertex2f(5.42, 3.51);
			glVertex2f(5.29, 3.83);
			glEnd();
			glPopMatrix();

			glPushMatrix(); //telinga kanan dalam
			glScalef(0.05, 0.05, 0);
			glTranslatef(105, 62, 0);
			circle.drawCircle(0, 0, 0);
			glPopMatrix();

			glColor3ub(105, 215, 228);
			glPushMatrix(); //badan
			glBegin(GL_POLYGON);
			glVertex2f(1.39, 0); //c
			glVertex2f(1.43, 0.45); //d
			glVertex2f(1.43, 0.91); //e
			glVertex2f(1.41, 1.44); //f
			glVertex2f(1.38, 2.0l); //g
			glVertex2f(1.42, 2.49); //h
			glVertex2f(1.52, 3.04); //i
			glVertex2f(1.73, 3.55); //j
			glVertex2f(2.16, 3.97); //k
			glVertex2f(2.67, 4.21); //l
			glVertex2f(3.25, 4.34); //m
			glVertex2f(3.9, 4.39); //n
			glVertex2f(4.51, 4.35); //o
			glVertex2f(5.22, 4.14); //p
			glVertex2f(5.67, 3.69); //q
			glVertex2f(5.93, 3.15); //r
			glVertex2f(6, 2.72); //s
			glVertex2f(6.09, 2.1); //t
			glVertex2f(6.13, 1.49); //u
			glVertex2f(6.14, 0.94); //v
			glVertex2f(6.18, 0.37); //w
			glVertex2f(6.18, 0);
			glEnd();
			glPopMatrix();

			glPushMatrix(); //mata kiri
			glTranslatef(1.3, 1.9, 0);
			glScalef(0.15, 0.14, 0);
			circle.drawCircle(1, 1, 1);
			glPopMatrix();

			glPushMatrix(); //mata kanan
			glTranslatef(3.2, 1.9, 0);
			glScalef(0.15, 0.14, 0);
			circle.drawCircle(1, 1, 1);
			glPopMatrix();

			glPushMatrix(); //pupil kiri
			glTranslatef(3.85, 2.6, 0);
			glScalef(0.06, 0.06, 0);
			circle.drawCircle(0, 0, 0);
			glPopMatrix();

			glPushMatrix(); //pupil kanan
			glTranslatef(1.95, 2.6, 0);
			glScalef(0.06, 0.06, 0);
			circle.drawCircle(0, 0, 0);
			glPopMatrix();

			glPushMatrix(); //gigi kiri
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
			glVertex2f(3.38, 2.2);
			glVertex2f(3.37, 2.13);
			glVertex2f(3.37, 2.08);
			glVertex2f(3.38, 2.02);
			glVertex2f(3.4, 1.96);
			glVertex2f(3.43, 1.91);
			glVertex2f(3.48, 1.87);
			glVertex2f(3.53, 1.84);
			glVertex2f(3.61, 1.86);
			glVertex2f(3.66, 1.9);
			glVertex2f(3.7, 1.96);
			glVertex2f(3.71, 2.07);
			glVertex2f(3.72, 2.14);
			glVertex2f(3.72, 2.23);
			glVertex2f(3.7, 2.4);
			glVertex2f(3.56, 2.38);
			glVertex2f(3.46, 2.33);
			glEnd();
			glPopMatrix();

			glPushMatrix(); //gigi kanan
			glColor3f(1, 1, 1);
			glTranslatef(0.35, 0, 0);
			glBegin(GL_POLYGON);
			glVertex2f(3.28, 2.2);
			glVertex2f(3.37, 2.13);
			glVertex2f(3.37, 2.08);
			glVertex2f(3.38, 2.02);
			glVertex2f(3.4, 1.96);
			glVertex2f(3.43, 1.91);
			glVertex2f(3.48, 1.87);
			glVertex2f(3.53, 1.84);
			glVertex2f(3.61, 1.86);
			glVertex2f(3.66, 1.9);
			glVertex2f(3.7, 1.96);
			glVertex2f(3.71, 2.07);
			glVertex2f(3.72, 2.14);
			glVertex2f(3.72, 2.23);
			glVertex2f(3.7, 2.4);
			glVertex2f(3.56, 2.38);
			glVertex2f(3.46, 2.33);
			glEnd();
			glPopMatrix();

			glPushMatrix(); //bibir
			glColor3ub(252, 213, 164);
			glBegin(GL_POLYGON);
			glVertex2f(3.5, 2.7);
			glVertex2f(3.32, 2.64);
			glVertex2f(3.2, 2.52);
			glVertex2f(3.17, 2.38);
			glVertex2f(3.26, 2.28);
			glVertex2f(3.39, 2.24);
			glVertex2f(3.51, 2.27);
			glVertex2f(3.67, 2.32);
			glVertex2f(3.73, 2.34);
			glVertex2f(3.81, 2.32);
			glVertex2f(3.89, 2.3);
			glVertex2f(3.99, 2.26);
			glVertex2f(4.12, 2.22);
			glVertex2f(4.22, 2.25);
			glVertex2f(4.29, 2.3);
			glVertex2f(4.33, 2.37);
			glVertex2f(4.34, 2.45);
			glVertex2f(4.26, 2.57);
			glVertex2f(4.13, 2.65);
			glVertex2f(4.01, 2.71);
			glVertex2f(3.74, 2.73);
			glEnd();
			glPopMatrix();

			glPushMatrix(); //hidung
			glTranslatef(3.05, 2.17, 0);
			glScalef(0.07, 0.05, 0);
			circle.drawCircle(0, 0, 0);
			glPopMatrix();
		}

		//bom
		if (spawn == 0)
		{
			glPushMatrix();
			glRotatef(30, 0, 0, 1);
			glTranslatef(1, -2, 0);

			glPushMatrix();
			glTranslatef(3.25, 4, 0);
			glColor3ub(224, 138, 53);
			glBegin(GL_POLYGON);
			glVertex2f(0.2, 0);
			glVertex2f(0.8, 0);
			glVertex2f(0.8, 1.5);
			glVertex2f(0.2, 1.5);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(3.25, 4, 0);
			glColor3f(0.15, 0.15, 0.15);
			glBegin(GL_POLYGON);
			glVertex2f(-0.2, 0);
			glVertex2f(1.2, 0);
			glVertex2f(1.2, 1);
			glVertex2f(-0.2, 1);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glScalef(0.5, 0.5, 0);
			glTranslatef(-2.5, -5, 0);
			circle.drawCircle(0.15, 0.15, 0.15);
			glPopMatrix();

			glPopMatrix();
		}
	}
	bool kenaBomb;
	void bombEffect(int orthox, int orthoy, float opacity) {
		//bom effect
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor4f(0.8, 0, 0, opacity);
		glVertex2f(0, 0);
		glVertex2f(orthox, 0);
		glVertex2f(orthox, orthoy);
		glVertex2f(0, orthoy);
		glEnd();
		glPopMatrix();
	}

}; // end of class