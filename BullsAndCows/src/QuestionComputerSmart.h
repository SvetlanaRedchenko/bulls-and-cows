#ifndef __QUESTIONCOMPUTERSMART_H_
#define __QUESTIONCOMPUTERSMART_H_

#include "QuestionInterface.h"
#include "Random.h"
#include "SequencesContainer.h"

class QuestionComputerSmart : public QuestionInterface {
public:
	QuestionComputerSmart();

	virtual Sequence nextAttempt() override;
	virtual void setAnswer(const Sequence&, const Answer&) override;

private:
	Random generator_;

	SequencesContainer sequencesForChoose_;
};

#endif
