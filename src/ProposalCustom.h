#ifndef __PROPOSALCUSTOM_H_
#define __PROPOSALCUSTOM_H_

#include "ProposalInterface.h"

class ProposalCustom : public ProposalInterface {
public:
	ProposalCustom(int);

	virtual void initialize() override;
	virtual Answer check(const DigitsSequence&) override;

private:
	DigitsSequence startSequence_;
};

#endif
