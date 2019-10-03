#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <random>

#include "DigitsSequence.h"
#include "SequencesContainer.h"

class Random {
public:
	Random();

	DigitsSequence get(SequencesContainer&, size_t min, size_t max) const;

private:
	mutable std::mt19937 generator_;

	size_t get(size_t min, size_t max) const;
};

#endif
