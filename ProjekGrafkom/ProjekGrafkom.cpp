/*
 GLUT WHACK A MOLE GAMES, "Gebuk Golang"
 WRITTEN BY kucingmaboek
 DO NOT COPY,CITE,OR DISTRIBUTE WITHOUT
 PERMISSION OF THE AUTHOR
 */

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//GameObject
#include "Circle.h"
#include "Bimo.h"
#include "Batu.h"
#include "Pager.h"
#include "KincirAngin.h"
#include "Palu.h"
#include "Awan.h"
#include "Printer.h"
#include "Ladang.h"
#include "Hama.h"
#include "HighScore.h"
#include "SceneManager.h"
using namespace std;

Bimo bimo;
Batu batu;
Pager pager;
Circle circle;
Palu palu;
Awan awan;
Printer print;
KincirAngin kincirAngin;
Ladang ladang;
Hama hama;
SceneManager scene;
HighScore highScore;
//GameObject end

char line[1000];
int currentScore, targetScore;
int koordinat, koordinat1, koordinatPalu;
int totalScore,scoreLevel1,scoreLevel2,scoreLevel3; //score controller

int waktu = 9999, randSpawn, spawnTime;
int playLevel; //value 1,2,3
float paluX = 50;
float paluY = 10;
float speedPalu = 1;
float effectOpacity;
float ortho[2] = { 171,91 }; //ortho
float paluPosXY[10][2] = { {200,200}, {34.1,5.5}, {42.1,5.5}, {50,5.5}, {34.1,13.5}, {42.1,13.5}, {50,13.5}, {34.1,21.5}, {42.1,21.5}, {50,21.5} };
float hamaPosXY[10][2] = { {200,200}, {19.2,4.8}, {25.8, 4.8}, { 32.4, 4.8 }, {19.2,11.4}, { 25.8,11.4 }, { 32.4,11.4 },  {19.2,18},  { 25.8,18 },   { 32.4,18 } };
float PosX, PosY, PosX1, PosY1; //hama current position
char cetakwaktu[1000];
char cetaktarget[1000];
char cetakscore[1000];
char numpad[1000] = "On";
bool numpadtoggle = true;
bool paluGerak = true;
bool change,change1; //display control
bool onLevelSelectUI,onGameUI; 
//collision
int level1[5] = { 52, 48, 123, 63, 1 };
int level2[5] = { 52, 32, 123, 47, 2 };
int level3[5] = { 52, 17, 123, 31, 3 };
int playbutton[4] = { 75, 40, 100, 50 }; //x1,y1,x2,y2
int tombolSelesai[4] = { 75,34,130,39 };

bool hover,selesaiHover; //hover control, tombol selesai hover control
bool level1Hover,level2Hover,level3Hover; 
//collision end




void update(int value) {
	awan.awanMove();
	kincirAngin.muter = true;
	bimo.bimoMuter();
	//SceneController();
	//if (waktu > 0)
	//{
	//	//awan.awanMove();
	//	//kincirAngin.muter = true;
	//}
	//else {
	//	kincirAngin.muter = false;
	//}
	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}
void gameTime(int value) {
	if (change1)
	{
		if (waktu > 0)
		{
			waktu--;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(1000, gameTime, 0);
}
void hamaSpawn(int value) {
	randSpawn = rand() % 2;
		koordinat = rand() % 10;
		koordinat1 = rand() % 10;
		if (koordinat == koordinat1)
		{
			koordinat1 = 0;
		}
		PosX = hamaPosXY[koordinat][0];
		PosY = hamaPosXY[koordinat][1];
		PosX1 = hamaPosXY[koordinat1][0];
		PosY1 = hamaPosXY[koordinat1][1];

		glutPostRedisplay();
		glutTimerFunc(spawnTime, hamaSpawn, 0);
	if (waktu > 0) {
	}
}


void hamaReset(int koor) {
	if (koor == 0)
	{
		koordinat = 0;
		PosX = hamaPosXY[0][0];
		PosY = hamaPosXY[0][1];
		if (randSpawn == 0)
		{
			currentScore -= 50;
			effectOpacity = 1;
		}
		else
		{
			currentScore += 20;
		}
	}
	if (koor == 1)
	{
		koordinat1 = 0;
		PosX1 = hamaPosXY[0][0];
		PosY1 = hamaPosXY[0][1];
		currentScore += 20;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'c') {
		change = true;
	}
	if (waktu > 0) {
		if (key == 13) { //32
			palu.angle = 90;
			paluGerak = false;
		}
		if (numpadtoggle == true) {
			if (key == '1') {
				paluX = paluPosXY[1][0];
				paluY = paluPosXY[1][1];
				koordinatPalu = 1;
				palu.angle = 90;
			}
			if (key == '2') {
				paluX = paluPosXY[2][0];
				paluY = paluPosXY[2][1];
				koordinatPalu = 2;
				palu.angle = 90;
			}
			if (key == '3') {
				paluX = paluPosXY[3][0];
				paluY = paluPosXY[3][1];
				koordinatPalu = 3;
				palu.angle = 90;
			}
			if (key == '4') {
				paluX = paluPosXY[4][0];
				paluY = paluPosXY[4][1];
				koordinatPalu = 4;
				palu.angle = 90;
			}
			if (key == '5') {
				paluX = paluPosXY[5][0];
				paluY = paluPosXY[5][1];
				koordinatPalu = 5;
				palu.angle = 90;
			}
			if (key == '6') {
				paluX = paluPosXY[6][0];
				paluY = paluPosXY[6][1];
				koordinatPalu = 6;
				palu.angle = 90;
			}
			if (key == '7') {
				paluX = paluPosXY[7][0];
				paluY = paluPosXY[7][1];
				koordinatPalu = 7;
				palu.angle = 90;
			}
			if (key == '8') {
				paluX = paluPosXY[8][0];
				paluY = paluPosXY[8][1];
				koordinatPalu = 8;
				palu.angle = 90;
			}
			if (key == '9') {
				paluX = paluPosXY[9][0];
				paluY = paluPosXY[9][1];
				koordinatPalu = 9;
				palu.angle = 90;
			}
		}
	}
}


void mousehover(int mousex, int mousey) {
	int mousexHoverPos = mousex / 8;
	int mouseyHoverPos = 91-(mousey / 8);
	//printf("%i current mouse x position \n", mousexHoverPos);
	//printf("%i current mouse y position \n", mouseyHoverPos);
	
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
		if (mouseyHoverPos >= playbutton[1] && mouseyHoverPos <= playbutton[3]){hover = true;}
		else{hover = false;}
	}
	else{hover = false;}

	if (mousexHoverPos >= level1[0] && mousexHoverPos <= level1[2])
	{
		if (mouseyHoverPos >= level1[1] && mouseyHoverPos <= level1[3]) { level1Hover = true; }
		else { level1Hover = false; }
		if (mouseyHoverPos >= level2[1] && mouseyHoverPos <= level2[3]) { level2Hover = true; }
		else { level2Hover = false; }
		if (mouseyHoverPos >= level3[1] && mouseyHoverPos <= level3[3]) { level3Hover = true; }
		else { level3Hover = false; }
	}
	else { level1Hover = false; level2Hover = false; level3Hover = false;}

	if (mousexHoverPos >= tombolSelesai[0] && mousexHoverPos <= tombolSelesai[2])
	{
		if (mouseyHoverPos >= tombolSelesai[1] && mouseyHoverPos <= tombolSelesai[3]) { selesaiHover = true; }
		else { selesaiHover = false; }
	}
	else { selesaiHover = false; }

	glutPostRedisplay();
}

void selectedLevel(int level) {
	change1 = true;
	switch (level)
	{
	case 1:
		//waktu = 5;
		waktu = 60;
		spawnTime = 1300;
		currentScore = 0;
		playLevel = 1;
		targetScore = 900;
		break;
	case 2:
		waktu = 60;
		spawnTime = 1000;
		currentScore = 0;
		playLevel = 2;
		targetScore = 1400;
		break;
	case 3:
		waktu = 60;
		spawnTime = 600;
		currentScore = 0;
		playLevel = 3;
		targetScore = 500;
		break;
	}
	
}
void mouse(int button, int state, int mousex, int mousey) {
	int mousexPos = mousex / 8;
	int mouseyPos = 91-(mousey / 8);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_ENTERED && mousexPos >= playbutton[0] && mousexPos <= playbutton[2])
	{
		printf("%i posisi mouse x\n", mousexPos);
		printf("%i posisi mouse y\n", mouseyPos);
		if (mouseyPos >= playbutton[1] && mouseyPos <= playbutton[3]){change = true;}
	}

	if (onLevelSelectUI)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_ENTERED && mousexPos >= level1[0] && mousexPos <= level1[2])
		{
			printf("%i posisi mouse x\n", mousexPos);
			printf("%i posisi mouse y\n", mouseyPos);
			if (mouseyPos >= level1[1] && mouseyPos <= level1[3]) 
			{ 
				selectedLevel(1);
			}
			if (mouseyPos >= level2[1] && mouseyPos <= level2[3])
			{
				if (totalScore >= 900)
				{
				selectedLevel(2);

				}
			}
			if (mouseyPos >= level3[1] && mouseyPos <= level3[3])
			{
				if (totalScore >= 2500) {
				selectedLevel(3);

				}
			}
		}

	}

	if (onGameUI)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_ENTERED && mousexPos >= tombolSelesai[0] && mousexPos <= tombolSelesai[2])
		{
			printf("%i posisi mouse x\n", mousexPos);
			printf("%i posisi mouse y\n", mouseyPos);
			if (mouseyPos >= tombolSelesai[1] && mouseyPos <= tombolSelesai[3]) { change = true; }
		}
		onGameUI = false;
	}

	glutPostRedisplay();
}

void keyboardup(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);
	}
	if (waktu > 0) {
		if (key == 13) {
			palu.angle = 15;
			paluGerak = true;
		}
		if (key == 'o')
		{
			numpadtoggle = !numpadtoggle;
			if (numpadtoggle == true)
			{
				//visual studio user use this
				sprintf_s(numpad, "On");

				//codeblock user use this
				//sprintf(numpad, "On");
			}
			else
			{
				//visual studio user use this
				sprintf_s(numpad, "Off");

				//codeblock user use this
				//sprintf(numpad, "Off");
			}
		}
		
		//numpad
		if (numpadtoggle == true) {
			if (key == '1') {
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
				palu.angle = 15;
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
			if (GetAsyncKeyState(VK_UP) && paluGerak == true){paluY += speedPalu;}
			if (GetAsyncKeyState(VK_DOWN) && paluGerak == true){paluY -= speedPalu;}
			if (GetAsyncKeyState(VK_RIGHT) && paluGerak == true){paluX += speedPalu;}
			if (GetAsyncKeyState(VK_LEFT) && paluGerak == true){paluX -= speedPalu;}
		}
	}
}

// page 3
void display() {
	onLevelSelectUI = false;

	//visual studio user use this 
	sprintf_s(cetakwaktu, "%d", waktu);
	sprintf_s(cetakscore, "%d", currentScore);
	sprintf_s(cetaktarget, "%d", targetScore);

	//codeblock user use this
	//sprintf(cetakwaktu, "%d", waktu);
	//sprintf(cetakscore, "%d", currentScore);
	//sprintf(cetaktarget, "%d", targetScore);

	scene.defaultScene();

	glPushMatrix();
	glTranslatef(60, -15, 0);
	glScalef(1.8, 1.8, 0);
	ladang.drawLadang();
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

	if (waktu > 0)
	{
		//hama start
		glPushMatrix();
		glScalef(3, 3, 0);
		glTranslatef(PosX, PosY, 0);
		hama.drawHama(randSpawn);
		glPopMatrix();

		glPushMatrix();
		glScalef(3, 3, 0);
		glTranslatef(PosX1, PosY1, 0);
		hama.drawHama(1);
		glPopMatrix();
		//hama end
		//UI start

		//palu start
		glPushMatrix();
		glScalef(2.5, 2.5, 0);
		glTranslatef(paluX, paluY, 0);
		palu.drawPalu();
		glPopMatrix();
		//palu end
	}

	if (waktu < 1)
	{
		highScore.write();
		onGameUI = true;
		//gameover
		change1 = false;
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
		print.drawText(75, 63, "Game Over..");
		print.drawText(75, 55, "Score:");
		print.drawText(120, 55, cetakscore);
		print.drawText(75, 50, "Target score:");
		print.drawText(120, 50, cetaktarget);
		glPushMatrix();
		glBegin(GL_POLYGON);
		if (selesaiHover)
		{
			glColor4f(0.7, 0.7, 0.7, 0.9);
		}
		else
		{
			glColor4f(1, 1, 1, 0.9);
		}
		glVertex2f(tombolSelesai[0], tombolSelesai[1]);
		glVertex2f(tombolSelesai[2], tombolSelesai[1]);
		glVertex2f(tombolSelesai[2], tombolSelesai[3]);
		glVertex2f(tombolSelesai[0], tombolSelesai[3]);
		glEnd();
		glColor3f(0, 0, 0);
		print.drawText(95, 35, "Lanjutkan");
		glPopMatrix();
		if (currentScore < targetScore)
		{
			print.drawText(112, 45, "Kamu kalah");
		}
		else
		{
			print.drawText(100, 45, "Kamu menang");
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
	print.drawText(3, 86, "Score :");
	print.drawText(23, 86, cetakscore);
	print.drawText(3, 82, "Sisa Waktu :");
	print.drawText(23, 82, cetakwaktu);
	//print.drawText(3, 78, "Numpad mode:");
	//print.drawText(23, 78, numpad);
	//UI end

	hama.bombEffect(ortho[0], ortho[1], effectOpacity);
	effectOpacity -= 0.3;
	switch (playLevel)
	{
	case 1:
		if (scoreLevel1 < currentScore) { scoreLevel1 = currentScore; }
		break;
	case 2:
		if(scoreLevel2 < currentScore) { scoreLevel2 = currentScore; }
		break;
	case 3:
		if (scoreLevel3 < currentScore) { scoreLevel3 = currentScore; }
		break;
	}
	glutSwapBuffers();
	glFlush(); //memaksa proses menggambar sampai selesai
}


//page 2
void levelSelection() {
	change = false;
	onLevelSelectUI = true;
	scene.defaultScene();
	if (totalScore >= highScore.curHighScore) { 
		highScore.curHighScore = totalScore;
		highScore.write();
	}
	totalScore = scoreLevel1 + scoreLevel2 + scoreLevel3;
	scene.levelContainer(totalScore,highScore.curHighScore);
	//scene.levelContainer(totalScore);
	scene.levelSelectorUI(level1[0], level1[1], level1[2], level1[3], level1[4], level1Hover,totalScore);
	scene.levelSelectorUI(level2[0], level2[1], level2[2], level2[3], level2[4], level2Hover,totalScore);
	scene.levelSelectorUI(level3[0], level3[1], level3[2], level3[3], level3[4], level3Hover,totalScore);

	glutSwapBuffers();
	glFlush();
}

//page 1
void mainMenu() {


	scene.defaultScene();
	//button ui

	//75, 40, 100, 50
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0, 0.776, 0.929);
	glVertex2f(70,35);
	glVertex2f(105,35);
	glColor3f(1,1,1);;
	glVertex2f(105,55);
	glVertex2f(70,55);
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
	print.drawText(78, 44, "Mulai Bermain");
	glLoadIdentity();

	glutSwapBuffers();
	glFlush(); //memaksa proses menggambar sampai selesai
}

void SceneController(int value) {
	if (change)
	{
		glutDisplayFunc(levelSelection);
	}
	if (change1)
	{
		glutDisplayFunc(display);
	}
	glutPostRedisplay();
	glutTimerFunc(1000, SceneController, 0);
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
	glutFullScreen();
	highScore.read();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project HeheHihi");
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(mousehover);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutTimerFunc(0, update, 0);
	glutTimerFunc(0, gameTime, 0);
	glutTimerFunc(0, hamaSpawn, 0);
	glutTimerFunc(0, SceneController, 0);
	keyboardfunction();
	glutDisplayFunc(mainMenu);
	myinit();
	glutMainLoop();



	

	return 0;
}
