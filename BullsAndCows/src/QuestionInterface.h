#ifndef __QUESTIONINTERFACE_H_
#define __QUESTIONINTERFACE_H_

#include "Sequence.h"

class QuestionInterface {
public:
	virtual Sequence nextAttempt() = 0;
	virtual void setAnswer(const Sequence&, const Answer&) = 0;
};

#endif
