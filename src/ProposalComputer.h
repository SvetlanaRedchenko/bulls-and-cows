#ifndef __PROPOSALCOMPUTER_H_
#define __PROPOSALCOMPUTER_H_

#include "ProposalInterface.h"

class ProposalComputer : public ProposalInterface {
public:
	ProposalComputer();

	virtual void initialize() override;
	virtual Answer check(const DigitsSequence&) override;

private:
	DigitsSequence startSequence_;
};

#endif
