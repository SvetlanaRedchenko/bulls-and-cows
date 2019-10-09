#include "Game.h"

#include <cassert>
#include <iostream>

#include "Answer.h"
#include "Characteristics.h"
#include "Helper.h"
#include "ProposalInterface.h"
#include "QuestionInterface.h"

int Game::play(
	    std::shared_ptr<ProposalInterface> proposal,
        std::shared_ptr<QuestionInterface> question) {
	assert(proposal);
	assert(question);

	int step = 0;
	proposal->initialize();
	Answer answer(Characteristics::sequenceLength_);
	do {
		const Sequence sequence = question->nextAttempt();
		std::cout << sequence.toString() << "?" << std::endl;
		answer = proposal->check(sequence);
		std::cout << "For " << sequence.toString() << " : " << toString(answer) << std::endl;
		question->setAnswer(sequence, answer);
		++step;
	} while (!answer.isWin());

	return step;
}
