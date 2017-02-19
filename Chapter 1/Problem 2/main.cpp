#include "stdafx.h"

void writeAnswer(int x);
int readNumber();

int main() 
{
	int x = readNumber();
	int y = readNumber();
	writeAnswer(x + y);
	return 0;
}
