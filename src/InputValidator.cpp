#include "InputValidator.h"

#include <cassert>
#include <iostream>
#include <limits>
#include <set>

#include "Characteristics.h"
#include "Sequence.h"

namespace {
	bool isStringContainsCorrectSequence(const std::string& str) {
		std::set<Symbol> symbols;
		for (auto c : str) {
			if (Characteristics::isCorrectSymbol(c))
				symbols.insert(c);
			else return false;
		}
		return symbols.size() == Characteristics::sequenceLength_;
	}

	std::string toString(const std::vector<Symbol>& vec) {
		std::string symbols("[");
		for (auto c : vec) {
			symbols += c;
			symbols += ' ';
		}
		symbols += "]";
		return symbols;
	}
}

Sequence getSequenceFromPlayer() {
	std::string input;
	do {
		std::cout << "Please, enter " << Characteristics::sequenceLength_ << " unique symbols from "
			<< toString(Characteristics::getSymbols()) << std::endl;
		std::cin >> input;

	} while (!isStringContainsCorrectSequence(input));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return Sequence(input);
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
	} while (!isCorrectBullsOrCowsValue(result));
	return result;
}
