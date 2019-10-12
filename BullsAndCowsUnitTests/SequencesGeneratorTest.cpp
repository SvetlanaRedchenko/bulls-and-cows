#include "gtest/gtest.h"

#include <algorithm>

#include <src/SequencesContainer.h>
#include <src/SequencesGenerator.h>
#include <src/Symbol.h>

class SequencesGeneratorTest : public ::testing::Test {
public:
	SequencesGeneratorTest() {
		SequencesGenerator generator;
		generator.set(1, std::vector<Symbol>({ 'a' }));
		sequences_1_from_1 = generator.get();

		generator.set(4, std::vector<Symbol>({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }));
		sequences_4_from_10 = generator.get();

		generator.set(4, std::vector<Symbol>(
			{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' }));
		sequences_4_from_16 = generator.get();

		generator.set(2, std::vector<Symbol>({
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
			'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }));
		sequences_2_from_26 = generator.get();
	}

	~SequencesGeneratorTest() { }
	void SetUp() { }
	void TearDown() { }

protected:
	SequencesContainer sequences_1_from_1;
	SequencesContainer sequences_4_from_10;
	SequencesContainer sequences_4_from_16;
	SequencesContainer sequences_2_from_26;

	bool isContentUnique(const SequencesContainer& container) {
		std::list<Sequence> sequences = container.getForTest();
		const size_t size = sequences.size();

		sequences.sort();
		sequences.unique();

		return sequences.size() == size;
	}

	bool isSequencesUnique(const SequencesContainer& container) {
		for (auto sequence : container.getForTest()) {
			if (!isUnique(sequence))
				return false;
		}
		return true;
	}

	size_t countPermutationsWithoutRepetition(size_t length, size_t count) {
		size_t result = 1;
		for (size_t i = count - length + 1; i <= count; ++i) {
			result *= i;
		}
		return result;
	}
};

TEST_F(SequencesGeneratorTest, ContainerSize) {
	EXPECT_EQ(countPermutationsWithoutRepetition(1, 1), sequences_1_from_1.getForTest().size());
	EXPECT_EQ(countPermutationsWithoutRepetition(4, 10), sequences_4_from_10.getForTest().size());
	EXPECT_EQ(countPermutationsWithoutRepetition(4, 16), sequences_4_from_16.getForTest().size());
	EXPECT_EQ(countPermutationsWithoutRepetition(2, 26), sequences_2_from_26.getForTest().size());
}

TEST_F(SequencesGeneratorTest, UniqueContainerContent) {
	EXPECT_TRUE(isContentUnique(sequences_1_from_1));
	EXPECT_TRUE(isContentUnique(sequences_4_from_10));
	EXPECT_TRUE(isContentUnique(sequences_4_from_16));
	EXPECT_TRUE(isContentUnique(sequences_2_from_26));
}

TEST_F(SequencesGeneratorTest, UniqueSequences) {
	EXPECT_TRUE(isSequencesUnique(sequences_1_from_1));
	EXPECT_TRUE(isSequencesUnique(sequences_4_from_10));
	EXPECT_TRUE(isSequencesUnique(sequences_4_from_16));
	EXPECT_TRUE(isSequencesUnique(sequences_2_from_26));
}

