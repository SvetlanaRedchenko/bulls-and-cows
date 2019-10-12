#include "Characteristics.h"

#include <algorithm>

std::vector<Symbol> Characteristics::symbols_;

std::vector<Symbol> Characteristics::getSymbols() {
	if (symbols_.empty()) {
		symbols_ = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		std::sort(symbols_.begin(), symbols_.end());
		auto end = std::unique(symbols_.begin(), symbols_.end());
		symbols_.resize(std::distance(symbols_.begin(), end));
	}
	return symbols_;
}
