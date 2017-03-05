#include "stdafx.h"
#include <iostream>

enum Items {
	HEALTH_POTION, TORCH, ARROW
};

int countTotalItems(int *item) {
	int num = 0;
	for (int i = 0; i < 3; i++) {
		num = num + item[i];
	}
	return num;
}

int main()
{
	int items[3] = {2, 5, 10};

	std::cout << "You have: " << countTotalItems(items) << " items.";
	return 0;
	
}