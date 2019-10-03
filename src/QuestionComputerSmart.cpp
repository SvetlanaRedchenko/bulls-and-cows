#include "QuestionComputerSmart.h"

#include <cassert>
#include <iostream>

#include "Characteristics.h"
#include "InputValidator.h"

QuestionComputerSmart::QuestionComputerSmart()
	: QuestionInterface(), generator_() {
	sequencesForChoose_ = Characteristics::getAllSequences();
}

DigitsSequence QuestionComputerSmart::nextAttempt() {
	const DigitsSequence attempt = generator_.get(sequencesForChoose_, 0, sequencesForChoose_.size());
	//std::cout << attempt.toString() << "?" << std::endl;
	return attempt;
}

void QuestionComputerSmart::setAnswer(const DigitsSequence& sequence, const Answer& result) {
	sequencesForChoose_.sieve(sequence, result);
}
