#include "InputValidator.h"

#include <cassert>
#include <iostream>
#include <limits>
#include <set>

#include "Characteristics.h"

namespace {
	bool isStringContainsCorrectNumber(const std::string& str) {
		std::set<char> digits;
		for (auto c : str) {
			if (isdigit(c))
				digits.insert(c);
			else return false;
		}
		return digits.size() == Characteristics::sequenceLength_;
	}
}

DigitsSequence getDigitsSequenceFromPlayer() {
	std::string input;
	do {
		std::cout << "Please, enter a four-digit number: ";
		std::cin >> input;

	} while (!isStringContainsCorrectNumber(input));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return DigitsSequence(input);
}

int getCountBullsOrCowsFromPlayer(const std::string& message) {
	int result = -1;
	do {
		std::cout << message;
		std::cin >> result;
		if (std::cin.fail()) {
			std::cin.clear();
			result = -1;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!isCorrectSequenceLenght(result));
	return result;
}
