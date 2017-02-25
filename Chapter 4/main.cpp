#include "stdafx.h"
#include <iostream>
#include<string>

enum class MonsterType {
	OGRE, DRAGON, ORC, GIANT_SPIDER, SLIME
};

struct Monster{
	MonsterType type;
	std::string name;
	int health;
};



void printMonsterType(Monster mon) {
	switch (mon.type) {
	case MonsterType::OGRE:
		std::cout << "This Ogre";
		break;
	case MonsterType::DRAGON:
		std::cout << "This Dragon";
		break;
	case MonsterType::ORC:
		std::cout << "This Orc";
		break;
	case MonsterType::GIANT_SPIDER:
		std::cout << "This Giant Spider";
		break;
	case MonsterType::SLIME:
		std::cout << "This Slime";
		break;
	
	}
}

void printMonster(Monster m) {
	printMonsterType(m);
	std::cout << " is named " << m.name << " and has " << m.health << " health.\n";

}

int main() 
{
	Monster m1 = { MonsterType::OGRE, "Torg", 145 };
	Monster m2 = { MonsterType::SLIME, "Blurp", 23 };
	printMonster(m1);
	printMonster(m2);
	int x;
	std::cin >> x;
}
