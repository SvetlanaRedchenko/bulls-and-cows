#include "gtest/gtest.h"

#include <src/Answer.h>

class TestAnswer : public ::testing::Test {
public:
	TestAnswer() { /* init protected members here */ }
	~TestAnswer() { /* free protected members here */ }
	void SetUp() { /* called before every test */ }
	void TearDown() { /* called after every test */ }

protected:
	/* none yet */
};

TEST_F(TestAnswer, EqualsAnswerByDefault) {
	Answer a1, a2;
	ASSERT_EQ(a1, a2);
}
