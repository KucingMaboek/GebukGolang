#pragma once
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Bimo.h"
#include "Awan.h"
#include "KincirAngin.h"
#include "Batu.h"
#include <string>

extern Bimo bimo;
extern Awan awan;
extern KincirAngin kincirAngin;
extern Batu batu;

class SceneManager
{
public:
	int tombolSelesai[4] = { 75,34,130,39 };
	//page 1
	void defaultScene() {
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

		glPushMatrix();
		glTranslatef(171, 75, 0);
		glTranslatef(-(bimo.rotasi*0.1), 10, 0);
		glScalef(0.3, 0.3, 0);
		glRotatef(bimo.rotasi, 0, 0, 1);
		bimo.drawBimo();
		glPopMatrix();

		//awan start
		glPushMatrix();
		awan.awanPosInit();
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
		kincirAngin.drawKincirAngin(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(141, 73, 0);
		glScalef(2, 2, 0);
		kincirAngin.drawKincirAngin(1);
		glPopMatrix();
		kincirAngin.rotasi++;
		//glutSwapBuffers();
		//glFlush(); //memaksa proses menggambar sampai selesai
	}

	void levelContainer(int curScore, int highScore) {
		char cetakCurScore[1000];
		char cetakHighScore[1000];
		sprintf_s(cetakCurScore, "%d", curScore);
		sprintf_s(cetakHighScore, "%d", highScore);
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor4f(0.6, 0.6, 0.6, 0.9);
		glVertex2f(50, 15);
		glVertex2f(125, 15);
		glColor4f(1, 1, 1, 0.9);
		glVertex2f(125, 70);
		glVertex2f(50, 70);
		glEnd();
		glPopMatrix();
		glColor3f(0, 0, 0);
		print.drawText(95, 64, "Score saat ini:");
		print.drawText(115, 64, cetakCurScore);
		//print.drawText(52, 64, "High Score:");
		//print.drawText(72, 64, cetakHighScore);
	}

	void levelSelectorUI(int x1, int y1, int x2, int y2, int level, bool hoverSwitch, int CurrentScore) {
		char cetakLevel[1000];
		sprintf_s(cetakLevel, "%d", level);
		int gameSpeed[3] = { 1300,800,400 };
		
		glPushMatrix();
		glBegin(GL_POLYGON);
		if (hoverSwitch) { glColor4f(0.7, 0.7, 0.7, 0.9); } else{ glColor4f(1, 1, 1, 0.9); }
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glEnd();
		glColor3f(0, 0, 0);
		print.drawText(x1 + 1, y1 + 10, "Level");
		print.drawText(x1 + 10, y1 + 10, cetakLevel);

		print.drawText(x1+1, y1+2, "Score target:");
		print.drawText(x1+35, y1+6, "Waktu permainan:");
		print.drawText(x1+35, y1+2, "Tingkat kesulitan:");
		switch (level)
		{
			case 3:
				print.drawText(x1 + 59, y1 + 2, "Hard"); //kesulitan
				print.drawText(x1 + 25, y1 + 2, "500"); //score target
				print.drawText(x1 + 59, y1 + 6, "60"); //waktu
				glPushMatrix();
				if (CurrentScore < 2500) {glColor3f(1, 0, 0);} else{glColor3f(0, 0, 0);}
				print.drawText(x1 + 25, y1 + 6, "2500"); //score prasyarat
				print.drawText(x1 + 1, y1 + 6, "Score prasyarat:");
				glPopMatrix(); 
				break;
			case 2:
				print.drawText(x1 + 59, y1 + 2, "Normal"); //kesulitan
				print.drawText(x1 + 25, y1 + 2, "1400"); //score target
				print.drawText(x1 + 59, y1 + 6, "60"); //waktu
				glPushMatrix();
				if (CurrentScore < 900) { glColor3f(1, 0, 0); }
				else { glColor3f(0, 0, 0); }
				print.drawText(x1 + 25, y1 + 6, "900"); //score prasyarat
				print.drawText(x1 + 1, y1 + 6, "Score prasyarat:");
				glPopMatrix();
				break;
			case 1:
				print.drawText(x1 + 59, y1 + 2, "Easy"); //kesulitan
				print.drawText(x1 + 25, y1 + 6, "0"); //score prasyarat
				print.drawText(x1 + 25, y1 + 2, "900"); //score target
				print.drawText(x1 + 59, y1 + 6, "60"); //waktu
				glPushMatrix();
				print.drawText(x1 + 1, y1 + 6, "Score prasyarat:");
				break;
		}

		glPopMatrix();
	}
};