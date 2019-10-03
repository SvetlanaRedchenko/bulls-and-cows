#include "Helper.h"

#include <cassert>
#include <set>

#include "Characteristics.h"

bool isDigitsUnique(int number) {
	assert(number >= 0 && number < Characteristics::maxSequenceCount_);

	std::set<Digit> digits;

	for (int i = Characteristics::sequenceLength_ - 1; i >= 0; --i) {
		digits.insert(number % 10);
		number = number / 10;
	}

	return digits.size() == Characteristics::sequenceLength_;
}
