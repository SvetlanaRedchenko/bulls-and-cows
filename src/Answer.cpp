#include "Answer.h"

#include <cassert>
#include <sstream>

#include "Characteristics.h"

Answer::Answer() : Answer(0, 0) {
}

Answer::Answer(int bulls, int cows) 
    : bulls_(bulls), cows_(cows) {
	assert(bulls_ + cows_ <= Characteristics::sequenceLength_);
}

bool Answer::isWin() const {
	return bulls_ == Characteristics::sequenceLength_;
}

void Answer::addBull() {
	bulls_++;
	assert(bulls_ + cows_ <= Characteristics::sequenceLength_);
}

void Answer::addCow() {
	cows_++;
	assert(bulls_ + cows_ <= Characteristics::sequenceLength_);
}

bool Answer::operator==(const Answer& answer) const {
	return bulls_ == answer.bulls_ && cows_ == answer.cows_;
}

bool Answer::operator!=(const Answer& answer) const {
	return !(this->operator==(answer));
}

std::string Answer::toString() const {
	std::ostringstream oss;
	oss << "bulls = " << bulls_ << ", cows = " << cows_;
	return oss.str();
}
