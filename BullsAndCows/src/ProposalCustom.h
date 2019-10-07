#ifndef __PROPOSALCUSTOM_H_
#define __PROPOSALCUSTOM_H_

#include "ProposalInterface.h"

class ProposalCustom : public ProposalInterface {
public:
	ProposalCustom(const Sequence&);

	virtual void initialize() override;
	virtual Answer check(const Sequence&) override;

private:
	Sequence startSequence_;
};

#endif
