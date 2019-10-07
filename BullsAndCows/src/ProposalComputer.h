#ifndef __PROPOSALCOMPUTER_H_
#define __PROPOSALCOMPUTER_H_

#include "ProposalInterface.h"

class ProposalComputer : public ProposalInterface {
public:
	ProposalComputer();

	virtual void initialize() override;
	virtual Answer check(const Sequence&) override;

private:
	Sequence startSequence_;
};

#endif
