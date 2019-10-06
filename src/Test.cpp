#include "Test.h"

#include <iostream>

#include "Characteristics.h"
#include "Factory.h"
#include "Game.h"
#include "Sequence.h"
#include "SequencesContainer.h" 

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
	SequencesContainer allSequences = Characteristics::getAllSequences();
	const size_t count = allSequences.size();
	int max = 0;
	for (size_t i = 0; i < count; ++i) {
		const Sequence sequence = allSequences.extract(0);
		int step = Game::play(
			Factory::getTestProposal(sequence),
			Factory::getComputerHardQuestion());
		max = step > max ? step : max;
		std::cout << sequence.toString() << " " << step << std::endl;
	}
	std::cout << "Test: " << count << " mathes, max step " << max << std::endl;
}
