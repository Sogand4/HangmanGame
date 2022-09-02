#include <string>
#include <set>

class Hangman {
	const static int TOTAL_NUM_TRIES = 6;

protected:
	int tries;
	int numLetters;
	std::set<char> allGuesses;
	std::string secretWord;

public:
	Hangman(std::string word) {
		tries = 0;
		numLetters = word.length();
		secretWord = word;
	}

	// EFFECTS: if letter has not been guessed, return true, otherwise return false
	bool hasBeenGuessed(char letter);

	// REQUIRES: letter has not been guessed before
	// EFFECTS: if guess succeeds return true, otherwise update number of tries and return false.
	bool tryGuess(char letter);

	// EFFECTS: display all successfully guessed letters to the player
	void displayUpdatedWord();

	// EFFECTS: display the state of the man (based on the number of failed tries)
	void displayMan();

	// EFFECTS: return true if player guessed all the letters, otherwise false
	bool gameWon();

	// EFFECTS: return true if player ran out of tries before they guessed all the letters, otherwise false
	bool gameOver();

	// getters
	int getTries() { return tries; }
	int getNumLetters() { return numLetters; }
	std::set<char> getallGuesses() { return allGuesses; }
	std::string getSecretWord() { return secretWord; }
};
