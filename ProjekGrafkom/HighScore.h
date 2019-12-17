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
	#include<conio.h>
	using namespace std;
	class HighScore {
	public:
		int curHighScore;
		int x;
		string line;
		void write() {
			ofstream myfile;
			myfile.open("highscore.txt");
			if (myfile.is_open()) {
				remove("highscore.txt");
				myfile << curHighScore;
				myfile.close();
			}
			else {
				printf_s("file not found");
			}
		}

		void read() {
			ifstream myfile;
			int status;
			char fname[20];
			myfile.open("highscore.txt");
			if (myfile.is_open())
			{
				getline(myfile, line);
				stringstream casting(line);
				casting >> curHighScore;
				//printf_s("%d", x);
				myfile.close();
			}
			else {
				printf_s("file not found");
			}
		}
	};