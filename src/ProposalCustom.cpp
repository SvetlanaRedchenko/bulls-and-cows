#include "ProposalCustom.h"

#include "Answer.h"

ProposalCustom::ProposalCustom(const Sequence& sequence)
	: ProposalInterface(), startSequence_(sequence) {
}

void ProposalCustom::initialize() {
}

Answer ProposalCustom::check(const Sequence& guess) {
	return checkSequence(startSequence_, guess);
}
