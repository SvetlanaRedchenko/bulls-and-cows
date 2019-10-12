#include "Game.h"

#include <iostream>

#include "Answer.h"
#include "Characteristics.h"
#include "Helper.h"
#include "ProposalInterface.h"
#include "QuestionInterface.h"

int Game::play(
	    std::shared_ptr<ProposalInterface> proposal,
        std::shared_ptr<QuestionInterface> question) {
	if (!(proposal && question)) {
		return 0;
	}

	int step = 0;
	proposal->initialize();
	Answer answer(Characteristics::sequenceLength_);
	do {
		const Sequence sequence = question->nextAttempt();
		std::cout << toString(sequence) << "?" << std::endl;
		answer = proposal->check(sequence);
		std::cout << "For " << toString(sequence) << " : " << toString(answer) << std::endl;
		question->setAnswer(sequence, answer);
		++step;
	} while (!answer.isWin());

	return step;
}
