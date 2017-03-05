#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<array>
#include <ctime>
#include <cstdlib>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES};

enum Rank { ACE, R2, R3, R4, R5, R6, R7, R8, R9, R10, JACK, QUEEN, KING };

struct Card {
	Suit suit;
	Rank rank;
};

void printCard(const Card &card) {

	switch (card.rank)
	{
	case ACE: std::cout << 'A'; 
		break;
	case R2: std::cout << '2';
		break;
	case R3: std::cout << '3'; 
		break;
	case R4: std::cout << '4'; 
		break;
	case R5: std::cout << '5'; 
		break;
	case R6: std::cout << '6'; 
		break;
	case R7: std::cout << '7'; 
		break;
	case R8: std::cout << '8'; 
		break;
	case R9: std::cout << '9'; 
		break;
	case R10: std::cout << '0'; 
		break;
	case JACK: std::cout << 'J';
		break;
	case QUEEN:	std::cout << 'Q';
		break;
	case KING: std::cout << 'K';
		break;
	}

	switch (card.suit)
	{
	case CLUBS:	std::cout << 'C';
		break;
	case DIAMONDS: std::cout << 'D';
		break;
	case HEARTS: std::cout << 'H';
		break;
	case SPADES: std::cout << 'S';
		break;
	}
	std::cout << " ";
}

void printDeck(const std::array<Card, 52> &cards) {
	for (const Card &card : cards) {
		printCard(card);
		std::cout << "\n";
	}
}

void swapCard(Card &i, Card &j) {
	Card temp = i;
	i = j;
	j = temp;
}

//getRandomNumber method from section 5.9
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffle(std::array<Card, 52> &cards) {
	for (int i = 0; i < 52; i++) {
		swapCard(cards[i], cards[getRandomNumber(0, 51)]);
	}
}

int getCardValue(const Card &card) {

	switch (card.rank)
	{
	case ACE: return 11;
	case R2: return 2;
	case R3: return 3;
	case R4: return 4;
	case R5: return 5;
	case R6: return 6;
	case R7: return 7;
	case R8: return 8;
	case R9: return 9;
	case R10: return 10;
	case JACK: return 10;
	case QUEEN: return 10;
	case KING: return 10;
	}
}


bool playBlackJack(const std::array<Card, 52> &cards) {
	const Card *cardPtr = &cards[0];//first card

	int p1Score = 0;
	int p2Score = 0;

	p1Score += getCardValue(*cardPtr++);
	p1Score += getCardValue(*cardPtr++);
	p2Score += getCardValue(*cardPtr++);

	while (true) {//player's move
		std::cout << "Your points: " << p1Score << ". What do you want to do? (0 = hit, 1 = stand) \n";
		int choice;
		std::cin >> choice;
		if (choice == 1) {
			break;
		}
		p1Score += getCardValue(*cardPtr++);
		if (p1Score > 21) {
		std::cout << "Your points: " << p1Score << ".\n";
		return false;
	}
	}

	while (p2Score < 17) {//dealer's moves
		p2Score += getCardValue(*cardPtr++);
		std::cout << "Dealer's score is: " << p2Score << ".\n";
	}

	//game has ended
	if (p2Score > 21)
		return true;
	return p1Score > p2Score;
}

int main(){

	//random int from learncpp random int section
	srand(static_cast<unsigned int>(time(0)));
	rand();
	
	std::array<Card, 52> cards;
	

	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[index].suit = static_cast<Suit>(i);
			cards[index].rank = static_cast<Rank>(j);
			index++;
		}
	}

	shuffle(cards);

	if (playBlackJack(cards)) {
		std::cout << "YOU WIN, CONGRATS!!";
	}
	else
		std::cout << "YOU LOSE, DEALER WINS!!";

	int x;
	std::cin >> x;
	return 0;
}