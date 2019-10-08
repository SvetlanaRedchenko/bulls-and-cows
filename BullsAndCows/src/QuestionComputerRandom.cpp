#include "QuestionComputerRandom.h"

QuestionComputerRandom::QuestionComputerRandom()
	: QuestionInterface(),
	  generator_() {
}

Sequence QuestionComputerRandom::nextAttempt() {
	return generator_.getNextSequence();
}

void QuestionComputerRandom::setAnswer(const Sequence&, const Answer&) {
}
