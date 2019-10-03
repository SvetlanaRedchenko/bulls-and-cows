#include "RandomSequence.h"

#include <cassert>
#include <iostream>

#include "Characteristics.h"

RandomSequence::RandomSequence()
	: generator_() {
	sequencesForChoose_ = Characteristics::getAllSequences();
}

DigitsSequence RandomSequence::getNextSequence() {
	return generator_.get(sequencesForChoose_, 0, sequencesForChoose_.size());
}
