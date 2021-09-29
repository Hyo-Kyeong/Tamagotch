#pragma once
#include "01Dama.h"

class cat :public Dama
{
public:
	void PrintDama();//다마출력
	void PrintStatus();//상태창 출력
	void PrintMenu();//메뉴 출력
	void EndingHungry();//아사 엔딩
	void EndingSick();//병사 엔딩
	void EndingRunaway();//가출 엔딩
	void RealEnding();//진엔딩

};