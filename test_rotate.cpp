#include "hlrotate.h"

#include "gtest/gtest.h"

#include <random>

TEST(RotateTest, basic_rotl_u16_tests)
{
    uint16_t test1 = 1;
    test1 = rotateLeft(test1);
    EXPECT_EQ(2, test1);

    uint16_t test2 = 1 << 14;
    test2 = rotateLeft(test2);
    EXPECT_EQ(1 + 0xFFFF/2, test2);

    uint16_t test3 = 1 << 15;
    test3 = rotateLeft(test3);
    EXPECT_EQ(1, test3);

    uint16_t test4 = 0xFFFE;
    test4 = rotateLeft(test4);
    test4 = rotateLeft(test4);
    test4 = rotateLeft(test4);
    EXPECT_EQ(0xFFF7, test4);
}

TEST(RotateTest, basic_rotr_u16_tests)
{
    uint16_t test1 = 1;
    test1 = rotateRight(test1);
    EXPECT_EQ(1 + 0xFFFF/2, test1);

    uint16_t test2 = 1 << 15;
    test2 = rotateRight(test2);
    EXPECT_EQ(1 << 14, test2);

    uint16_t test3 = 2;
    test3 = rotateRight(test3);
    EXPECT_EQ(1, test3);

    uint16_t test4 = 0x7FFF;
    test4 = rotateRight(test4);
    test4 = rotateRight(test4);
    test4 = rotateRight(test4);
    EXPECT_EQ(0xEFFF, test4);
}

TEST(RotateTest, rotl_and_rotr_u16_interop_tests)
{
    uint16_t const initial = 0xFF7D;
    uint16_t rightRot = rotateRight(initial);
    uint16_t leftRot = rotateLeft(rightRot);
    EXPECT_EQ(initial, leftRot);
    EXPECT_NE(rightRot,  leftRot);

    constexpr auto RIGHT_AMT = 9;
    for (auto i = 0; i < RIGHT_AMT; i++)
    {
        rightRot = rotateRight(rightRot);
    }

    constexpr auto LEFT_AMT = RIGHT_AMT + 1;
    for (auto i = 0; i < LEFT_AMT; i++)
    {
        rightRot = rotateLeft(rightRot);
    }
    EXPECT_EQ(rightRot, leftRot);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
