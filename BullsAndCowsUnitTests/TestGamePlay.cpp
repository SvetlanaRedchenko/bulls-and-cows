#include "gtest/gtest.h"

#include <src/Characteristics.h>
#include <src/Factory.h>
#include <src/Game.h>
#include <src/Sequence.h>
#include <src/SequencesContainer.h> 
#include <src/SequencesGenerator.h>

bool test(std::shared_ptr<ProposalInterface> proposal,
		std::shared_ptr<QuestionInterface> question) {
	return Game::play(proposal, question) > 0;
}

TEST(TestGamePlay, ComputerVsComputerEasy) {
	EXPECT_TRUE(test(Factory::getComputerProposal(),
		Factory::getComputerEasyQuestion()));
}

TEST(TestGamePlay, ComputerVsComputerHard) {
	EXPECT_TRUE(test(Factory::getComputerProposal(),
		Factory::getComputerHardQuestion()));
}

TEST(TestGamePlay, DISABLED_ComputerVsPlayer) {
	EXPECT_TRUE(test(Factory::getComputerProposal(),
		Factory::getPlayerQuestion()));
}

TEST(TestGamePlay, DISABLED_PlayerVsComputerEasy) {
	EXPECT_TRUE(test(Factory::getPlayerProposal(),
		Factory::getComputerEasyQuestion()));
}

TEST(TestGamePlay, DISABLED_PlayerVsComputerHard) {
	EXPECT_TRUE(test(Factory::getPlayerProposal(),
		Factory::getComputerHardQuestion()));
}

TEST(TestGamePlay, DISABLED_PlayerVsPlayer) {
	EXPECT_TRUE(test(Factory::getPlayerProposal(),
		Factory::getPlayerQuestion()));
}

TEST(TestGamePlay, DISABLED_ComputerVsComputerHardFull) {
	SequencesGenerator generator;
	generator.set(Characteristics::sequenceLength_, Characteristics::getSymbols());
	SequencesContainer allSequences = generator.get();

	const size_t count = allSequences.size();
	for (size_t i = 0; i < count; ++i) {
		const Sequence sequence = allSequences.extract(0);
		EXPECT_GT(Game::play(
			Factory::getTestProposal(sequence),
			Factory::getComputerHardQuestion()), 0);
	}
}
