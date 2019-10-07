#ifndef __PROPOSALPLAYER_H_
#define __PROPOSALPLAYER_H_

#include "ProposalInterface.h"

class ProposalPlayer : public ProposalInterface {
public:
	ProposalPlayer();

	virtual void initialize() override;
	virtual Answer check(const Sequence&) override;
};

#endif
