#ifndef __DIGITSSEQUENCE_H_
#define __DIGITSSEQUENCE_H_

#include <string>
#include <vector>

#include "Answer.h"

using Digit = unsigned int;

class DigitsSequence {
public:
	DigitsSequence();
	DigitsSequence(int);
	DigitsSequence(const std::string&);

	std::string toString() const;

	friend Answer checkDigitsSequence(
		const DigitsSequence&, const DigitsSequence&);

private:
	std::vector<Digit> digits_;
};

#endif
