#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<array>

struct Student {
	std::string name;
	int score;
};

void selectionSort(Student *stu, int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		int index = i;
		for (int j = i+1; j < numStudents; j++) {
			if (stu[j].score > stu[index].score)
				index = j;
		}
		Student temp = stu[i];
		stu[i] = stu[index];
		stu[index] = temp;
	}
}

int main()
{
	std::cout << "How many students do you want to enter?\n";
	int numStudents;
	std::cin >> numStudents;
	Student *stu = new Student[numStudents];
	
	for (int i = 0; i < numStudents; i++) {
		std::cin >> stu[i].name;
		std::cin >> stu[i].score;
	}

	selectionSort(stu, numStudents);

	for (int i = 0; i < numStudents; i++) {
		std::cout << stu[i].name << " got a grade of " << stu[i].score << "\n";
	}

	delete[] stu;

	int x;
	std::cin >> x;
	return 0;
	
}