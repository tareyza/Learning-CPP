#include "stdafx.h"
#include <iostream>
#include <array>
#include<cassert>

class IntArray {
private:
	int length;
	int *address = nullptr;

public:
	IntArray(int leng) {
		length = leng;
		assert(leng >= 0);
		address = new int[length] {0};
	}

	IntArray(const IntArray &array){
		length = array.length;
		address = new int[length];

		for (int i = 0; i < length; i++) {
			address[i] = array.address[i];
		}
	}

	int& operator[] (const int index) {
		assert(index >= 0 && index < length);
		return address[index];
	}

	IntArray& operator= (const IntArray &array) {
		if (this == &array) {
			return *this;
		}
		length = array.length;
		address = new int[length];

		for (int i = 0; i < length; i++) {
			address[i] = array.address[i];
		}
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &cout, const IntArray &array) {
		cout << "[";
		for (int i = 0; i < array.length; i++)
			cout << array.address[i] << " ";
		cout << "]";
		return cout;
	}
};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';
	int x;
	std::cin >> x;
	return 0;
}