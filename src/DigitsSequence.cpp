#include "DigitsSequence.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

#include "Characteristics.h"
#include "Helper.h"

DigitsSequence::DigitsSequence(const std::string& number)
    : digits_() {
	for (auto c : number) {
		if (isdigit(c))
			digits_.push_back(c - '0');
	}
	assert(digits_.size() == Characteristics::sequenceLength_);
}

DigitsSequence::DigitsSequence() : digits_() {
}

DigitsSequence::DigitsSequence(int number) : digits_() {
	assert(number >= 0 && number < Characteristics::maxSequenceCount_);
	assert(isDigitsUnique(number));
	digits_.resize(Characteristics::sequenceLength_);
	for (int i = Characteristics::sequenceLength_-1; i >= 0; --i) {
		digits_[i] = number % 10;
		number = number / 10;
	}
}

std::string DigitsSequence::toString() const {
	std::string number;
	for (auto digit : digits_) {
		std::ostringstream oss;
		oss << digit;
		number += oss.str();
	}
	return number;
}

Answer checkDigitsSequence(
	const DigitsSequence& origin, const DigitsSequence& attempt) {
	assert(origin.digits_.size() == attempt.digits_.size());
	Answer answer;
	for (int i = 0; i < origin.digits_.size(); ++i) {
		if (origin.digits_[i] == attempt.digits_[i]) {
			answer.addBull();
		}
		else if (std::find(origin.digits_.begin(), origin.digits_.end(), attempt.digits_[i]) != origin.digits_.end()) {
			answer.addCow();
		}
	}
	
	return answer;
}
