#include "ProposalPlayer.h"

#include <iostream>

#include "Answer.h"
#include "InputValidator.h"

ProposalPlayer::ProposalPlayer()
	: ProposalInterface() {
}

void ProposalPlayer::initialize() {
	std::cout << "Please, make up a sequence and press Enter." << std::endl;

	std::string temp;
	std::getline(std::cin, temp);
}

Answer ProposalPlayer::check(const Sequence& sequence) {
	std::cout << "You make [" << sequence.toString() << "]?" << std::endl;
	const int bulls = getCountBullsOrCowsFromPlayer("Please, enter bulls count: ");
	const int cows = getCountBullsOrCowsFromPlayer("Please, enter cows count: ");
	return Answer(bulls, cows);
}
