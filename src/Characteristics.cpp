#include "Characteristics.h"

#include "Helper.h"

SequencesContainer Characteristics::allSequences_;

const int Characteristics::maxSequenceCount_ =
	static_cast<const int>(
		pow(Characteristics::symbolsCount_, Characteristics::sequenceLength_));

SequencesContainer Characteristics::getAllSequences() {
	if (allSequences_.empty()) {
		for (int i = 0; i < Characteristics::maxSequenceCount_; i++) {
			if (isDigitsUnique(static_cast<int>(i)))
				allSequences_.push_back(i);
		}
	}
	return allSequences_;
}

bool isCorrectSequenceLenght(int value) {
	return value >= 0 && value <= Characteristics::sequenceLength_;
}
