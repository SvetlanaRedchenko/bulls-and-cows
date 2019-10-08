#ifndef __CHARACTERISTICS_H_
#define __CHARACTERISTICS_H_

#include <string>
#include <vector>

#include "Symbol.h"

class Sequence;
class SequencesContainer;

class Characteristics {
public:
	static const size_t sequenceLength_ = 4;

	static std::vector<Symbol> getSymbols();
	static SequencesContainer getAllSequences();

	static bool isCorrectSymbol(Symbol);

private:
	static std::vector<Symbol> symbols_;
	static SequencesContainer allSequences_;
};

bool isCorrectBullsOrCowsValue(int);
std::string getSymbolsAsString();

#endif
