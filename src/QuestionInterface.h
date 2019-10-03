#ifndef __QUESTIONINTERFACE_H_
#define __QUESTIONINTERFACE_H_

#include "DigitsSequence.h"

class QuestionInterface {
public:
	virtual DigitsSequence nextAttempt() = 0;
	virtual void setAnswer(const DigitsSequence&, const Answer&) = 0;
};

#endif
