#include "QuestionComputerRandom.h"

#include <iostream>

QuestionComputerRandom::QuestionComputerRandom()
	: QuestionInterface(),
	  generator_() {
}

DigitsSequence QuestionComputerRandom::nextAttempt() {
	const DigitsSequence attempt = generator_.getNextSequence();
	//std::cout << attempt.toString() << "?" << std::endl;
	return attempt;
}

void QuestionComputerRandom::setAnswer(const DigitsSequence&, const Answer&) {
}
