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
#include<string>
#include<sstream>
#endif

#include <stdlib.h>


GLfloat angle = 1;
int refreshmill = 1;
void *font = GLUT_BITMAP_HELVETICA_12;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;
void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshmill, timer, 0);
}
void tulis2(int x, int y, char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font2, string[i]);
	}
}
void palu() {
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
void pager() {
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
void drawCircle(int r, int g, int b) {
	glTranslatef(10, 10, 0);
	glColor3f(r, g, b);
	double  PI = 3.141592654;
	double angle = 0.0;
	int points = 100;

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
void hama() {
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
void petak(int id) {

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
	tulis2(0.5, 1, "id");
}
void ladang() {
	int i;
	int a;
	int x = 0;
	int idpetak = 0;
	for (i = 1; i <= 3; i++) { //atas
		glTranslatef(0, 11, 0);
		x = 0;
		for (a = 1; a <= 3; a++) { //samping ke kanan
			idpetak += 1;
			glPushMatrix();
			glTranslatef(x, 0, 0);
			petak(idpetak);
			x += 11;
			glPopMatrix();
		}
	}
}
void batu() {
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
void bom() {
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glScalef(2, 2, 0);
	glTranslatef(1.5, 1.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(4.44, 5.5);
	glVertex2f(4.4, 5.65);
	glVertex2f(4.38, 5.89);
	glVertex2f(4.28, 6.01);
	glVertex2f(4.08, 6.11);
	glVertex2f(3.68, 6.11);
	glVertex2f(3.22, 6.07);
	glVertex2f(2.76, 6);
	glVertex2f(2.32, 5.86);
	glVertex2f(1.96, 5.52);
	glVertex2f(2.04, 5.67);
	glVertex2f(1.98, 5.33);
	glVertex2f(2.07, 5.09);
	glVertex2f(2.67, 4.98);
	glVertex2f(3.26, 4.91);
	glVertex2f(4.08, 5.17);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	drawCircle(0, 0, 0);
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.9, 0.9, 0.9, 0);
	glScalef(2.5, 2.5, 0);
	glTranslatef(1, 0.7, 0);
	glBegin(GL_POLYGON);
	glVertex2f(2.01, 4.26);
	glVertex2f(1.74, 3.96);
	glVertex2f(1.65, 3.65);
	glVertex2f(1.63, 3.37);
	glVertex2f(1.66, 3.06);
	glVertex2f(1.72, 2.82);
	glVertex2f(1.86, 2.59);
	glVertex2f(2.04, 2.41);
	glVertex2f(2.23, 2.42);
	glVertex2f(2.35, 2.57);
	glVertex2f(2.2, 2.74);
	glVertex2f(2.13, 2.88);
	glVertex2f(2.04, 3.1);
	glVertex2f(2.02, 3.34);
	glVertex2f(2.02, 3.59);
	glVertex2f(2.12, 3.82);
	glVertex2f(2.34, 4.05);
	glVertex2f(2.34, 4.24);
	glVertex2f(2.21, 4.32);
	glEnd();
	glPopMatrix();
}

bool muter = true;
void display() {
	glClearColor(0, 0.776, 0.929, 1);
	glClear(GL_COLOR_BUFFER_BIT); //menghapus windows dan memberi warna yang ada di glclearcolor
	glLoadIdentity();

	//0.0,171,0.0,91

	glBegin(GL_POLYGON); //langit
	glColor3f(0, 0.776, 0.929);
	glVertex2f(0, 70);
	glVertex2f(171, 70);
	glColor3ub(199, 255, 242);
	glVertex2f(171, 91);
	glVertex2f(0, 91);
	glEnd();

	//awan start
	glPushMatrix();
	glTranslatef(20, 80, 0);
	glScalef(1, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(40, 70, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(70, 80, 0);
	glScalef(2, 1, 0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(120, 75, 0);
	glScalef(1.7, 1, 0);
	awan();
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
	pager();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(90, 65, 0);
	glScalef(3, 3, 0);
	pager();
	glPopMatrix();

	glPushMatrix();
	glScalef(3, 3, 0);
	glTranslatef(19.2, 18, 0);
	hama();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.7, 1.7, 0);
	glTranslatef(48, 34, 0);
	glRotatef(angle, 0, 0, 1);
	palu();
	glPopMatrix();

	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslatef(1, 1, 0);
	batu();
	glScalef(0.7, 0.7, 0);
	batu();
	glPopMatrix();

	glPushMatrix();
	glScalef(10, 10, 0);
	glTranslated(13, 2, 0);
	batu();
	glPopMatrix();

	glPushMatrix();
	glScalef(6, 6, 0);
	glTranslated(1, 6, 0);
	batu();
	glPopMatrix();
	/*
	glPushMatrix();
	bom();
	glPopMatrix();
	*/
	//UI
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(2, 90);
	glVertex2f(30, 90);
	glColor3ub(222, 222, 222);
	glVertex2f(30, 80);
	glVertex2f(2, 80);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(2, 90);
	glVertex2f(30, 90);
	glVertex2f(30, 80);
	glVertex2f(2, 80);
	glEnd();
	glPopMatrix();
	glColor3f(0, 0, 0);
	//tulis2(3, 86, "Score :");
	//tulis2(3, 82, "Sisa Waktu :");
	if (angle == 45) {
		muter = false;
	}
	if (angle == 0) {
		muter = true;
	}
	if (muter == true) {
		angle += 1;
	}
	if (muter == false) {
		angle -= 1;
	}

	glutSwapBuffers();
	glFlush(); //memaksa proses menggambar sampai selesai
}

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 171, 0.0, 91); //membuat orto
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); //membersihkan windows
	glColor3f(0.0, 0.0, 0.0); //spesifikasi warna
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project HeheHihi");
	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
