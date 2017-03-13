#include "stdafx.h"
#include <iostream>
#include <array>
#include<cassert>
#include <string>
#include<vector>

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape {
public:
	virtual std::ostream& print(std::ostream &cout) = 0;

	friend std::ostream& operator<<(std::ostream &cout, Shape &p) {
		return p.print(cout);
	}

	virtual ~Shape() {}

};

class Triangle :public Shape {
private:
	Point p1;
	Point p2;
	Point p3;

public:
	Triangle(Point &p, Point &pp, Point &ppp) :
		p1(p), p2(pp), p3(ppp) {}

	virtual std::ostream& print(std:: ostream &cout) override {
		cout << "Triangle(" << p1 << ", " << p2 << ", " << p3 << ")";
		return cout;
	}
};

class Circle : public Shape {
private:
	Point point;
	int radius;

public:
	Circle(Point& p, int r):
		radius(r), point(p) {}

	virtual std::ostream& print(std::ostream &cout) override {
		cout << "Cicle(" << point << ", radius "<< radius << ")";
		return cout;
	}

	int getRadius() {
		return radius;
	}
};

int getLargestRadius(std::vector<Shape*> &arr) {
	int max = 0;
	for (int i = 0; i < arr.size(); i++) {
		Circle *c = dynamic_cast<Circle*>(arr[i]);
		if (c && c->getRadius() > max) {
			max = c->getRadius();
		}
	}
	return max;
}


int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	std::cout << *(v[0]) << "\n";
	std::cout << *(v[1]) << "\n";
	std::cout << *(v[2]) << "\n";
	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	delete v[0];
	delete v[1];
	delete v[2];
	int x;
	std::cin >> x;
	return 0;
}