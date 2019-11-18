#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Circle.h"
#include "Printer.h"
#include <sstream>

extern Circle circle;
extern Printer print;
class Ladang
{
public:
	void petak(char *id) {
		glColor3ub(121, 60, 47);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(10, 0);
		glColor3ub(224, 138, 53);
		glVertex2f(10, 10);
		glVertex2f(0, 10);
		glEnd();
		glPushMatrix();
		glTranslatef(-5, 2, 0);
		glScalef(1, 0.3, 0);
		circle.drawCircle(0, 0, 0);
		glPopMatrix();
		glColor3f(1, 1, 1);
		print.drawText(1, 1, id);
	}
	void drawLadang() {
		int i;
		int a;
		int x = 0;
		int idpetak = 0;
		char cetak[1000];
		for (i = 1; i <= 3; i++) { //atas
			glTranslatef(0, 11, 0);
			x = 0;
			for (a = 1; a <= 3; a++) { //samping ke kanan
				idpetak++;
				sprintf_s(cetak, "%d", idpetak);
				glPushMatrix();
				glTranslatef(x, 0, 0);
				petak(cetak);
				x += 11;
				glPopMatrix();
			}
		}
	}
};