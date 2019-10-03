#include "Game.h"

#include <cassert>

#include "Characteristics.h"
#include "ProposalInterface.h"
#include "QuestionInterface.h"

int Game::play(
	    std::shared_ptr<ProposalInterface> proposal,
        std::shared_ptr<QuestionInterface> question) {
	assert(proposal);
	assert(question);

	int step = 0;
	proposal->initialize();
	Answer answer;
	do {
		DigitsSequence sequence = question->nextAttempt();
		answer = proposal->check(sequence);
		question->setAnswer(sequence, answer);
		++step;
	} while (!answer.isWin());

	return step;
}
