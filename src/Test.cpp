#include "Test.h"

#include <iostream>

#include "Characteristics.h"
#include "Factory.h"
#include "Game.h"
#include "Helper.h"
#include "InputValidator.h"

namespace {
	void test(const std::string& message,
    		std::shared_ptr<ProposalInterface> proposal,
	    	std::shared_ptr<QuestionInterface> question) {
		std::cout << std::endl << "Test: " << message << std::endl;
		const int step = Game::play(
			proposal,
			question);
		std::cout << "Test: step = " << step << std::endl;

	}
};

void testComputerVsComputerEasy() {
	test("Computer VS Computer (easy)",
		Factory::getComputerProposal(),
		Factory::getComputerEasyQuestion());
}

void testComputerVsComputerHard() {
	test("Computer VS Computer (hard)",
		Factory::getComputerProposal(),
		Factory::getComputerHardQuestion());
}

void testComputerVsPlayer() {
	test("Computer VS Player",
		Factory::getComputerProposal(),
		Factory::getPlayerQuestion());
}

void testPLayerVsComputerEasy() {
	test("Player VS Computer (Easy)",
		Factory::getPlayerProposal(),
		Factory::getComputerEasyQuestion());
}

void testPlayerVsComputerHard() {
	test("Player VS Computer (Hard)",
		Factory::getPlayerProposal(),
		Factory::getComputerHardQuestion());
}

void testPlayerVsPlayer() {
	test("Player VS Player",
		Factory::getPlayerProposal(),
		Factory::getPlayerQuestion());
}

void testComputerFullHard() {
	int max = 0;
	int count = 0;
	for (int i = 0; i < Characteristics::maxSequenceCount_; i++) {
		if (isDigitsUnique(static_cast<int>(i))) {
			int step = Game::play(
				Factory::getTestProposal(i),
				Factory::getComputerHardQuestion());
			max = step > max ? step : max;
			count++;
			std::cout << i << " " << step << std::endl;
		}
	}
	std::cout << "Test: " << count << " mathes, max step " << max << std::endl;
}
