class Hangman {
	const static int TOTAL_NUM_TRIES = 6;

private:
	int tries;
	char failedGuesses[TOTAL_NUM_TRIES];
	char *secretWord;

public:
	Hangman(char *word) {
		tries = 0;
		secretWord = word;
	}

	// EFFECTS: checks if letter has been used. If letter has not been guessed, return true, otherwise return false
	bool hasBeenGuessed(char letter);

	// REQUIRES: letter has not been guessed before
	// EFFECTS: return true if letter is in the secret word, false otherwise
	bool makeGuess(char letter);

	// EFFECTS: display all currently revealed letters to the player
	void displayUpdatedWord();

	// EFFECTS: display the state of the man (based on the number of failed tries)
	void displayMan();

	// EFFECTS: return true if player guessed all the letters 
	bool gameWon();

	// EFFECTS: return true if player ran out of tries before they guessed all the letters
	bool gameOver();

	// EFFECTS: run through one round of hangman (ie. user makes one guess and recieves feedback on that guess)
	void play(char letter);
};
