#include "QuestionPlayer.h"

#include <iostream>

#include "InputValidator.h"

DigitsSequence QuestionPlayer::nextAttempt() {
	return getDigitsSequenceFromPlayer();
}

void QuestionPlayer::setAnswer(const DigitsSequence& , const Answer& answer) {
	std::cout << answer.toString() << std::endl;
}
