#include "stdafx.h"
#include <iostream>
#include "constants.h"

//getRandomNumber class from section 5.9
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//prints out stuff for playing again
bool playAgain() {
	char playAgain;
	while (true) {
		std::cout << "Would you like to play again? (y/n) \n";
		std::cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'n') { break; }
	}
	return playAgain == 'y';
}

//a run through of the game
bool gameInstance() {
	int target = getRandomNumber(0, 100);
	std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
	int numGuesses = 0;
	while (numGuesses < 7) {
		std::cout << "Guess #" << (numGuesses+1) <<":\n";
		int nextGuess;
		std::cin >> nextGuess;

		if (nextGuess == target) {
			std::cout << "Correct! You win!\n";
			return playAgain();
		}
		else if (nextGuess > target) {
			std::cout << "Your guess is too high.\n";
		}
		else {
			std::cout << "Your guess is too low.\n";
		}
		numGuesses++;
		
	}//end while
	std::cout << "Sorry, you've lost. The correct number was " << target << ".\n";
	return playAgain();

}

int main()
{
	while (gameInstance()) {}
	return 0;
}