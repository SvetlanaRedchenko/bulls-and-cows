#include "Sequence.h"

#include <algorithm>
#include <cassert>

#include "Answer.h"
#include "Characteristics.h"

Sequence::Sequence() : symbols_() {
}

Sequence::Sequence(const std::string& sequence)
	: Sequence() {
	for (auto c : sequence) {
		if (Characteristics::isCorrectSymbol(c))
			symbols_.push_back(c);
	}
	assert(symbols_.size() == Characteristics::sequenceLength_);
}

std::string Sequence::toString() const {
	std::string sequence;
	for (auto symbol : symbols_) {
		sequence += symbol;
	}
	return sequence;
}

Answer checkSequence(
	const Sequence& origin, const Sequence& attempt) {
	assert(origin.symbols_.size() == attempt.symbols_.size());
	Answer answer;
	for (int i = 0; i < origin.symbols_.size(); ++i) {
		if (origin.symbols_[i] == attempt.symbols_[i]) {
			answer.addBull();
		}
		else if (std::find(origin.symbols_.begin(), origin.symbols_.end(), attempt.symbols_[i]) != origin.symbols_.end()) {
			answer.addCow();
		}
	}

	return answer;
}
