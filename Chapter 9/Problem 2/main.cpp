#include "stdafx.h"
#include <iostream>
#include <array>

class Average {
private:
	int32_t sum = 0;
	int8_t num = 0;

public:
	Average() {}

	friend std::ostream& operator<<(std::ostream &cout, const Average &average) {
		cout << (static_cast<double>(average.sum)) /(average.num);
		return cout;
	}

	Average& operator+=(int n) {
		sum += n;
		++num;
		return *this;
	}
};

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	int x;
	std::cin >> x;
	return 0;
}