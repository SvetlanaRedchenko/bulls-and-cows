#include "SequencesGenerator.h"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

#include "Sequence.h"

SequencesGenerator::SequencesGenerator()
	: length_(0), symbols_(), container_() {
}

void SequencesGenerator::set(size_t length, const std::vector<Symbol>& symbols) {
	if (length_ != length || symbols_ != symbols) {
		length_ = length;
		symbols_ = symbols;
		container_ = SequencesContainer();
	}
	assert(length_ <= symbols_.size());
}

SequencesContainer SequencesGenerator::get() {
	if (container_.empty()) {
		std::vector<size_t> indexes(length_, 0);
		const size_t length = symbols_.size();
		do {
			std::string temp;
			std::vector<Symbol> permutation = symbols_;

			for (size_t i = 0; i < indexes.size(); ++i) {
				temp += permutation[indexes[i]];
				permutation.erase(permutation.begin() + indexes[i]);
			}
			container_.push_back(Sequence(temp));
		} while (nextPermutation(indexes, length));
	}
	return container_;
}

bool SequencesGenerator::nextPermutation(std::vector<size_t>& permutation, size_t n) const {
	for (int j = static_cast<int>(permutation.size()) - 1; j >= 0; --j) {
		if (permutation[j] < n - j - 1) {
			permutation[j]++;
			for (size_t i = j + 1; i < permutation.size(); ++i) {
				permutation[i] = 0;
			}
			return true;
		}
	}
	return false;
}
