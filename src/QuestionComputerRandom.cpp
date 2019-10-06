#include "QuestionComputerRandom.h"

#include <iostream>

#include "Answer.h"

QuestionComputerRandom::QuestionComputerRandom()
	: QuestionInterface(),
	  generator_() {
}

Sequence QuestionComputerRandom::nextAttempt() {
	const Sequence attempt = generator_.getNextSequence();
	//std::cout << attempt.toString() << "?" << std::endl;
	return attempt;
}

void QuestionComputerRandom::setAnswer(const Sequence&, const Answer&) {
}
