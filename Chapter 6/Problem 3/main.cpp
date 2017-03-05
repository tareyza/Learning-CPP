#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<array>

struct Student {
	std::string name;
	int score;
};

void selectionSort(int i, int j) {
		int temp = i;
		i = j;
		j = temp;
	}


int main()
{
	int x = 0;
	int y = 1;
	selectionSort(x, y);
	std::cout << x;
	return 0;
	
}