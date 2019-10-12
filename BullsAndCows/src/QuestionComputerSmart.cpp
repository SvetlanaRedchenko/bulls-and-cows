#include "QuestionComputerSmart.h"

#include "Answer.h"
#include "Characteristics.h"
#include "SequencesGenerator.h"

QuestionComputerSmart::QuestionComputerSmart()
	: QuestionInterface(), generator_() {
	SequencesGenerator generator;
	generator.set(Characteristics::sequenceLength_, Characteristics::getSymbols());
	sequencesForChoose_ = generator.get();
}

Sequence QuestionComputerSmart::nextAttempt() {
	return generator_.get(sequencesForChoose_, 0, sequencesForChoose_.size());
}

void QuestionComputerSmart::setAnswer(const Sequence& sequence, const Answer& result) {
	sequencesForChoose_.sieve(sequence, result);
}
