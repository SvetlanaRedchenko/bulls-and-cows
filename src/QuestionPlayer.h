#ifndef __QUESTIONPLAYER_H_
#define __QUESTIONPLAYER_H_

#include "QuestionInterface.h"

class QuestionPlayer : public QuestionInterface {
	virtual Sequence nextAttempt() override;
	virtual void setAnswer(const Sequence&, const Answer&) override;
};

#endif
