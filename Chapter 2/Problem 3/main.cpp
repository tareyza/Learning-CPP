#include "stdafx.h"
#include <iostream>

double getDouble() {
	double x;
	std::cin >> x;
	return x;
}

char getSymbol() 
{
	char c;
	std::cin >> c;
	return c;
}

int main() 
{
	double x = getDouble();
	double y = getDouble();
	char c = getSymbol();

	if (c == '+')
		std::cout << "Result: " << x + y;
	else if (c == '-')
		std::cout << "Result: " << x - y;
	else if (c == '/')
		std::cout << "Result: " << x / y;
	else if (c == '*')
		std::cout << "Result: " << x * y;
	return 0;
}
