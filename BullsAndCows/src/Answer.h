#ifndef __ANSWER_H_
#define __ANSWER_H_

#include <string>

class Answer {
public:
	Answer();
	Answer(int bulls, int cows);

	bool isWin() const;
	void addBull();
	void addCow();
	bool operator==(const Answer&) const;
	bool operator!=(const Answer&) const;

	std::string toString() const;
private:
	int bulls_;
	int cows_;
};

#endif
