#ifndef __PROPOSALINTERFACE_H_
#define __PROPOSALINTERFACE_H_

#include "Answer.h"
#include "DigitsSequence.h"

class ProposalInterface {
public:
	virtual void initialize() = 0;
	virtual Answer check(const DigitsSequence&) = 0;
};

#endif
