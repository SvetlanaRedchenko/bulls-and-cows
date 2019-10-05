#include "ProposalCustom.h"

ProposalCustom::ProposalCustom(const DigitsSequence& sequence)
	: ProposalInterface(), startSequence_(sequence) {
}

void ProposalCustom::initialize() {
}

Answer ProposalCustom::check(const DigitsSequence& guess) {
	return checkDigitsSequence(startSequence_, guess);
}
