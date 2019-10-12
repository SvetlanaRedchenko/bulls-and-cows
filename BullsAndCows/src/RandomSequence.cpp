#include "RandomSequence.h"

#include <iostream>

#include "Characteristics.h"
#include "Sequence.h"
#include "SequencesGenerator.h"

RandomSequence::RandomSequence()
	: generator_() {
	SequencesGenerator generator;
	generator.set(Characteristics::sequenceLength_, Characteristics::getSymbols());
	sequencesForChoose_ = generator.get();
}

Sequence RandomSequence::getNextSequence() {
	return generator_.get(sequencesForChoose_, 0, sequencesForChoose_.size());
}
