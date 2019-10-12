#ifndef __SEQUENCESGENERATOR_H_
#define __SEQUENCESGENERATOR_H_

#include <vector>

#include "SequencesContainer.h"
#include "Symbol.h"

class SequencesGenerator
{
public:
	SequencesGenerator();

	void set(size_t, const std::vector<Symbol>&);
	SequencesContainer get();
private:
	size_t length_;
	std::vector<Symbol> symbols_;
	SequencesContainer container_;

	bool nextPermutation(std::vector<size_t>&, size_t) const;
};

#endif
