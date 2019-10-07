#include "QuestionPlayer.h"

#include <iostream>

#include "Answer.h"
#include "InputValidator.h"

Sequence QuestionPlayer::nextAttempt() {
	return getSequenceFromPlayer();
}

void QuestionPlayer::setAnswer(const Sequence& , const Answer& answer) {
	std::cout << answer.toString() << std::endl;
}
