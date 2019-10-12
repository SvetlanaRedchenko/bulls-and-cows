#include "Sequence.h"

#include <algorithm>

#include "Answer.h"
#include "Characteristics.h"
#include "Helper.h"

Sequence::Sequence() : symbols_() {
}

Sequence::Sequence(const std::string& sequence)
	: Sequence() {
	for (auto c : sequence) {
		symbols_.push_back(c);
	}
}

bool Sequence::operator==(const Sequence& other) const {
	return symbols_ == other.symbols_;
}

bool Sequence::operator<(const Sequence& other) const {
	if (symbols_.size() < other.symbols_.size())
		return true;
	if (symbols_.size() > other.symbols_.size())
		return false;

	for (size_t i = 0; i < symbols_.size(); ++i) {
		if (symbols_[i] < other.symbols_[i])
			return true;
		else if (symbols_[i] > other.symbols_[i])
			return false;
	}
	return false;
}

bool isUnique(Sequence sequence) {
	std::sort(sequence.symbols_.begin(), sequence.symbols_.end());
	auto end = std::unique(sequence.symbols_.begin(), sequence.symbols_.end());
	return end == sequence.symbols_.end();
}

Answer checkSequence(
	const Sequence& origin, const Sequence& attempt) {
	Answer answer(origin.symbols_.size());
	if (origin.symbols_.size() == attempt.symbols_.size()) {
		for (size_t i = 0; i < origin.symbols_.size(); ++i) {
			if (origin.symbols_[i] == attempt.symbols_[i]) {
				answer.incBull();
			}
			else if (std::find(origin.symbols_.begin(), origin.symbols_.end(), attempt.symbols_[i]) != origin.symbols_.end()) {
				answer.incCow();
			}
		}
	}

	return answer;
}

std::string toString(const Sequence& sequence) {
	std::string result;
	for (auto symbol : sequence.symbols_) {
		result += symbol;
	}
	return result;
}
