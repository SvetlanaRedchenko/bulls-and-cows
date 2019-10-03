#include "ProposalComputer.h"

#include <iostream>

#include "RandomSequence.h"

ProposalComputer::ProposalComputer()
	: ProposalInterface(), startSequence_() {
}

void ProposalComputer::initialize() {
	RandomSequence generator;
	startSequence_ = generator.getNextSequence();
	std::cout << "Computer set " << startSequence_.toString() << std::endl;
}

Answer ProposalComputer::check(const DigitsSequence& guess) {
	return checkDigitsSequence(startSequence_, guess);
}
