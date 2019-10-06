#ifndef __SEQUENCE_H_
#define __SEQUENCE_H_

#include <string>
#include <vector>

#include "Symbol.h"

class Answer;

class Sequence {
public:
	Sequence();
	Sequence(const std::string&);

	std::string toString() const;

	friend Answer checkSequence(
		const Sequence&, const Sequence&);

private:
	std::vector<Symbol> symbols_;
};

#endif
