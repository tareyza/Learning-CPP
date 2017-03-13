#include "stdafx.h"
#include <iostream>
#include <array>
#include<cassert>
#include <string>
#include<cstdlib>
#include<ctime>


// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
class Creature {
protected:
	std::string name;
	char symbol;
	int health;
	int strength;
	int gold;

public:

	Creature(std::string n, char s, int hp, int str, int g) {
		name = n;
		symbol = s;
		health = hp;
		strength = str;
		gold = g;
	}
	std::string getName() { 
		return name;
	}
	char getSymbol() { 
		return symbol;
	}
	int getHealth() { 
		return health;
	}
	int getStrength() { 
		return strength;
	}
	int getGold() {
		return gold;
	}

	void reduceHealth(int n) {
		health = health - n;
	}

	bool isDead() {
		return health <= 0;
	}

	void addGold(int n) {
		gold = gold + n;
	}


};

class Player : public Creature {
private:
	int level = 1;

public:
	Player(std::string name):
		Creature(name, '@', 10, 1, 0)
	{
	}

	int getLevel() {
		return level;
	}

	void levelUp() {
		level++;
		strength++;
	}

	bool hasWon() {
	if(level==20)
		return true;
	}
};

class Monster : public Creature {
public:
	enum Type { DRAGON, ORC, SLIM, MAX_TYPES };

	struct MonsterData { std::string name; char symbol; int health; int strength; int gold; };

	static MonsterData monsterData[MAX_TYPES];

	Monster(Type t) :
		Creature(monsterData[t].name, monsterData[t].symbol, monsterData[t].health, monsterData[t].strength, monsterData[t].gold) {}

	static Monster getRandomMonster() {
		return Monster(static_cast<Type>(getRandomNumber(0, 2)));
		
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

bool runGame(Player &p) {

	while (!p.isDead()) {
		Monster m = Monster::getRandomMonster();
		std::cout << "You've encountered a " << m.getName() << "(" << m.getSymbol() << ")\n";
		while (true) {
			std::cout << "(R)un or (F)ight? ";
			char in;
			std::cin >> in;
			if (in == 'R') {
				if (getRandomNumber(1, 2) == 1) {
					std::cout << "You flee successfully.";
					break;
				}
				else {
					p.reduceHealth(m.getStrength());
					std::cout << "You fail to flee and are hit for " << m.getStrength() << ".\n";
				}
			}
			else {
				std::cout << "You hit the " << m.getName() << " for " << p.getStrength() << ".\n";
				m.reduceHealth(p.getStrength());
				if (m.isDead()){
					std::cout << "You've killed the " << m.getName() << ".\n";
					p.addGold(m.getGold());
					break;
				}
				p.reduceHealth(m.getStrength());
				std::cout << "You've been hit for " << m.getStrength() << ".\n";
				if (p.isDead())
					break;
			}
			if (p.isDead())
				return false;
		}
		
		p.levelUp();
		if (p.getLevel() == 20)
			return true;
		
	}
	return false;
}

int main()
{
	rand();
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;

	Player p(name);
	std::cout << "Welcome, " << p.getName() << ".\n";

	if (runGame(p))
		std::cout << "You've won! You got "<< p.getGold() << "gold.";
	else
		std::cout << "You've lost. You were level " << p.getLevel() << " and died with " << p.getGold() << " gold. ";

	int x;
	std::cin >> x;
	return 0;
}