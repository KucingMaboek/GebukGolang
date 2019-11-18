#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Circle.h"
extern Circle circle;
class Awan
{
public:
	void drawAwan() {
		glPushMatrix();
		glScalef(1, 0.5, 0);
		circle.drawCircle(1, 1, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2, 2, 0);
		glScalef(1, 0.5, 0);
		circle.drawCircle(1, 1, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(3, -1.5, 0);
		glScalef(1, 0.5, 0);
		circle.drawCircle(1, 1, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(7, -1, 0);
		glScalef(1, 0.5, 0);
		circle.drawCircle(1, 1, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(6, 0.5, 0);
		glScalef(1, 0.5, 0);
		circle.drawCircle(1, 1, 1);
		glPopMatrix();
	}
	float awanStart[7] = { -10,10,25,50,80,110,120 };

	void awanMove() {
		awanStart[0] += 0.06;
		awanStart[1] += 0.1;
		awanStart[2] += 0.07;
		awanStart[3] += 0.13;
		awanStart[4] += 0.15;
		awanStart[5] += 0.05;
		awanStart[6] += 0.07;

		if (awanStart[0] >= 160) { awanStart[0] = -30; }
		if (awanStart[1] >= 160) { awanStart[1] = -30; }
		if (awanStart[2] >= 160) { awanStart[2] = -30; }
		if (awanStart[3] >= 160) { awanStart[3] = -30; }
		if (awanStart[4] >= 160) { awanStart[4] = -30; }
		if (awanStart[5] >= 160) { awanStart[5] = -30; }
		if (awanStart[6] >= 160) { awanStart[6] = -30; }
	}



	void awanPosInit() {
		//awan start
		glPushMatrix();

		glPushMatrix();
		glTranslatef(awanStart[0], 80, 0);
		glScalef(1, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[1], 70, 0);
		glScalef(2, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[2], 80, 0);
		glScalef(2, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[3], 75, 0);
		glScalef(1.7, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[4], 73, 0);
		glScalef(1.2, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[5], 77, 0);
		glScalef(1, 1, 0);
		drawAwan();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(awanStart[6], 71, 0);
		glScalef(2, 1, 0);
		drawAwan();
		glPopMatrix();

		glPopMatrix();
		//awan end
	}
};