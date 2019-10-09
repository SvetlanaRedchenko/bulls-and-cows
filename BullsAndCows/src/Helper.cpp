#include "Helper.h"

#include <sstream>

#include "Answer.h"

std::string toString(const Answer& answer) {
	std::ostringstream oss;
	oss << "bulls = " << answer.getBulls() << ", cows = " << answer.getCows();
	return oss.str();
}
