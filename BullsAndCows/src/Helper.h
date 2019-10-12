#ifndef __HELPER_H_
#define __HELPER_H

#include <string>
#include <vector>

#include "Symbol.h"

class Answer;

std::string toString(const Answer&);
std::string toString(const std::vector<Symbol>&);

bool isCorrectSymbol(Symbol, const std::vector<Symbol>&);

#endif
