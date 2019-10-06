#ifndef __PROPOSALINTERFACE_H_
#define __PROPOSALINTERFACE_H_

#include "Sequence.h"

class ProposalInterface {
public:
	virtual void initialize() = 0;
	virtual Answer check(const Sequence&) = 0;
};

#endif
