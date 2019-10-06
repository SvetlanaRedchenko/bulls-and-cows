#ifndef __SEQUENCESCONTAINER_H_
#define __SEQUENCESCONTAINER_H_

#include <list>

class Answer;
class Sequence;

class SequencesContainer {
public:
	SequencesContainer();

	size_t size() const;
	bool empty() const;
	void push_back(const Sequence&);
	Sequence extract(size_t);
	void sieve(const Sequence& sequence, const Answer& result);
private:
	std::list<Sequence> container_;
};

#endif
