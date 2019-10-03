#ifndef __QUESTIONPLAYER_H_
#define __QUESTIONPLAYER_H_

#include "QuestionInterface.h"

class QuestionPlayer : public QuestionInterface {
	virtual DigitsSequence nextAttempt() override;
	virtual void setAnswer(const DigitsSequence&, const Answer&) override;
};

#endif
