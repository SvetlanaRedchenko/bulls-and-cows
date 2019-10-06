#ifndef __RANDOMSEQUENCE_H_
#define __RANDOMSEQUENCE_H_

#include "Random.h"
#include "SequencesContainer.h"

class Sequence;

class RandomSequence {
public:
	RandomSequence();

	Sequence getNextSequence();

private:
	Random generator_;
	SequencesContainer sequencesForChoose_;
};

#endif
