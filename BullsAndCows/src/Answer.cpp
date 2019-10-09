#include "Answer.h"

Answer::Answer(size_t limit)
	: limit_(limit),
      bulls_(0),
      cows_(0) {
}

void Answer::set(size_t bulls, size_t cows) {
	bulls_ = bulls;
	cows_ = cows;
}

void Answer::incBull() {
	bulls_++;
}

void Answer::incCow() {
	cows_++;
}

size_t Answer::getBulls() const {
	return bulls_;
}

size_t Answer::getCows() const {
	return cows_;
}

size_t Answer::getLimit() const {
	return limit_;
}

bool Answer::isWin() const {
	return bulls_ == limit_;
}

bool Answer::operator==(const Answer& answer) const {
	return limit_ == answer.limit_ && bulls_ == answer.bulls_ && cows_ == answer.cows_;
}

bool Answer::operator!=(const Answer& answer) const {
	return !(this->operator==(answer));
}
