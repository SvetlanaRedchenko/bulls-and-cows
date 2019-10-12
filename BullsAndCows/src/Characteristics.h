#ifndef __CHARACTERISTICS_H_
#define __CHARACTERISTICS_H_

#include <vector>

#include "Symbol.h"

// TODO: Singleton. Change values at runtime
class Characteristics {
public:
	static const size_t sequenceLength_ = 4;
	static std::vector<Symbol> getSymbols();
private:
	static std::vector<Symbol> symbols_;
};

#endif
