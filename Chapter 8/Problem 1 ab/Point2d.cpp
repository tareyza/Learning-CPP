#include "stdafx.h"
#include <iostream>
#include <cmath>

class Point2d {
	double m_x = 0.0;
	double m_y = 0.0;

public:


	Point2d(double x=0, double y=0) {
		m_x = x;
		m_y = y;
	}

	void print() {
		std::cout << "Point2d(" << m_x << ", " << m_y << ");\n";
	}

	double distanceTo(Point2d &second) {
		return sqrt((m_x - second.m_x)*(m_x - second.m_x) + (m_y - second.m_y)*(m_y - second.m_y));
	}
};

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	int x;
	std::cin >> x;
	return 0;
}