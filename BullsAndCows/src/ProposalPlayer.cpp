#include "ProposalPlayer.h"

#include <iostream>

#include "Answer.h"
#include "Characteristics.h"
#include "InputValidator.h"

ProposalPlayer::ProposalPlayer()
	: ProposalInterface() {
}

void ProposalPlayer::initialize() {
	std::cout << "Please, make up a sequence and press Enter." << std::endl;

	std::string temp;
	std::getline(std::cin, temp);
}

Answer ProposalPlayer::check(const Sequence&) {
	const int bulls = getNumberFromPlayer("Please, enter bulls count: ",
		0, Characteristics::sequenceLength_);
	const int cows = getNumberFromPlayer("Please, enter cows count: ",
		0, Characteristics::sequenceLength_ - bulls);
	Answer answer(Characteristics::sequenceLength_);
	answer.set(bulls, cows);
	return answer;
}
