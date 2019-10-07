#include "Random.h"

#include <cassert>
#include <chrono>

#include "Sequence.h"
#include "SequencesContainer.h"

Random::Random()
	: generator_(
		static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())) {
}

size_t Random::get(size_t min, size_t max) const {
	assert(min < max);
	return generator_() % (max - min) + min;
}

Sequence Random::get(SequencesContainer& sequences, size_t min, size_t max) const {
	assert(sequences.size() > 0);

	size_t index = get(min, max);
	return sequences.extract(index);
}
