#include "stdafx.h"
#include <iostream>

const double gravity{ 9.8 };

double getHeight() {
	std::cout << "Enter height: ";
	double height;
	std::cin >> height;
	return height;
}

double findHeight(double startHeight, int sec) {
	double newHeight = startHeight - (gravity*(sec*sec / 2));
	if (newHeight < 0)
		newHeight = 0;
	return newHeight;
}
int main() 
{
	int height = getHeight();
	std::cout << "Ball is at height " << findHeight(height, 0) << " at time 0.\n";
	std::cout << "Ball is at height " << findHeight(height, 1) << " at time 1.\n";
	std::cout << "Ball is at height " << findHeight(height, 2) << " at time 2.\n";
	std::cout << "Ball is at height " << findHeight(height, 3) << " at time 3.\n";
	std::cout << "Ball is at height " << findHeight(height, 4) << " at time 4.\n";
	std::cout << "Ball is at height " << findHeight(height, 5) << " at time 5.\n";
}
