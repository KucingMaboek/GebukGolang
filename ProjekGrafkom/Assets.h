//#include<windows.h>
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#include <string>
//#include <sstream>
//#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#endif
//
//class Assets
//{
//public:
//	void drawCircle(float r, float g, float b) {
//		glTranslatef(10, 10, 0);
//		glColor3f(r, g, b);
//
//		for (int i = 0; i < 360; i++) {
//			glRotated(1, 0, 0, 1);
//			glBegin(GL_POLYGON);
//			glVertex2f(3.1, 0);
//			glVertex2f(0, 0);
//			glVertex2f(0, 3.1);
//			glVertex2f(3.1, 3.1);
//			glEnd();
//		}
//	}
//
//	void batu() {
//		glBegin(GL_POLYGON);
//		glColor3ub(122, 122, 122);
//		glVertex2f(2.19, 0.02);
//		glVertex2f(2.19, 0.27);
//		glColor3ub(74, 74, 74);
//		glVertex2f(2.28, 0.49);
//		glVertex2f(2.54, 0.68);
//		glVertex2f(2.87, 0.7);
//
//		glVertex2f(3.14, 0.59);
//		glColor3f(0, 0, 0);
//		glVertex2f(3.3, 0.4);
//		glVertex2f(3.35, 0.21);
//		glVertex2f(3.35, 0.01);
//		glEnd();
//
//	}
//
//	void bimo() {
//		//BODY
//		glBegin(GL_POLYGON); // BODY 1
//		glColor3f(0.023, 0.482, 0.376);
//		glVertex2d(-5, -5);
//		glVertex2f(-5, 10);
//		glVertex2f(8, 10);
//		glColor3f(0.062, 0.6, 0.482);
//		glVertex2f(8, -5);
//		glEnd();
//		glBegin(GL_POLYGON); //BODY 2
//		glColor3f(0.023, 0.482, 0.376);
//		glVertex2f(-5.5, -4.5);
//		glVertex2f(-5.5, 9.5);
//		glVertex2f(8.5, 9.5);
//		glColor3f(0.062, 0.6, 0.482);
//		glVertex2f(8.5, -4.5);
//		glEnd();
//
//		//FACE
//		glBegin(GL_POLYGON); //muka 1
//		glColor3f(0.4, 0.764, 0.690);
//		glVertex2f(-3.5, 3);
//		glVertex2f(-3.5, 8);
//		glVertex2f(3.5, 8);
//		glVertex2f(3.5, 3);
//		glEnd();
//		glBegin(GL_POLYGON); //muka 2
//		glColor3f(0.4, 0.764, 0.690);
//		glVertex2f(-4, 3.5);
//		glVertex2f(-4, 7.5);
//		glVertex2f(4, 7.5);
//		glVertex2f(4, 3.5);
//		glEnd();
//		glBegin(GL_POLYGON); //mata kiri
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(-2.5, 7);
//		glVertex2f(-2, 7);
//		glVertex2f(-2, 6);
//		glVertex2f(-2.5, 6);
//		glEnd();
//		glBegin(GL_POLYGON); //mata kanan
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(2, 7);
//		glVertex2f(2.5, 7);
//		glVertex2f(2.5, 6);
//		glVertex2f(2, 6);
//		glEnd();
//		glBegin(GL_POLYGON); //mulut
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(-1, 5.5);
//		glVertex2f(1, 5.5);
//		glVertex2f(1, 5);
//		glVertex2f(-1, 5);
//		glEnd();
//		glBegin(GL_POLYGON); //pipi kiri
//		glColor3f(0.517, 0.823, 0.768);
//		glVertex2f(-3.5, 5.5);
//		glVertex2f(-3, 5.5);
//		glVertex2f(-3, 5);
//		glVertex2f(-3.5, 5);
//		glEnd();
//		glBegin(GL_POLYGON); //pipi kanan
//		glColor3f(0.517, 0.823, 0.768);
//		glVertex2f(3, 5.5);
//		glVertex2f(3.5, 5.5);
//		glVertex2f(3.5, 5);
//		glVertex2f(3, 5);
//		glEnd();
//
//		//detail badan
//		glBegin(GL_POLYGON);//detail 1
//		glColor3f(0.145, 0.254, 0.196);
//		glVertex2f(-4, 2);
//		glVertex2f(1, 2);
//		glVertex2f(1, 1.5);
//		glVertex2f(-4, 1.5);
//		glEnd();
//		glBegin(GL_POLYGON);//detail 2
//		glColor3f(0.039, 0.078, 0.450);
//		glVertex2f(3, 2);
//		glVertex2f(3.5, 2);
//		glVertex2f(3.5, 1.5);
//		glVertex2f(3, 1.5);
//		glEnd();
//		glBegin(GL_POLYGON);//detail 3
//		glColor3f(0.686, 0.835, 0.164);
//		glVertex2d(-3, 0.5);
//		glVertex2f(-2.5, 0.5);
//		glVertex2f(-2.5, -1);
//		glVertex2f(-3, -1);
//		glEnd();
//		glBegin(GL_POLYGON);//detail 3.5
//		glColor3f(0.686, 0.835, 0.164);
//		glVertex2f(-3.5, 0);
//		glVertex2f(-2, 0);
//		glVertex2f(-2, -0.5);
//		glVertex2f(-3.5, -0.5);
//		glEnd();
//		glBegin(GL_POLYGON);//detail 4
//		glColor3f(0.254, 0.639, 0.745);
//		glVertex2f(1.5, 0);
//		glVertex2f(2, 0);
//		glVertex2f(2, -0.5);
//		glVertex2f(1.5, -0.5);
//		glEnd();
//		glBegin(GL_POLYGON);//detail 4.5
//		glColor3f(0.254, 0.639, 0.745);
//		glVertex2f(1, -0.5);
//		glVertex2f(2.5, -0.5);
//		glVertex2f(2.5, -1);
//		glVertex2f(1, -1);
//		glEnd();
//		glBegin(GL_POLYGON); //detail 5
//		glColor3f(0.031, 0.533, 0.309);
//		glVertex2f(3, 0);
//		glVertex2f(4, 0);
//		glVertex2f(4, -1);
//		glVertex2f(3, -1);
//		glEnd();
//		glBegin(GL_POLYGON); //detail 6
//		glColor3f(0.039, 0.078, 0.450);
//		glVertex2f(-4, -2.5);
//		glVertex2f(-3, -2.5);
//		glVertex2f(-3, -3);
//		glVertex2f(-4, -3);
//		glEnd();
//		glBegin(GL_POLYGON); //detail 7
//		glColor3f(0.039, 0.078, 0.450);
//		glVertex2f(-2.5, -2.5);
//		glVertex2f(-1.5, -2.5);
//		glVertex2f(-1.5, -3);
//		glVertex2f(-2.5, -3);
//		glEnd();
//		glBegin(GL_POLYGON); //detail 8
//		glColor3f(0.666, 0.113, 0.078);
//		glVertex2f(1.5, -2);
//		glVertex2f(2.5, -2);
//		glVertex2f(2.5, -3);
//		glVertex2f(1.5, -3);
//
//		glEnd();
//
//		//detail body 2
//		glBegin(GL_LINES);
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(5, -5);
//		glVertex2f(5, 10);
//		glEnd();
//		glBegin(GL_POLYGON);//lubang 1
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(6, 9);
//		glVertex2f(6.5, 9);
//		glVertex2f(6.5, 8.5);
//		glVertex2f(6, 8.5);
//		glEnd();
//		glBegin(GL_POLYGON);//lubang 2
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(7, 9);
//		glVertex2f(7.5, 9);
//		glVertex2f(7.5, 8.5);
//		glVertex2f(7, 8.5);
//		glEnd();
//		glBegin(GL_POLYGON);//lubang 3
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(5.5, 8);
//		glVertex2f(6, 8);
//		glVertex2f(6, 7.5);
//		glVertex2f(5.5, 7.5);
//		glEnd();
//		glBegin(GL_POLYGON); //lubang 4
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(6.5, 8);
//		glVertex2f(7, 8);
//		glVertex2f(7, 7.5);
//		glVertex2f(6.5, 7.5);
//		glEnd();
//		glBegin(GL_POLYGON); //lubang 5
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(7.5, 8);
//		glVertex2f(8, 8);
//		glVertex2f(8, 7.5);
//		glVertex2f(7.5, 7.5);
//		glEnd();
//		glBegin(GL_POLYGON); //lubang 6
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(6, 7);
//		glVertex2f(6.5, 7);
//		glVertex2f(6.5, 6.5);
//		glVertex2f(6, 6.5);
//		glEnd();
//		glBegin(GL_POLYGON); //lubang 7
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(7, 7);
//		glVertex2f(7.5, 7);
//		glVertex2f(7.5, 6.5);
//		glVertex2f(7, 6.5);
//		glEnd();
//		glBegin(GL_POLYGON); //bahu 1
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(5.7, 1.7);
//		glVertex2f(7.3, 1.7);
//		glVertex2f(7.3, 1.5);
//		glVertex2f(5.7, 1.5);
//		glEnd();
//		glBegin(GL_POLYGON); //bahu 2
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(5.5, 1.5);
//		glVertex2f(7.5, 1.5);
//		glVertex2f(7.5, 1.3);
//		glVertex2f(5.5, 1.3);
//		glEnd();
//
//		//tangan kaki
//		glBegin(GL_POLYGON); //tangan kanan
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(6, 1.5);
//		glVertex2f(7, 1.5);
//		glVertex2f(7, -7);
//		glVertex2f(6, -7);
//		glEnd();
//		glBegin(GL_POLYGON); //tangan kiri
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(-5, -5);
//		glVertex2f(-4, -5);
//		glVertex2f(-4, -7);
//		glVertex2f(-5, -7);
//		glEnd();
//		glBegin(GL_POLYGON); //kaki kiri 1
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(-3, -5);
//		glVertex2f(-2, -5);
//		glVertex2f(-2, -9);
//		glVertex2f(-3, -9);
//		glEnd();
//		glBegin(GL_POLYGON); //kaki kiri 2
//		glColor3f(0.098, 0.301, 0.254);
//		glVertex2f(-4, -9);
//		glVertex2f(-2, -9);
//		glVertex2f(-2, -10);
//		glVertex2f(-4, -10);
//		glEnd();
//		glBegin(GL_POLYGON); //kaki kanan 1
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(4, -5);
//		glVertex2f(5, -5);
//		glVertex2f(5, -9);
//		glVertex2f(4, -9);
//		glEnd();
//		glBegin(GL_POLYGON); //kaki kanan 2
//		glColor3f(0.031, 0.462, 0.364);
//		glVertex2f(3, -9);
//		glVertex2f(5, -9);
//		glVertex2f(5, -10);
//		glVertex2f(3, -10);
//		glEnd();
//	}
//
//	void awan() {
//		glPushMatrix();
//		glScalef(1, 0.5, 0);
//		drawCircle(1, 1, 1);
//		glPopMatrix();
//		glPushMatrix();
//		glTranslatef(2, 2, 0);
//		glScalef(1, 0.5, 0);
//		drawCircle(1, 1, 1);
//		glPopMatrix();
//		glPushMatrix();
//		glTranslatef(3, -1.5, 0);
//		glScalef(1, 0.5, 0);
//		drawCircle(1, 1, 1);
//		glPopMatrix();
//		glPushMatrix();
//		glTranslatef(7, -1, 0);
//		glScalef(1, 0.5, 0);
//		drawCircle(1, 1, 1);
//		glPopMatrix();
//		glPushMatrix();
//		glTranslatef(6, 0.5, 0);
//		glScalef(1, 0.5, 0);
//		drawCircle(1, 1, 1);
//		glPopMatrix();
//	}
//
//
//	void baling() {
//		glBegin(GL_POLYGON);
//		glColor3ub(248, 156, 50);
//		glVertex2f(4.54, 4.36);
//		glVertex2f(4.25, 0.85);
//		glColor3ub(153, 87, 54);
//		glVertex2f(5.67, 0.39);
//		glVertex2f(5.42, 4.4);
//		glEnd();
//	}
//	void kincirAngin(float kecepatanRotasi) {
//		glPushMatrix();
//		if (waktu > 0)
//		{
//			glRotatef(rotasi*kecepatanRotasi, 0, 0, 1);
//		}
//		glTranslatef(-5, -5, 0);
//		glColor3f(1, 0, 0);
//		glPushMatrix();
//		baling();
//		glPopMatrix();
//		glPushMatrix();
//		glRotatef(90, 0, 0, 1);
//		glTranslatef(0, -10, 0);
//		baling();
//		glPopMatrix();
//		glPushMatrix();
//		glRotatef(180, 0, 0, 1);
//		glTranslatef(-10, -10, 0);
//		baling();
//		glPopMatrix();
//		glPushMatrix();
//		glRotatef(270, 0, 0, 1);
//		glTranslatef(-10, 0, 0);
//		baling();
//		glPopMatrix();
//
//		glPushMatrix();
//		glTranslatef(3.4, 3.4, 0);
//		glScalef(0.16, 0.16, 0);
//		drawCircle(0.957, 0.718, 0.325);
//		glPopMatrix();
//
//		glPopMatrix();
//	}
//	void kincir(float kecepatanRotasi) {
//		glPushMatrix();
//		glTranslatef(-5, -6.3, 0);
//		//bangunan utama
//		glPushMatrix();
//		glColor3f(1, 0, 1);
//		glBegin(GL_POLYGON);
//		glColor3ub(237, 50, 55);
//		glVertex2f(2, 0);
//		glVertex2f(2.5, 4);
//		glVertex2f(3, 10);
//		glColor3ub(101, 45, 13);
//		glVertex2f(7, 10);
//		glVertex2f(7.5, 4);
//		glVertex2f(8, 0);
//		glEnd();
//		glPopMatrix();
//		//pintu
//		glPushMatrix();
//		glBegin(GL_POLYGON);
//		glColor3ub(66, 2, 0);
//		glVertex2f(4, 0);
//		glVertex2f(6, 0);
//		glColor3ub(36, 0, 0);
//		glVertex2f(6, 3);
//		glVertex2f(4, 3);
//		glEnd();
//		glPopMatrix();
//		//gelang
//		glColor3f(0, 0, 0);
//		glPushMatrix();
//		glBegin(GL_POLYGON);
//		glColor3ub(211, 203, 57);
//		glVertex2f(2.2, 3.8);
//		glVertex2f(7.8, 3.8);
//		glColor3ub(245, 136, 52);
//		glVertex2f(7.8, 4.2);
//		glVertex2f(2.2, 4.2);
//		glEnd();
//		glPopMatrix();
//		//atap
//		glPushMatrix();
//		glBegin(GL_POLYGON);
//		glColor3ub(238, 165, 52);
//		glVertex2f(1, 8);
//		glVertex2f(9, 8);
//		glColor3ub(123, 81, 50);
//		glVertex2f(5, 12);
//		glEnd();
//		glPopMatrix();
//		glPopMatrix();
//		//kincir
//		glPushMatrix();
//		kincirAngin(kecepatanRotasi);
//		glPopMatrix();
//	}
//
//
//	void hama(int spawn) {
//		//hama
//		if (spawn == 1) {
//			glColor3ub(105, 215, 228);
//			glPushMatrix(); //telinga kiri
//			glBegin(GL_POLYGON);
//			glVertex2f(2, 3.88);
//			glVertex2f(1.83, 3.96);
//			glVertex2f(1.68, 3.98);
//			glVertex2f(1.47, 3.93);
//			glVertex2f(1.27, 3.82);
//			glVertex2f(1.14, 3.59);
//			glVertex2f(1.13, 3.42);
//			glVertex2f(1.18, 3.25);
//			glVertex2f(1.32, 3.13);
//			glVertex2f(1.66, 2.99);
//			glVertex2f(1.93, 3.42);
//			glVertex2f(2.09, 3.75);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); // telinga kiri dalam
//			glScalef(0.05, 0.05, 0);
//			glTranslatef(23, 60, 0);
//			drawCircle(0, 0, 0);
//			glPopMatrix();
//
//			glColor3ub(105, 215, 228);
//			glPushMatrix(); //telinga kanan
//			glBegin(GL_POLYGON);
//			glVertex2f(5.42, 3.97);
//			glVertex2f(5.73, 4.09);
//			glVertex2f(6.01, 4.04);
//			glVertex2f(6.22, 3.89);
//			glVertex2f(6.3, 3.64);
//			glVertex2f(6.29, 3.41);
//			glVertex2f(5.81, 3.11);
//			glVertex2f(5.42, 3.51);
//			glVertex2f(5.29, 3.83);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); //telinga kanan dalam
//			glScalef(0.05, 0.05, 0);
//			glTranslatef(105, 62, 0);
//			drawCircle(0, 0, 0);
//			glPopMatrix();
//
//			glColor3ub(105, 215, 228);
//			glPushMatrix(); //badan
//			glBegin(GL_POLYGON);
//			glVertex2f(1.39, 0); //c
//			glVertex2f(1.43, 0.45); //d
//			glVertex2f(1.43, 0.91); //e
//			glVertex2f(1.41, 1.44); //f
//			glVertex2f(1.38, 2.0l); //g
//			glVertex2f(1.42, 2.49); //h
//			glVertex2f(1.52, 3.04); //i
//			glVertex2f(1.73, 3.55); //j
//			glVertex2f(2.16, 3.97); //k
//			glVertex2f(2.67, 4.21); //l
//			glVertex2f(3.25, 4.34); //m
//			glVertex2f(3.9, 4.39); //n
//			glVertex2f(4.51, 4.35); //o
//			glVertex2f(5.22, 4.14); //p
//			glVertex2f(5.67, 3.69); //q
//			glVertex2f(5.93, 3.15); //r
//			glVertex2f(6, 2.72); //s
//			glVertex2f(6.09, 2.1); //t
//			glVertex2f(6.13, 1.49); //u
//			glVertex2f(6.14, 0.94); //v
//			glVertex2f(6.18, 0.37); //w
//			glVertex2f(6.18, 0);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); //mata kiri
//			glTranslatef(1.3, 1.9, 0);
//			glScalef(0.15, 0.14, 0);
//			drawCircle(1, 1, 1);
//			glPopMatrix();
//
//			glPushMatrix(); //mata kanan
//			glTranslatef(3.2, 1.9, 0);
//			glScalef(0.15, 0.14, 0);
//			drawCircle(1, 1, 1);
//			glPopMatrix();
//
//			glPushMatrix(); //pupil kiri
//			glTranslatef(3.85, 2.6, 0);
//			glScalef(0.06, 0.06, 0);
//			drawCircle(0, 0, 0);
//			glPopMatrix();
//
//			glPushMatrix(); //pupil kanan
//			glTranslatef(1.95, 2.6, 0);
//			glScalef(0.06, 0.06, 0);
//			drawCircle(0, 0, 0);
//			glPopMatrix();
//
//			glPushMatrix(); //gigi kiri
//			glColor3f(1, 1, 1);
//			glBegin(GL_POLYGON);
//			glVertex2f(3.38, 2.2);
//			glVertex2f(3.37, 2.13);
//			glVertex2f(3.37, 2.08);
//			glVertex2f(3.38, 2.02);
//			glVertex2f(3.4, 1.96);
//			glVertex2f(3.43, 1.91);
//			glVertex2f(3.48, 1.87);
//			glVertex2f(3.53, 1.84);
//			glVertex2f(3.61, 1.86);
//			glVertex2f(3.66, 1.9);
//			glVertex2f(3.7, 1.96);
//			glVertex2f(3.71, 2.07);
//			glVertex2f(3.72, 2.14);
//			glVertex2f(3.72, 2.23);
//			glVertex2f(3.7, 2.4);
//			glVertex2f(3.56, 2.38);
//			glVertex2f(3.46, 2.33);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); //gigi kanan
//			glColor3f(1, 1, 1);
//			glTranslatef(0.35, 0, 0);
//			glBegin(GL_POLYGON);
//			glVertex2f(3.28, 2.2);
//			glVertex2f(3.37, 2.13);
//			glVertex2f(3.37, 2.08);
//			glVertex2f(3.38, 2.02);
//			glVertex2f(3.4, 1.96);
//			glVertex2f(3.43, 1.91);
//			glVertex2f(3.48, 1.87);
//			glVertex2f(3.53, 1.84);
//			glVertex2f(3.61, 1.86);
//			glVertex2f(3.66, 1.9);
//			glVertex2f(3.7, 1.96);
//			glVertex2f(3.71, 2.07);
//			glVertex2f(3.72, 2.14);
//			glVertex2f(3.72, 2.23);
//			glVertex2f(3.7, 2.4);
//			glVertex2f(3.56, 2.38);
//			glVertex2f(3.46, 2.33);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); //bibir
//			glColor3ub(252, 213, 164);
//			glBegin(GL_POLYGON);
//			glVertex2f(3.5, 2.7);
//			glVertex2f(3.32, 2.64);
//			glVertex2f(3.2, 2.52);
//			glVertex2f(3.17, 2.38);
//			glVertex2f(3.26, 2.28);
//			glVertex2f(3.39, 2.24);
//			glVertex2f(3.51, 2.27);
//			glVertex2f(3.67, 2.32);
//			glVertex2f(3.73, 2.34);
//			glVertex2f(3.81, 2.32);
//			glVertex2f(3.89, 2.3);
//			glVertex2f(3.99, 2.26);
//			glVertex2f(4.12, 2.22);
//			glVertex2f(4.22, 2.25);
//			glVertex2f(4.29, 2.3);
//			glVertex2f(4.33, 2.37);
//			glVertex2f(4.34, 2.45);
//			glVertex2f(4.26, 2.57);
//			glVertex2f(4.13, 2.65);
//			glVertex2f(4.01, 2.71);
//			glVertex2f(3.74, 2.73);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix(); //hidung
//			glTranslatef(3.05, 2.17, 0);
//			glScalef(0.07, 0.05, 0);
//			drawCircle(0, 0, 0);
//			glPopMatrix();
//		}
//
//		//bom
//		if (spawn == 0)
//		{
//			glPushMatrix();
//			glRotatef(30, 0, 0, 1);
//			glTranslatef(1, -2, 0);
//
//			glPushMatrix();
//			glTranslatef(3.25, 4, 0);
//			glColor3ub(224, 138, 53);
//			glBegin(GL_POLYGON);
//			glVertex2f(0.2, 0);
//			glVertex2f(0.8, 0);
//			glVertex2f(0.8, 1.5);
//			glVertex2f(0.2, 1.5);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix();
//			glTranslatef(3.25, 4, 0);
//			glColor3f(0.15, 0.15, 0.15);
//			glBegin(GL_POLYGON);
//			glVertex2f(-0.2, 0);
//			glVertex2f(1.2, 0);
//			glVertex2f(1.2, 1);
//			glVertex2f(-0.2, 1);
//			glEnd();
//			glPopMatrix();
//
//			glPushMatrix();
//			glScalef(0.5, 0.5, 0);
//			glTranslatef(-2.5, -5, 0);
//			drawCircle(0.15, 0.15, 0.15);
//			glPopMatrix();
//
//			glPopMatrix();
//		}
//	}
//
//	void petak(char *id) {
//		glColor3ub(121, 60, 47);
//		glBegin(GL_POLYGON);
//		glVertex2f(0, 0);
//		glVertex2f(10, 0);
//		glColor3ub(224, 138, 53);
//		glVertex2f(10, 10);
//		glVertex2f(0, 10);
//		glEnd();
//		glPushMatrix();
//		glTranslatef(-5, 2, 0);
//		glScalef(1, 0.3, 0);
//		drawCircle(0, 0, 0);
//		glPopMatrix();
//		glColor3f(1, 1, 1);
//		print(1, 1, id);
//	}
//	void ladang() {
//		int i;
//		int a;
//		int x = 0;
//		int idpetak = 0;
//		char cetak[1000];
//		for (i = 1; i <= 3; i++) { //atas
//			glTranslatef(0, 11, 0);
//			x = 0;
//			for (a = 1; a <= 3; a++) { //samping ke kanan
//				idpetak++;
//				sprintf_s(cetak, "%d", idpetak);
//				glPushMatrix();
//				glTranslatef(x, 0, 0);
//				petak(cetak);
//				x += 11;
//				glPopMatrix();
//			}
//		}
//	}
//};