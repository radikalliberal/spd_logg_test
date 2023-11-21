#include "gtest/gtest.h"

TEST(testsuite, really)
{
    EXPECT_EQ(1000, 500 + 500);	
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}