#include <iostream>
using namespace std;
#include "01Dama.h"

class Dog :public Dama
{
public:
	Dog();
	~Dog();

	void PrintDama();
	void PrintStatus();
	void PrintMenu();
	void EndingHugry();
	void EndingSick();
	void EndingRunaway();
	void RealEnding();
};