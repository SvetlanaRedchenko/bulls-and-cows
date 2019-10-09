#include "gtest/gtest.h"

#include <limits>
#include <src/Answer.h>

bool checkAnswer(const Answer& answer) {
	return answer.getBulls() + answer.getCows() <= answer.getLimit();
}

TEST(AnswerTest, CorrectEmptyAnswerForBoundaryValues) {
	Answer answer1(std::numeric_limits<size_t>::min());
	EXPECT_TRUE(checkAnswer(answer1));

	Answer answer2(std::numeric_limits<size_t>::max());
	EXPECT_TRUE(checkAnswer(answer2));
}

TEST(AnswerTest, IncrementalBulls) {
	Answer answer(std::numeric_limits<size_t>::max());
	const size_t times = 10;
	for (size_t i = 1; i <= times; ++i) {
		answer.incBull();
		EXPECT_EQ(i, answer.getBulls());
		EXPECT_EQ(0, answer.getCows());
		EXPECT_TRUE(checkAnswer(answer));
	}

	EXPECT_EQ(times, answer.getBulls());
	EXPECT_EQ(0, answer.getCows());

	EXPECT_TRUE(checkAnswer(answer));
}

TEST(AnswerTest, IncrementalCows) {
	Answer answer(std::numeric_limits<size_t>::max());
	const size_t times = 10;
	for (size_t i = 1; i <= times; ++i) {
		answer.incCow();
		EXPECT_EQ(i, answer.getCows());
		EXPECT_EQ(0, answer.getBulls());
		EXPECT_TRUE(checkAnswer(answer));
	}

	EXPECT_EQ(times, answer.getCows());
	EXPECT_EQ(0, answer.getBulls());
	EXPECT_TRUE(checkAnswer(answer));
}

TEST(AnswerTest, SetValues) {
	const size_t limit = 10;
	Answer answer(limit);

	answer.set(4, 2);

	EXPECT_EQ(4, answer.getBulls());
	EXPECT_EQ(2, answer.getCows());
	EXPECT_TRUE(checkAnswer(answer));

	answer.set(limit, limit);

	EXPECT_EQ(limit, answer.getBulls());
	EXPECT_EQ(limit, answer.getCows());
	EXPECT_FALSE(checkAnswer(answer));
}

TEST(AnswerTest, SetForBoundaryValues) {
	const size_t limit = 10;
	{
		Answer answer(limit);
		answer.set(limit, 0);
		EXPECT_TRUE(checkAnswer(answer));
	}
	{
		Answer answer(limit);
		answer.set(0, limit);
		EXPECT_TRUE(checkAnswer(answer));
	}
	{
		Answer answer(limit);
		answer.set(limit + 1, 0);
		EXPECT_FALSE(checkAnswer(answer));
	}
	{
		Answer answer(limit);
		answer.set(0, limit + 1);
		EXPECT_FALSE(checkAnswer(answer));
	}
	{
		Answer answer(limit);
		answer.set(limit, 1);
		EXPECT_FALSE(checkAnswer(answer));
	}
	{
		Answer answer(limit);
		answer.set(1, limit);
		EXPECT_FALSE(checkAnswer(answer));
	}
}

TEST(AnswerTest, Win) {
	const size_t limit = 10;
	Answer answer(limit);

	EXPECT_FALSE(answer.isWin());

	answer.set(limit, 0);
	EXPECT_TRUE(answer.isWin());

	answer.set(0, limit);
	EXPECT_FALSE(answer.isWin());
}

TEST(AnswerTest, Equals) {
	const size_t limit = 10;
	Answer answer1(limit), answer2(limit), answer3(limit + 1);

	EXPECT_TRUE(answer1 == answer1);
	EXPECT_FALSE(answer1 == answer3);

	EXPECT_FALSE(answer1 != answer1);
	EXPECT_TRUE(answer1 != answer3);

	answer1.set(limit, 0);
	answer2.set(0, limit);

	EXPECT_FALSE(answer1 == answer2);
	EXPECT_TRUE(answer1 != answer2);
}
