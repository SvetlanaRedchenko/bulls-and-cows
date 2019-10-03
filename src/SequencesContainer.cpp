#include "SequencesContainer.h"

#include <cassert>
#include <iostream>

SequencesContainer::SequencesContainer() {
}

size_t SequencesContainer::size() const {
	return container_.size();
}

bool SequencesContainer::empty() const {
	return container_.empty();
}

void SequencesContainer::push_back(const DigitsSequence&param) {
	container_.push_back(param);
}

DigitsSequence SequencesContainer::extract(size_t index) {
	assert(index < container_.size());
	std::list<DigitsSequence>::iterator it = container_.begin();
	for (size_t i = 0; i < index; ++i, ++it);
	DigitsSequence sequence = *it;
	container_.erase(it);
	return sequence;
}

void SequencesContainer::sieve(const DigitsSequence& sequence, const Answer& answer) {
	for (std::list<DigitsSequence>::iterator it = container_.begin();
		it != container_.end(); ) {
		if (checkDigitsSequence(sequence, *it) != answer) {
			it = container_.erase(it);
		} else {
			++it;
		}
	}
}
