/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
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
#include "Bimo.h"
#include "Batu.h"
#include "Pager.h"
#endif
using namespace std;

Bimo bimo;
Batu batu;
Pager pager;
float angle = 15;
bool paluGerak = true;
int refreshmill = 1;
bool selected = false;
float paluX = 50;
float paluY = 10;
int sleepdelay = 0;
float rotasi;
bool muter = true;
int waktu = 60;
float speedPalu = 1;
char cetakwaktu[1000];
int currentScore = 0;
int targetScore = 1000;
char cetaktarget[1000];
char cetakscore[1000];
char numpad[1000] = "On";
bool numpadtoggle = true;
float bimomuter;
float awanEnd = -10;
float awanEnd1 = 10;
float awanEnd2 = 25;
float awanEnd3 = 50;
float awanEnd4 = 80;
float awanEnd5 = 110;
float awanEnd6 = 120;
int randSpawn;
int koordinat;
int koordinat1;
int koordinatPalu;
int playbutton[4] = { 75, 40, 100, 50 }; //x1,y1,x2,y2
float ortho[2] = { 171,91 };
float paluPosXY[10][2] = { {200,200}, {34.1,5.5}, {42.1,5.5}, {50,5.5}, {34.1,13.5}, {42.1,13.5}, {50,13.5}, {34.1,21.5}, {42.1,21.5}, {50,21.5} };
float dataPosXY[10][2] = { {200,200}, {19.2,4.8}, {25.8, 4.8}, { 32.4, 4.8 }, {19.2,11.4}, { 25.8,11.4 }, { 32.4,11.4 },  {19.2,18},  { 25.8,18 },   { 32.4,18 } };
float PosX = 200;
float PosY = 200;
float PosX1 = 200;
float PosY1 = 200;
bool change = false;
bool hover = false;
void *font = GLUT_BITMAP_HELVETICA_12;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;

void timer(int value) {
	if (waktu > 0)
	{
		awanEnd+=0.06;
		awanEnd1+=0.1;
		awanEnd2+=0.07;
		awanEnd3+=0.13;
		awanEnd4 += 0.15;
		awanEnd5 += 0.05;
		awanEnd6 += 0.07;
		bimomuter+=2;
	}
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}
void score(int value) {
	if (change)
	{
		if (waktu > 0)
		{
			waktu--;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(1000, score, 0);
}
void hamaSpawn(int value) {
	randSpawn = rand() % 2;
	if (waktu > 0) {
		koordinat = rand() % 10;
		koordinat1 = rand() % 10;
		if (koordinat == koordinat1)
		{
			koordinat1 = 0;
		}
		PosX = dataPosXY[koordinat][0];
		PosY = dataPosXY[koordinat][1];
		PosX1 = dataPosXY[koordinat1][0];
		PosY1 = dataPosXY[koordinat1][1];

		glutPostRedisplay();
		glutTimerFunc(1300, hamaSpawn, 0);
	}
}
void print(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font2, string[i]);
	}
}

void hamaReset(int koor) {
	if (koor == 0)
	{
		koordinat = 0;
		PosX = dataPosXY[0][0];
		PosY = dataPosXY[0][1];
		if (randSpawn == 0)
		{
		currentScore -= 50;
		}
		else
		{
			currentScore += 20;
		}
	}
	if (koor == 1)
	{
		koordinat1 = 0;
		PosX1 = dataPosXY[0][0];
		PosY1 = dataPosXY[0][1];
		currentScore += 20;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'c') {
		change = true;
	}
	if (waktu > 0) {
		if (key == 32) {
			angle = 90;
			paluGerak = false;
		}
		if (numpadtoggle == true) {
			if (key == '1') {
				paluX = paluPosXY[1][0];
				paluY = paluPosXY[1][1];
				koordinatPalu = 1;
				angle = 90;
			}
			if (key == '2') {
				paluX = paluPosXY[2][0];
				paluY = paluPosXY[2][1];
				koordinatPalu = 2;
				angle = 90;
			}
			if (key == '3') {
				paluX = paluPosXY[3][0];
				paluY = paluPosXY[3][1];
				koordinatPalu = 3;
				angle = 90;
			}
			if (key == '4') {
				paluX = paluPosXY[4][0];
				paluY = paluPosXY[4][1];
				koordinatPalu = 4;
				angle = 90;
			}
			if (key == '5') {
				paluX = paluPosXY[5][0];
				paluY = paluPosXY[5][1];
				koordinatPalu = 5;
				angle = 90;
			}
			if (key == '6') {
				paluX = paluPosXY[6][0];
				paluY = paluPosXY[6][1];
				koordinatPalu = 6;
				angle = 90;
			}
			if (key == '7') {
				paluX = paluPosXY[7][0];
				paluY = paluPosXY[7][1];
				koordinatPalu = 7;
				angle = 90;
			}
			if (key == '8') {
				paluX = paluPosXY[8][0];
				paluY = paluPosXY[8][1];
				koordinatPalu = 8;
				angle = 90;
			}
			if (key == '9') {
				paluX = paluPosXY[9][0];
				paluY = paluPosXY[9][1];
				koordinatPalu = 9;
				angle = 90;
			}
		}
	}
}


void mousehover(int mousex, int mousey) {
	int mousexHoverPos = mousex / 8;
	int mouseyHoverPos = 91-(mousey / 8);
	printf("%i current mouse x position \n", mousexHoverPos);
	printf("%i current mouse y position \n", mouseyHoverPos);
	
	//deteksi koordinat mouse
	//glBegin(GL_LINES);
	//	glVertex2f(mousexHoverPos, 91);
	//	glVertex2f(mousexHoverPos, 0);
	//glEnd;
	//glBegin(GL_LINES);
	//glVertex2f(0, (mouseyHoverPos));
	//glVertex2f(171, (9mouseyHoverPos));
	//glEnd;

	if (mousexHoverPos >= playbutton[0] && mousexHoverPos <= playbutton[2])
	{
		if (mouseyHoverPos >= playbutton[1] && mouseyHoverPos <= playbutton[3])
		{
			hover = true;
		}
		else
		{
			hover = false;
		}
	}
	else
	{
		hover = false;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int mousex, int mousey) {
	//int width, height;
	//width = glutGet(GLUT_WINDOW_WIDTH)/8;
	//height = glutGet(GLUT_WINDOW_HEIGHT)/8;
	int mousexPos = mousex / 8;
	int mouseyPos = 91-(mousey / 8);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_ENTERED && mousexPos >= playbutton[0] && mousexPos <= playbutton[2])
	{
		printf("%i posisi mouse x\n", mousexPos);
		printf("%i posisi mouse y\n", mouseyPos);
		if (mouseyPos >= playbutton[1] && mouseyPos <= playbutton[3])
		{
			change = true;
		}
	}
	glutPostRedisplay();
}

void keyboardup(unsigned char key, int x, int y)
{
	if (waktu > 0) {
		if (key == 32) {
			//if (koordinatPalu == koordinat) { hamaReset(0); }
			//if (koordinatPalu == koordinat1) { hamaReset(1); }
			angle = 15;
			paluGerak = true;
		}
		if (key == 'o')
		{
			numpadtoggle = !numpadtoggle;
			if (numpadtoggle == true)
			{
				sprintf_s(numpad, "On");
			}
			else
			{
				sprintf_s(numpad, "Off");
			}
		}
		
		//numpad
		if (numpadtoggle == true) {
			if (key == '1') {
				angle = 15;
				if (koordinat == 1)
				{
					hamaReset(0);
				}
				if (koordinat1 == 1)
				{
					hamaReset(1);
				}
			}
			if (key == '2') {
				angle = 15;
				if (koordinat == 2)
				{
					hamaReset(0);
				}
				if (koordinat1 == 2)
				{
					hamaReset(1);
				}
			}
			if (key == '3') {
				angle = 15;
				if (koordinat == 3)
				{
					hamaReset(0);
				}
				if (koordinat1 == 3)
				{
					hamaReset(1);
				}
			}
			if (key == '4') {
				angle = 15;
				if (koordinat == 4)
				{
					hamaReset(0);
				}
				if (koordinat1 == 4)
				{
					hamaReset(1);
				}
			}
			if (key == '5') {
				angle = 15;
				if (koordinat == 5)
				{
					hamaReset(0);
				}
				if (koordinat1 == 5)
				{
					hamaReset(1);
				}
			}
			if (key == '6') {
				angle = 15;
				if (koordinat == 6)
				{
					hamaReset(0);
				}
				if (koordinat1 == 6)
				{
					hamaReset(1);
				}
			}
			if (key == '6') {
				angle = 15;
				if (koordinat == 6)
				{
					hamaReset(0);
				}
				if (koordinat1 == 6)
				{
					hamaReset(1);
				}
			}
			if (key == '7') {
				angle = 15;
				if (koordinat == 7)
				{
					hamaReset(0);
				}
				if (koordinat1 == 7)
				{
					hamaReset(1);
				}
			}
			if (key == '8') {
				angle = 15;
				if (koordinat == 8)
				{
					hamaReset(0);
				}
				if (koordinat1 == 8)
				{
					hamaReset(1);
				}
			}
			if (key == '9') {
				angle = 15;
				if (koordinat == 9)
				{
					hamaReset(0);
				}
				if (koordinat1 == 9)
				{
					hamaReset(1);
				}
			}
		}
	}
}


void keyboardfunction() {
	if (waktu > 0) {
		if (numpadtoggle == false) {
			if (GetAsyncKeyState(VK_UP) && paluGerak == true)
			{
				paluY += speedPalu;
			}
			if (GetAsyncKeyState(VK_DOWN) && paluGerak == true)
			{
				paluY -= speedPalu;
			}
			if (GetAsyncKeyState(VK_RIGHT) && paluGerak == true)
			{
				paluX += speedPalu;
			}
			if (GetAsyncKeyState(VK_LEFT) && paluGerak == true)
			{
				paluX -= speedPalu;
			}
		}
	}
}


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

void baling() {
	glBegin(GL_POLYGON);
	glColor3ub(248,156,50);
	glVertex2f(4.54, 4.36);
	glVertex2f(4.25, 0.85);
	glColor3ub(153,87,54);
	glVertex2f(5.67, 0.39);
	glVertex2f(5.42, 4.4);
	glEnd();
}
void kincirAngin(float kecepatanRotasi) {
	glPushMatrix();
	if (waktu > 0)
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
	drawCircle(0.957, 0.718, 0.325);
	glPopMatrix();

	glPopMatrix();
}
void kincir(float kecepatanRotasi) {
	glPushMatrix();
	glTranslatef(-5, -6.3, 0);
	//bangunan utama
	glPushMatrix();
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glColor3ub(237,50,55);
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
	glColor3ub(66,2,0);
	glVertex2f(4,0);
	glVertex2f(6,0);
	glColor3ub(36, 0,0);
	glVertex2f(6,3);
	glVertex2f(4,3);
	glEnd();
	glPopMatrix();
	//gelang
	glColor3f(0, 0, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(211,203,57);
	glVertex2f(2.2,3.8);
	glVertex2f(7.8,3.8);
	glColor3ub(245,136,52);
	glVertex2f(7.8,4.2);
	glVertex2f(2.2,4.2);
	glEnd();
	glPopMatrix();
	//atap
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(238,165,52);
	glVertex2f(1,8);
	glVertex2f(9,8);
	glColor3ub(123,81,50);
	glVertex2f(5,12);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	//kincir
	glPushMatrix();
	kincirAngin(kecepatanRotasi);
	glPopMatrix();
}

void palu() {
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

void hama(int spawn) {
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
		drawCircle(0, 0, 0);
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
		drawCircle(0, 0, 0);
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
		drawCircle(1, 1, 1);
		glPopMatrix();

		glPushMatrix(); //mata kanan
		glTranslatef(3.2, 1.9, 0);
		glScalef(0.15, 0.14, 0);
		drawCircle(1, 1, 1);
		glPopMatrix();

		glPushMatrix(); //pupil kiri
		glTranslatef(3.85, 2.6, 0);
		glScalef(0.06, 0.06, 0);
		drawCircle(0, 0, 0);
		glPopMatrix();

		glPushMatrix(); //pupil kanan
		glTranslatef(1.95, 2.6, 0);
		glScalef(0.06, 0.06, 0);
		drawCircle(0, 0, 0);
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
		drawCircle(0, 0, 0);
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
		drawCircle(0.15, 0.15, 0.15);
		glPopMatrix();

		glPopMatrix();
	}
}
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
	drawCircle(0, 0, 0);
	glPopMatrix();
	glColor3f(1, 1, 1);
	print(1, 1, id);
}
void ladang() {
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

void awan() {
	glPushMatrix();
	glScalef(1, 0.5, 0);
	drawCircle(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2, 2, 0);
	glScalef(1, 0.5, 0);
	drawCircle(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, -1.5, 0);
	glScalef(1, 0.5, 0);
	drawCircle(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7, -1, 0);
	glScalef(1, 0.5, 0);
	drawCircle(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6, 0.5, 0);
	glScalef(1, 0.5, 0);
	drawCircle(1, 1, 1);
	glPopMatrix();
}


void display() {
	keyboardfunction();
	glClearColor(0, 0.776, 0.929, 1);
	glClear(GL_COLOR_BUFFER_BIT); //menghapus windows dan memberi warna yang ada di glclearcolor
	glLoadIdentity();
	sprintf_s(cetakwaktu, "%d", waktu);
	sprintf_s(cetakscore, "%d", currentScore);
	sprintf_s(cetaktarget, "%d", targetScore);
	//0.0,171,0.0,91

	glBegin(GL_POLYGON); //langit
	glColor3f(0, 0.776, 0.929);
	glVertex2f(0, 70);
	glVertex2f(171, 70);
	glColor3ub(199, 255, 242);
	glVertex2f(171, 91);
	glVertex2f(0, 91);
	glEnd();

	glPushMatrix();
	glTranslatef(171, 75, 0);
	glTranslatef(-(bimomuter*0.1), 10, 0);
	glScalef(0.3, 0.3, 0);
	glRotatef(bimomuter, 0, 0, 1);
	bimo.drawBimo();
	glPopMatrix();

	//awan start
	glPushMatrix();

	if (awanEnd >= 160) { awanEnd = -30; }
	if (awanEnd1 >= 160) { awanEnd1 = -30; }
	if (awanEnd2 >= 160) { awanEnd2 = -30; }
	if (awanEnd3 >= 160) { awanEnd3 = -30; }
	if (awanEnd4 >= 160) { awanEnd4 = -30; }

	glPushMatrix();
	glTranslatef(awanEnd, 80, 0);
	glScalef(1, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd1, 70, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd2, 80, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd3, 75, 0);
	glScalef(1.7, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd4, 73, 0);
	glScalef(1.2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd5, 77, 0);
	glScalef(1, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd6, 71, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();

	glPopMatrix();
	//awan end

	glBegin(GL_POLYGON);
	glColor3f(0.063, 0.91, 0.176);
	glVertex2f(0, 0);
	glVertex2f(171, 0);
	glColor3ub(125, 191, 0);
	glVertex2f(171, 75);
	glVertex2f(0, 75);
	glEnd();

	glPushMatrix();
	glTranslatef(60, -15, 0);
	glScalef(1.8, 1.8, 0);
	ladang();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 65, 0);
	glScalef(3, 3, 0);
	pager.drawPager();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(90, 65, 0);
	glScalef(3, 3, 0);
	pager.drawPager();
	glPopMatrix();

	//hama start
	glPushMatrix();
	glScalef(3, 3, 0);
	glTranslatef(PosX, PosY, 0);
	hama(randSpawn);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, 3, 0);
	glTranslatef(PosX1, PosY1, 0);
	hama(1);
	glPopMatrix();
	//hama end

	//batu start
	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslatef(1, 1, 0);
	batu.drawBatu();
	glScalef(0.7, 0.7, 0);
	batu.drawBatu();
	glPopMatrix();

	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslated(13, 2, 0);
	batu.drawBatu();
	glPopMatrix();

	glPushMatrix();
	glScalef(6, 6, 0);
	glTranslated(1, 6, 0);
	batu.drawBatu();
	glPopMatrix();
	//batu end

	glPushMatrix();
	glTranslatef(150, 80, 0);
	glScalef(3, 3, 0);
	kincir(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(141, 73, 0);
	glScalef(2, 2, 0);
	kincir(2);
	glPopMatrix();
	rotasi++;

	//UI start

	//palu start
	glPushMatrix();
	glScalef(2.5, 2.5, 0);
	glTranslatef(paluX, paluY, 0);
	palu();
	glPopMatrix();
	//palu end


	if (waktu <= 0)
	{
		//gameover
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(40, 30);
		glVertex2f(137, 30);
		glColor3f(1, 1, 1);
		glVertex2f(137, 70);
		glVertex2f(40, 70);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		print(75, 63, "Game Over..");
		print(75, 55, "Score:");
		print(120, 55, cetakscore);
		print(75, 50, "Target score:");
		print(120, 50, cetaktarget);
		if (currentScore < targetScore)
		{
			print(90, 35, "Kamu kalah");
		}
		else
		{
			print(90, 35, "Kamu menang");
		}
		glTranslatef(60, 50, 0);
		glScalef(-1.5, 1.5, 0);
		bimo.drawBimo();
		glPopMatrix();
	}
	

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(2, 90);
	glVertex2f(30, 90);
	glColor3ub(222, 222, 222);
	glVertex2f(30, 76);
	glVertex2f(2, 76);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(2, 90);
	glVertex2f(30, 90);
	glVertex2f(30, 76);
	glVertex2f(2, 76);
	glEnd();
	glPopMatrix();
	glColor3f(0, 0, 0);
	print(3, 86, "Score :");
	print(23, 86, cetakscore);
	print(3, 82, "Sisa Waktu :");
	print(23, 82, cetakwaktu);
	print(3, 78, "Numpad mode:");
	print(23, 78, numpad);
	//UI end

	glutSwapBuffers();
	glFlush(); //memaksa proses menggambar sampai selesai
}


//page 1
void mainMenu() {
	glClearColor(0, 0.776, 0.929, 1);
	glClear(GL_COLOR_BUFFER_BIT); //menghapus windows dan memberi warna yang ada di glclearcolor
	glLoadIdentity();
	sprintf_s(cetaktarget, "%d", targetScore);
	//0.0,171,0.0,91

	glBegin(GL_POLYGON); //langit
	glColor3f(0, 0.776, 0.929);
	glVertex2f(0, 70);
	glVertex2f(171, 70);
	glColor3ub(199, 255, 242);
	glVertex2f(171, 91);
	glVertex2f(0, 91);
	glEnd();

	glPushMatrix();
	glTranslatef(171, 75, 0);
	glTranslatef(-(bimomuter*0.1), 10, 0);
	glScalef(0.3, 0.3, 0);
	glRotatef(bimomuter, 0, 0, 1);
	bimo.drawBimo();
	glPopMatrix();

	//awan start
	glPushMatrix();

	if (awanEnd >= 160) { awanEnd = -30; }
	if (awanEnd1 >= 160) { awanEnd1 = -30; }
	if (awanEnd2 >= 160) { awanEnd2 = -30; }
	if (awanEnd3 >= 160) { awanEnd3 = -30; }
	if (awanEnd4 >= 160) { awanEnd4 = -30; }

	glPushMatrix();
	glTranslatef(awanEnd, 80, 0);
	glScalef(1, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd1, 70, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd2, 80, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd3, 75, 0);
	glScalef(1.7, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd4, 73, 0);
	glScalef(1.2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd5, 77, 0);
	glScalef(1, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(awanEnd6, 71, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();

	glPopMatrix();
	//awan end

	glBegin(GL_POLYGON);
	glColor3f(0.063, 0.91, 0.176);
	glVertex2f(0, 0);
	glVertex2f(171, 0);
	glColor3ub(125, 191, 0);
	glVertex2f(171, 75);
	glVertex2f(0, 75);
	glEnd();

	//glPushMatrix();
	//glTranslatef(60, -15, 0);
	//glScalef(1.8, 1.8, 0);
	//ladang();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(50, 65, 0);
	//glScalef(3, 3, 0);
	//pager.drawPager();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(90, 65, 0);
	//glScalef(3, 3, 0);
	//pager.drawPager();
	//glPopMatrix();

	//batu start
	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslatef(1, 1, 0);
	batu.drawBatu();
	glScalef(0.7, 0.7, 0);
	batu.drawBatu();
	glPopMatrix();

	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslated(13, 2, 0);
	batu.drawBatu();
	glPopMatrix();

	glPushMatrix();
	glScalef(6, 6, 0);
	glTranslated(1, 6, 0);
	batu.drawBatu();
	glPopMatrix();
	//batu end

	glPushMatrix();
	glTranslatef(150, 80, 0);
	glScalef(3, 3, 0);
	kincir(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(141, 73, 0);
	glScalef(2, 2, 0);
	kincir(2);
	glPopMatrix();
	rotasi++;

	//button ui

	//75, 40, 100, 50
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0, 0.776, 0.929);
	//glColor3f(0.7, 0.7, 0.7);;
	glVertex2f(70,35);
	glVertex2f(105,35);
	glColor3f(1,1,1);;
	glVertex2f(105,55);
	glVertex2f(70,55);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor4f(1, 1, 0, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(30, 30);
	glVertex2f(50, 30);
	glVertex2f(50, 50);
	glVertex2f(30, 50);
	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);
	if (hover)
	{
		glColor3f(0.5, 0.5, 0.5);
	}
	else
	{
		glColor3f(0.9, 0.9, 0.9);
	}
	glVertex2f(playbutton[0], playbutton[1]);
	glVertex2f(playbutton[2], playbutton[1]);
	glVertex2f(playbutton[2], playbutton[3]);
	glVertex2f(playbutton[0], playbutton[3]);
	glEnd();
	glColor3f(0, 0, 0);
	print(78, 44, "Mulai Bermain");
	glLoadIdentity();

	if (change)
	{
		glutDisplayFunc(display);
	}

	glutSwapBuffers();
	glFlush(); //memaksa proses menggambar sampai selesai
}

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, ortho[0], 0.0, ortho[1]); //membuat orto
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); //membersihkan windows
	glColor3f(0.0, 0.0, 0.0); //spesifikasi warna
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	//glEnable(GL_BLEND);

	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project HeheHihi");	
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutMouseFunc(mouse);
	//glutMotionFunc(mousehover);
	glutPassiveMotionFunc(mousehover);
	glutTimerFunc(0, timer, 0);
	glutTimerFunc(0, score, 0);
	glutTimerFunc(0, hamaSpawn, 0);

	glutDisplayFunc(mainMenu);
	myinit();
	glutMainLoop();
	return 0;
}
