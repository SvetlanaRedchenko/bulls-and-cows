#include "ProposalComputer.h"

#include "Answer.h"
#include "RandomSequence.h"

ProposalComputer::ProposalComputer()
	: ProposalInterface(), startSequence_() {
}

void ProposalComputer::initialize() {
	RandomSequence generator;
	startSequence_ = generator.getNextSequence();
}

Answer ProposalComputer::check(const Sequence& question) {
	return checkSequence(startSequence_, question);
}
