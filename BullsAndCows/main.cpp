#include <iostream>
#include <memory>

#include "src/Characteristics.h"
#include "src/InputValidator.h"
#include "src/Factory.h"
#include "src/Game.h"

int main()
{
	std::cout << "Game Bulls and Cows (extended, non-classic version)\n"
		"Player 1 makes up a sequence of " << Characteristics::sequenceLength_ <<
		" unique characters from the set " << getSymbolsAsString() << std::endl <<
		"Player 2 tries to guess her by offering his own version.\n"
		"If the symbol is present in the desired sequence in its place, this is the Bull.\n"
		"If the symbol is not present in the correct sequence in the desired sequence, this is the Cow.\n"
		"Thus, Player 2 offers his own version of the sequence, and Player 1 gives the number of Bulls and Cows.\n\n"
		"Who will make up the sequence?\n"
		"1. Player (You)\n"
		"2. Computer" << std::endl;
	const int player1 = getNumberFromPlayer("Please, make You choose", 1, 2);
	std::cout << "Who will guess?\n"
		"1. Player (You)\n"
		"2. Computer (Easy mode)\n"
		"3. Computer (Smart mode)" << std::endl;
	const int player2 = getNumberFromPlayer("Please, make You choose", 1, 3);

	std::string player1Name, player2Name;
	std::shared_ptr<ProposalInterface> proposal;
	std::shared_ptr<QuestionInterface> question;

	switch (player1) {
	case 1:
		proposal = Factory::getPlayerProposal();
		player1Name = "Player";
		break;
	case 2:
		proposal = Factory::getComputerProposal();
		player1Name = "Computer";
		break;
	}

	switch (player2) {
	case 1:
		question = Factory::getPlayerQuestion();
		player2Name = "Player";
		break;
	case 2:
		question = Factory::getComputerEasyQuestion();
		player2Name = "Computer";
		break;
	case 3:
		question = Factory::getComputerHardQuestion();
		player2Name = "Computer";
		break;
	}

	std::cout << std::endl <<  player1Name << " VS " << player2Name << std::endl;
	const int step = Game::play(proposal, question);
	std::cout << "Win! It took " << step << " step(s)!" << std::endl;
}
