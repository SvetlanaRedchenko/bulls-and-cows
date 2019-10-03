#ifndef __SEQUENCESCONTAINER_H_
#define __SEQUENCESCONTAINER_H_

#include <list>

#include "Answer.h"
#include "DigitsSequence.h"

class SequencesContainer {
public:
	SequencesContainer();

	size_t size() const;
	bool empty() const;
	void push_back(const DigitsSequence&);
	DigitsSequence extract(size_t);
	void sieve(const DigitsSequence& sequence, const Answer& result);

private:
	std::list<DigitsSequence> container_;
};

#endif
