#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>



class Monster{
public:
	enum MonsterType { Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, Zombie, MAX_MONSTER_TYPES };

private:
	MonsterType type;
	std::string name;
	std::string roar;
	int hp;

public:
	Monster(MonsterType ty, std::string n, std::string r, int h) {
		type = ty;
		name = n;
		roar = r;
		hp = h;
	}
	
	std::string getTypeString() {
		switch (type)
		{
		case Dragon: 
			return "dragon";
		case Goblin: 
			return "goblin";
		case Ogre: 
			return "ogre";
		case Orc: 
			return "orc";
		case Skeleton: 
			return "skeleton";
		case Troll: 
			return "troll";
		case Vampire: 
			return "vampire";
		case Zombie: 
			return "zombie";
		}
	}

	void print() {
		std::cout << name << " the " << getTypeString() << " has " << hp << " hitpoints and says " << roar << ".\n";
	}
};

class MonsterGenerator {
public:
	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster() {
		static std::string s_names[6]{"A", "B", "C", "D", "E", "F"};
		static std::string s_roars[6]{ "R1","R2","R3","R4","R5","R6" };
		return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, 7)), s_names[getRandomNumber(0,5)], s_roars[getRandomNumber(0, 5)], getRandomNumber(0,100));
	}
};


int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();
	int x;
	std::cin >> x;
	return 0;
}