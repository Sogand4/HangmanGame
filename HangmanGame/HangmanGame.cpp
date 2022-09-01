#include <iostream>
#include <C:\Users\sogan\source\repos\HangmanGame\HangmanGame\Hangman.h>

int main()
{
	std::string secretWord;
	char letter;

	std:: cout << "Player one enter your secret word: ";
	std::cin >> secretWord;
	Hangman game = Hangman(secretWord);

	system("CLS");
	std::cout << "Pass the device to player two! \n";
	game.displayUpdatedWord();

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
			std::cout << "-----------------------------------";
			std::cout << "\n";
		}
	}

	std::cout << "\n";
	if (game.gameWon()) {
		std::cout << "The word was guessed. Player two wins!";
	}
	else {
		std::cout << "The word was " << secretWord << "\nPlayer one wins!";
	}

	return 0;
}
