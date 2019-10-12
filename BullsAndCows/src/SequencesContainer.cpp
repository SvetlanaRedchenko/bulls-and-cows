#include "SequencesContainer.h"

#include <cassert>

#include "Answer.h"
#include "Sequence.h"

SequencesContainer::SequencesContainer() {
}

size_t SequencesContainer::size() const {
	return container_.size();
}

bool SequencesContainer::empty() const {
	return container_.empty();
}

void SequencesContainer::push_back(const Sequence&param) {
	container_.push_back(param);
}

Sequence SequencesContainer::extract(size_t index) {
	assert(index < container_.size());
	std::list<Sequence>::iterator it = container_.begin();
	for (size_t i = 0; i < index; ++i, ++it);
	Sequence sequence = *it;
	container_.erase(it);
	return sequence;
}

void SequencesContainer::sieve(const Sequence& sequence, const Answer& answer) {
	for (std::list<Sequence>::iterator it = container_.begin();
		it != container_.end(); ) {
		if (checkSequence(sequence, *it) != answer) {
			it = container_.erase(it);
		} else {
			++it;
		}
	}
}

const std::list<Sequence>& SequencesContainer::getForTest() const {
	return container_;
}
