#include<iostream>
using namespace std;
#include<string>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

class Dama {

protected:
	// member variables
	string name;
	int fool;
	int heart;
	int clean;
	int tired;
	int level;
	static int time;
public:
	// constructor
	Dama();
	Dama(string n, int f, int h, int c, int t, int l);
	~Dama();
	string GetName() const { return name; }
	void SetName(string n) { name = n; }

	// function
	void Feed();
	void Enjoy();
	void Shower();
	void Sleep();
	void Status();
	// 출력함수
	void Printdama();
	void Printstatus();
	void Printmenu();
	// 엔딩함수
	void EndingHungry();
	void EndingSick();
	void EndingRunaway();
	void RealEnding();

	void rate_init();

	void Timeflow();
	void gotoxy(int x, int y);
};
#pragma once
