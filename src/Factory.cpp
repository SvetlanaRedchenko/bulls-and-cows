#include "Factory.h"

#include "ProposalComputer.h"
#include "ProposalCustom.h"
#include "ProposalPlayer.h"
#include "QuestionComputerRandom.h"
#include "QuestionComputerSmart.h"
#include "QuestionPlayer.h"
#include "Sequence.h"

std::shared_ptr<ProposalInterface> Factory::getComputerProposal() {
	return std::shared_ptr<ProposalInterface>(new ProposalComputer());
}

std::shared_ptr<ProposalInterface> Factory::getPlayerProposal() {
	return std::shared_ptr<ProposalInterface>(new ProposalPlayer());
}

std::shared_ptr<ProposalInterface> Factory::getTestProposal(const Sequence& sequence) {
	return std::shared_ptr<ProposalInterface>(new ProposalCustom(sequence));
}

std::shared_ptr<QuestionInterface> Factory::getPlayerQuestion() {
	return std::shared_ptr<QuestionInterface>(new QuestionPlayer());
}

std::shared_ptr<QuestionInterface> Factory::getComputerEasyQuestion() {
	return std::shared_ptr<QuestionInterface>(new QuestionComputerRandom());
}

std::shared_ptr<QuestionInterface> Factory::getComputerHardQuestion() {
	return std::shared_ptr<QuestionInterface>(new QuestionComputerSmart());
}
