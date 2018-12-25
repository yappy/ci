#include <gtest/gtest.h>
#include "../src/sample.h"

using namespace sample;

TEST(SampleTest, Simple) {
	EXPECT_EQ(9, sample1(2, 7));
}

TEST(SampleTest2, Simple) {
	EXPECT_EQ(14, sample2(2, 7));
}
