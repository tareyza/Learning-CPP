#include "stdafx.h"
#include <iostream>
#include <array>
#include<cassert>
#include <string>

class Fruit {
private:
	std::string name;
	std::string color;
public:

	Fruit() {}
	Fruit(std::string name, std::string color) {
		this->name = name;
		this->color = color;
	}

	std::string getColor() {
		return color;
	}

	std::string getName() {
		return name;
	}
};

class Apple : public Fruit {
public:
	Apple(std::string color):
		Fruit("apple", color){
	}

	Apple(std::string name, std::string color) :
		Fruit(name, color) {
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith() :
		Apple("granny smith apple", "green") {
	}
};

class Banana : public Fruit {
public:
	Banana():
		Fruit("banana", "yellow"){
	}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	int x;
	std::cin >> x;
	return 0;
}