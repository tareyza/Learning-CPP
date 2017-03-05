#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<array>

struct Student {
	std::string name;
	int score;
};

void printCharByChar(char *str) {
	while (*str != '\0') {
		std::cout << *str;
		str++;
	}

}


int main()
{
	printCharByChar("Hello, World!");
	return 0;
}