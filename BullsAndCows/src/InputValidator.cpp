#include "InputValidator.h"

#include <cassert>
#include <iostream>
#include <limits>
#include <set>

#include "Characteristics.h"
#include "Helper.h"
#include "Sequence.h"

namespace {
	bool isStringContainsCorrectSequence(const std::string& str) {
		std::set<Symbol> symbols;
		for (auto c : str) {
			if (isCorrectSymbol(c, Characteristics::getSymbols()))
				symbols.insert(c);
			else return false;
		}
		return symbols.size() == Characteristics::sequenceLength_;
	}
}

Sequence getSequenceFromPlayer() {
	std::string input;
	do {
		std::cout << "Please, enter You sequence" << std::endl;
		std::cin >> input;

	} while (!isStringContainsCorrectSequence(input));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return Sequence(input);
}

int getNumberFromPlayer(const std::string& message, int min, int max) {
	assert(min <= max);
	int result = -1;
	do {
		std::cout << message << std::endl;
		std::cin >> result;
		if (std::cin.fail()) {
			std::cin.clear();
			result = -1;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (result < min || result > max);
	return result;
}
