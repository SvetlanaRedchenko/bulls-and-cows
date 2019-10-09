#ifndef __ANSWER_H_
#define __ANSWER_H_

class Answer {
public:
	explicit Answer(size_t);

	void set(size_t, size_t);
	void incBull();
	void incCow();

	bool isWin() const;

	size_t getBulls() const;
	size_t getCows() const;
	size_t getLimit() const;

	bool operator==(const Answer&) const;
	bool operator!=(const Answer&) const;

private:
	size_t limit_;
	size_t bulls_;
	size_t cows_;
};

#endif
