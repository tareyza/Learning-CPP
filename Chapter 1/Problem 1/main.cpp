#include "stdafx.h"
#include <iostream>

int readNumber() {
	int x;
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "Sum: " << x;
}

int main() 
{
	int x = readNumber();
	int y = readNumber();
	writeAnswer(x + y);
	return 0;
}
