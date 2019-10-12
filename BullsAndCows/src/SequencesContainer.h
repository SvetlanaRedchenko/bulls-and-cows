#ifndef __SEQUENCESCONTAINER_H_
#define __SEQUENCESCONTAINER_H_

#include <list>

#include "Sequence.h"

class Answer;

class SequencesContainer {
public:
	SequencesContainer();

	size_t size() const;
	bool empty() const;
	void push_back(const Sequence&);
	Sequence extract(size_t);
	void sieve(const Sequence& sequence, const Answer& result);

	const std::list<Sequence>& getForTest() const;
private:
	std::list<Sequence> container_;
};

#endif
