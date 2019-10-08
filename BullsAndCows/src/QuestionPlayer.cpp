#include "QuestionPlayer.h"

#include "InputValidator.h"

Sequence QuestionPlayer::nextAttempt() {
	return getSequenceFromPlayer();
}

void QuestionPlayer::setAnswer(const Sequence&, const Answer&) {
}
