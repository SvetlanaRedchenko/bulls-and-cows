#include "QuestionComputerSmart.h"

#include <cassert>
#include <iostream>

#include "Answer.h"
#include "Characteristics.h"

QuestionComputerSmart::QuestionComputerSmart()
	: QuestionInterface(), generator_() {
	sequencesForChoose_ = Characteristics::getAllSequences();
}

Sequence QuestionComputerSmart::nextAttempt() {
	return generator_.get(sequencesForChoose_, 0, sequencesForChoose_.size());
}

void QuestionComputerSmart::setAnswer(const Sequence& sequence, const Answer& result) {
	sequencesForChoose_.sieve(sequence, result);
}
