#include "Characteristics.h"

#include <algorithm>
#include <string>
#include <vector>

#include "Sequence.h"
#include "SequencesContainer.h"

namespace {
	bool nextPermutationWithReplace(std::vector<size_t>& permutation, size_t n) {
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

	// Алгоритм Нараяны для генерации следующей перестановки в лексографическом порядке
	bool nextPermutation(std::vector<size_t>& permutation) {
		for (int j = static_cast<int>(permutation.size()) - 2; j >= 0; --j) {
			if (permutation[j] < permutation[j + 1]) {
				size_t max_l = j;
				for (size_t l = max_l; l < permutation.size(); ++l) {
					if (permutation[l] > permutation[j])
						max_l = l;
				}
				std::swap(permutation[j], permutation[max_l]);
				std::reverse(permutation.begin() + j + 1, permutation.end());
				return true;
			}
		}
		return false;
	}

}

SequencesContainer Characteristics::allSequences_;
std::vector<Symbol> Characteristics::symbols_;

SequencesContainer Characteristics::getAllSequences() {
	if (allSequences_.empty()) {
		std::vector<size_t> indexes(Characteristics::sequenceLength_, 0);
		const size_t length = Characteristics::getSymbols().size();
		do {
			std::string temp;
			std::vector<Symbol> permutation = Characteristics::getSymbols();

			for (size_t i = 0; i < indexes.size(); ++i) {
				temp += permutation[indexes[i]];
				permutation.erase(permutation.begin() + indexes[i]);
			}
			allSequences_.push_back(Sequence(temp));
		} while (nextPermutationWithReplace(indexes, length));
	}
	return allSequences_;
}

bool Characteristics::isCorrectSymbol(Symbol symbol) {
	return std::find(
		symbols_.begin(),
		symbols_.end(),
		symbol) != symbols_.end();
}

std::vector<Symbol> Characteristics::getSymbols() {
	if (symbols_.empty()) {
		symbols_ = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		std::sort(symbols_.begin(), symbols_.end());
	}
	return symbols_;
}

bool isCorrectBullsOrCowsValue(int value) {
	return value >= 0 && value <= Characteristics::sequenceLength_;
}
