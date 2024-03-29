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

	bool operator==(const Sequence&) const;
	bool operator<(const Sequence&) const;

	friend Answer checkSequence(
		const Sequence&, const Sequence&);
	friend bool isUnique(Sequence);
	friend std::string toString(const Sequence&);

private:
	std::vector<Symbol> symbols_;
};

#endif
