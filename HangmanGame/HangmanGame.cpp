#include <iostream>
#include <C:\Users\sogan\source\repos\HangmanGame\HangmanGame\Hangman.h>

std::string secretWord;

void displayInstructions();
void playGame(Hangman& game);
std::string setSecretWord();
void displayResults(Hangman& game);

// EFFECTS: runs a game of hangman
int main()
{
	displayInstructions();
	secretWord = setSecretWord();
	Hangman game = Hangman(secretWord);

	playGame(game);

	displayResults(game);

	return 0;
}

// EFFECTS: print instructions on how to play hangman
void displayInstructions() {
	std::cout << "Welcome to hangman! \n";
	std::cout << "Rules: Player one thinks of a word and player two attempts to figure out the secret word\nby guessing if it contains a particular letter.\n";
	std::cout << "Player one wins if player two fails to guess the word before the man is hung.\n";
}

// EFFECTS: player two makes guesses until the game is over
void playGame(Hangman& game) {
	char letter;

	std::cout << "Pass the device to player two! \n";
	game.displayUpdatedWord();
	std::cout << "\n";

	while (!game.gameOver() && !game.gameWon()) {
		std::cout << "\nPlayer two guess a letter: ";
		std::cin >> letter;

		if (game.hasBeenGuessed(letter)) {
			std::cout << "\nThat letter has already been guessed. Try again...";
		}
		else {
			if (game.tryGuess(letter)) {
				std::cout << "Correct!";
			}
			else {
				std::cout << "Incorrect!";
			}

			std::cout << "\n";
			game.displayMan();
			std::cout << "\n\n";
			game.displayUpdatedWord();
			std::cout << "\n";
			std::cout << "-----------------------------------";
			std::cout << "\n";
		}
	}
}

// EFFECTS: ask user for a word, clear the console, then return the word
std::string setSecretWord() {
	std::string secretWord;

	std::cout << "Player one enter your secret word: ";
	std::cin >> secretWord;

	system("CLS");
	return secretWord;
}

// EFFECTS: print which player won the game
void displayResults(Hangman& game) {
	std::cout << "\n";
	if (game.gameWon()) {
		std::cout << "The word was guessed. Player two wins!";
	}
	else {
		std::cout << "The word was " << secretWord << "\nPlayer one wins!";
	}
}