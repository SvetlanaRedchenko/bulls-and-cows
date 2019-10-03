#ifndef __QUESTIONCOMPUTERRANDOM_H_
#define __QUESTIONCOMPUTERRANDOM_H_

#include "QuestionInterface.h"
#include "RandomSequence.h"

class QuestionComputerRandom : public QuestionInterface {
public:
	QuestionComputerRandom();

	virtual DigitsSequence nextAttempt() override;
	virtual void setAnswer(const DigitsSequence&, const Answer&) override;

private:
	RandomSequence generator_;
};

#endif
