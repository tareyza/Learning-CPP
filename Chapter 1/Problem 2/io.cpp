#include "stdafx.h"
#include <iostream>


int readNumber(){
	int x;
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "Sum: " << x;
}
