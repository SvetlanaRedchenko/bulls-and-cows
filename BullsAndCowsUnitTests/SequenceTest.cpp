#include "gtest/gtest.h"

#include <src/Answer.h>
#include <src/Sequence.h>

bool CheckToString(const std::string& sequence) {
	return (sequence == toString(sequence));
}

TEST(SequenceTest, Equals) {
	const Sequence sequence1("13579");
	const Sequence sequence2(sequence1);
	EXPECT_TRUE(sequence1 == sequence1);
	EXPECT_TRUE(sequence1 == sequence2);
	EXPECT_TRUE(sequence2 == sequence1);

	EXPECT_FALSE(sequence1 == Sequence("135790"));
	EXPECT_FALSE(sequence1 == Sequence("97531"));
}

TEST(SequenceTest, LessThen) {
	const Sequence sequence1("13579");

	EXPECT_FALSE(sequence1 < sequence1);

	const Sequence sequence2("13580");
	EXPECT_TRUE(sequence1 < sequence2);
	EXPECT_FALSE(sequence2 < sequence1);

	const Sequence sequence3("");
	EXPECT_TRUE(sequence3 < sequence1);
	EXPECT_TRUE(sequence3 < sequence2);

	const Sequence sequence4("024689");
	EXPECT_TRUE(sequence1 < sequence4);
	EXPECT_TRUE(sequence2 < sequence4);
	EXPECT_TRUE(sequence3 < sequence4);
}

TEST(SequenceTest, Check) {
	{
		const Sequence s1("2468"), s2("2468");
		Answer answer(4);
		answer.set(4, 0);
		EXPECT_EQ(checkSequence(s1, s2), answer);
		EXPECT_EQ(checkSequence(s1, s2), checkSequence(s2, s1));
	}
	{
		const Sequence s1("1234"), s2("5678");
		Answer answer(4);
		answer.set(0, 0);
		EXPECT_EQ(checkSequence(s1, s2), answer);
		EXPECT_EQ(checkSequence(s1, s2), checkSequence(s2, s1));
	}
	{
		const Sequence s1("1234"), s2("4321");
		Answer answer(4);
		answer.set(0, 4);
		EXPECT_EQ(checkSequence(s1, s2), answer);
		EXPECT_EQ(checkSequence(s1, s2), checkSequence(s2, s1));
	}
}

TEST(SequenceTest, Unique) {
	EXPECT_TRUE(isUnique(Sequence("")));
	EXPECT_TRUE(isUnique(Sequence("1024")));

	EXPECT_FALSE(isUnique(Sequence("0000")));
	EXPECT_FALSE(isUnique(Sequence("111222")));
	EXPECT_FALSE(isUnique(Sequence("12341")));
}

TEST(SequenceTest, ToString) {
	EXPECT_TRUE(CheckToString(""));
	EXPECT_TRUE(CheckToString("A"));
	EXPECT_TRUE(CheckToString("1024"));
	EXPECT_TRUE(CheckToString("0000"));
	EXPECT_TRUE(CheckToString("0123456789"));
	EXPECT_TRUE(CheckToString("0123456789abcdef"));
	EXPECT_TRUE(CheckToString("abcdefghijklmnopqrstuvwxyz"));
}
