//
// Created by David Wang on 24-11-16.
//

#include "BinaryTricky.h"
#include <gtest/gtest.h>

TEST(BinaryTricky, TwoTimesPlusOne)
{
    EXPECT_EQ(1, TwoTimesPlusOne(0));
    EXPECT_EQ(3, TwoTimesPlusOne(1));
    EXPECT_EQ(5, TwoTimesPlusOne(2));
    EXPECT_EQ(7, TwoTimesPlusOne(3));
    EXPECT_EQ(9, TwoTimesPlusOne(4));
    EXPECT_EQ(11, TwoTimesPlusOne(5));
}

TEST(BinaryTricky, IsPowerOfTwo)
{
    EXPECT_FALSE(IsPowerOfTwo(0));
    EXPECT_TRUE(IsPowerOfTwo(1));
    EXPECT_TRUE(IsPowerOfTwo(2));
    EXPECT_FALSE(IsPowerOfTwo(3));
    EXPECT_TRUE(IsPowerOfTwo(4));
}

TEST(BinaryTricky, IsPowerOfTwoOrZero)
{
    EXPECT_TRUE(IsPowerOfTwoOrZero(0));
    EXPECT_TRUE(IsPowerOfTwoOrZero(1));
    EXPECT_TRUE(IsPowerOfTwoOrZero(2));
    EXPECT_FALSE(IsPowerOfTwoOrZero(3));
    EXPECT_TRUE(IsPowerOfTwoOrZero(4));
}

TEST(BinaryTricky, CountOnes)
{
    EXPECT_EQ(0, CountOnes(0b0));
    EXPECT_EQ(1, CountOnes(0b1));
    EXPECT_EQ(7, CountOnes(0b10111111));
    EXPECT_EQ(8, CountOnes(0xff));
}

TEST(BinaryTricky, RoundUpToNextPowerOfTwo)
{
    EXPECT_EQ(0b100, RoundUpToNextPowerOfTwo(0b100));
    EXPECT_EQ(0b1000, RoundUpToNextPowerOfTwo(0b101));
    // unsigened long 边界值
    EXPECT_EQ(4294967296, RoundUpToNextPowerOfTwo(4294967295));
}
