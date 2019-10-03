#ifndef __RANDOMSEQUENCE_H_
#define __RANDOMSEQUENCE_H_

#include "DigitsSequence.h"

#include "Random.h"
#include "SequencesContainer.h"

class RandomSequence {
public:
	RandomSequence();

	DigitsSequence getNextSequence();

private:
	Random generator_;
	SequencesContainer sequencesForChoose_;
};

#endif
