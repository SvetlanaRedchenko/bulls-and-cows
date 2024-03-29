#ifndef __FACTORY_H_
#define __FACTORY_H_

#include <memory>

class QuestionInterface;
class ProposalInterface;
class Sequence;

class Factory {
public:
	static std::shared_ptr<ProposalInterface> getComputerProposal();
	static std::shared_ptr<ProposalInterface> getPlayerProposal();
	static std::shared_ptr<ProposalInterface> getTestProposal(const Sequence&);

	static std::shared_ptr<QuestionInterface> getPlayerQuestion();
	static std::shared_ptr<QuestionInterface> getComputerEasyQuestion();
	static std::shared_ptr<QuestionInterface> getComputerHardQuestion();
};

#endif
