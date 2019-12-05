#include <myClass.h>
#include <gtest/gtest.h>

TEST(first_test, first_subtest) {
	ASSERT_EQ("apple", getApple());
}
