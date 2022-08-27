#include "Hangman.h"
#include <iostream>

bool Hangman::hasBeenGuessed(char letter) {
	return allGuesses.find(letter) != allGuesses.end();
}

bool Hangman::makeGuess(char letter) {
	tries++;
	return secretWord.find(letter) != std::string::npos;
}

void Hangman::displayUpdatedWord() {
	for (int i = 0; i < secretWord.size(); i++) {
		char currentLetter = secretWord.at(i);

		if (allGuesses.find(currentLetter) != allGuesses.end()) {
			std::cout << currentLetter;
		}
		else {
			std::cout << "_";
		}
	}
}

void Hangman::displayMan() {
	switch (tries) {
	case 0:
		std::cout << "    |    ";
		break;
	case 1:
		std::cout << "    |    ";
		std::cout << "    0    ";
		break;
	case 2:
		std::cout << "    |    ";
		std::cout << "    0    ";
		std::cout << "    |    ";
		break;
	case 3:
		std::cout << "    |    ";
		std::cout << "    0    ";
		std::cout << "    |    ";
		std::cout << "   /     ";
		break;
	case 4:
		std::cout << "    |    ";
		std::cout << "    0    ";
		std::cout << "    |    ";
		std::cout << "   / \   ";
		break;
	case 5:
		std::cout << "    |    ";
		std::cout << "    0    ";
		std::cout << "   /|    ";
		std::cout << "   / \   ";
		break;
	case 6:
		std::cout << "    |    ";
		std::cout << "    0    ";
		std::cout << "   /|\   ";
		std::cout << "   / \   ";
		break;
	default:
		break;
	}
}

bool Hangman::gameWon() {
	int numLettersGuessed = 0;

	for (int i = 0; i < secretWord.size(); i++) {
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
