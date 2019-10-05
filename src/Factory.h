#ifndef __FACTORY_H_
#define __FACTORY_H_

#include <memory>

class DigitsSequence;
class QuestionInterface;
class ProposalInterface;

class Factory {
public:
	static std::shared_ptr<ProposalInterface> getComputerProposal();
	static std::shared_ptr<ProposalInterface> getPlayerProposal();
	static std::shared_ptr<ProposalInterface> getTestProposal(const DigitsSequence&);

	static std::shared_ptr<QuestionInterface> getPlayerQuestion();
	static std::shared_ptr<QuestionInterface> getComputerEasyQuestion();
	static std::shared_ptr<QuestionInterface> getComputerHardQuestion();
};

#endif
