#pragma once
#include "01Dama.h"

class cat :public Dama
{
public:
	void PrintDama();//�ٸ����
	void PrintStatus();//����â ���
	void PrintMenu();//�޴� ���
	void EndingHungry();//�ƻ� ����
	void EndingSick();//���� ����
	void EndingRunaway();//���� ����
	void RealEnding();//������

};