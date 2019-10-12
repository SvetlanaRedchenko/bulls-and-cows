#include "Helper.h"

#include <sstream>

#include "Answer.h"

std::string toString(const Answer& answer) {
	std::ostringstream oss;
	oss << "bulls = " << answer.getBulls() << ", cows = " << answer.getCows();
	return oss.str();
}

std::string toString(const std::vector<Symbol>& param) {
	std::string symbols("[ ");
	for (auto c : param) {
		symbols += c;
		symbols += ' ';
	}
	symbols += "]";
	return symbols;
}

bool isCorrectSymbol(Symbol symbol, const std::vector<Symbol>& symbols) {
	return std::find(
		symbols.begin(),
		symbols.end(),
		symbol) != symbols.end();
}