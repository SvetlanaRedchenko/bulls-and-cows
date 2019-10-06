#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <random>

class Sequence;
class SequencesContainer;

class Random {
public:
	Random();

	Sequence get(SequencesContainer&, size_t min, size_t max) const;

private:
	mutable std::mt19937 generator_;

	size_t get(size_t min, size_t max) const;
};

#endif
