#include "QuestionComputerRandom.h"

#include <iostream>

#include "Answer.h"

QuestionComputerRandom::QuestionComputerRandom()
	: QuestionInterface(),
	  generator_() {
}

Sequence QuestionComputerRandom::nextAttempt() {
	return generator_.getNextSequence();
}

void QuestionComputerRandom::setAnswer(const Sequence&, const Answer&) {
}
