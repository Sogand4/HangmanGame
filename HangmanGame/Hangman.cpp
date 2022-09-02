#include "Hangman.h"
#include <iostream>

bool Hangman::hasBeenGuessed(char letter) {
	return allGuesses.find(letter) != allGuesses.end();
}

bool Hangman::tryGuess(char letter) {
	allGuesses.insert(letter);

	if (secretWord.find(letter) == std::string::npos) {
		tries++;
		return false;
	}
	else {
		return true;
	}
}

void Hangman::displayUpdatedWord() {
	for (std::string::size_type i = 0; i < secretWord.length(); i++) {
		char currentLetter = secretWord.at(i);

		if (allGuesses.find(currentLetter) != allGuesses.end()) {
			std::cout << currentLetter;
		}
		else {
			std::cout << "_";
		}

		std::cout << " ";
	}
}

void Hangman::displayMan() {
	switch (tries) {
	case 0:
		std::cout << "    |    \n";
		break;
	case 1:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		break;
	case 2:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		std::cout << "    |    \n";
		break;
	case 3:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		std::cout << "    |    \n";
		std::cout << "   /     \n";
		break;
	case 4:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		std::cout << "    |    \n";
		std::cout << "   / \\   \n";
		break;
	case 5:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		std::cout << "   /|    \n";
		std::cout << "   / \\   \n";
		break;
	case 6:
		std::cout << "    |    \n";
		std::cout << "    0    \n";
		std::cout << "   /|\\   \n";
		std::cout << "   / \\   \n";
		break;
	default:
		break;
	}
}

bool Hangman::gameWon() {
	int numLettersGuessed = 0;

	for (std::string::size_type i = 0; i < secretWord.length(); i++) {
		char currentLetter = secretWord.at(i);

		if (allGuesses.find(currentLetter) != allGuesses.end()) {
			numLettersGuessed++;
		}
	}

	return numLettersGuessed == secretWord.size();
}

bool Hangman::gameOver() {
	return tries == TOTAL_NUM_TRIES;
}
