#pragma once
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
#include "Scene1.h"
using namespace std;

extern Bimo bimo;
extern Batu batu;
extern Pager pager;
extern Circle circle;
extern Palu palu;
extern Awan awan;
extern Printer print;
extern KincirAngin kincirAngin;
extern Ladang ladang;
extern Hama hama;

class Scene1
{
	bool paluGerak = true;
	int refreshmill = 1;
	bool selected = false;
	float paluX = 50;
	float paluY = 10;
	int sleepdelay = 0;
	//float rotasi;
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
public:
	//page 1
	void mainMenu() {
		glClearColor(0, 0.776, 0.929, 1);
		glClear(GL_COLOR_BUFFER_BIT); //menghapus windows dan memberi warna yang ada di glclearcolor
		glLoadIdentity();
		
		glutSwapBuffers();
		glFlush(); //memaksa proses menggambar sampai selesai
	}
};