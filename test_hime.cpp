#include "hime.h"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"

#include <random>

TEST(HimeTest, deep_verify_check_sub_07_b97a_part_1)
{
    codeArray7e1680[0] = 0x3913; // で(unicode)
    codeArray7e1680[2] = 0x002A; // れ(unicode)
    codeArray7e1680[4] = 0x000D; // す(unicode)
    codeArray7e1680[6] = 0x3912; // づ(unicode)
    codeArray7e1680[8] = 0x3912; // づ(unicode)

    codeArray7e1680[10] = 0x001D; // へ(unicode)
    codeArray7e1680[12] = 0x3A1A; // ぱ(unicode)
    codeArray7e1680[14] = 0x001F; // ま(unicode)
    codeArray7e1680[16] = 0x0009; // け(unicode)
    codeArray7e1680[18] = 0x390C; // じ(unicode)

    codeArray7e1680[20] = 0x3912; // づ(unicode)
    codeArray7e1680[22] = 0x0003; // う(unicode)
    codeArray7e1680[24] = 0x000A; // こ(unicode)
    codeArray7e1680[26] = 0x3912; // づ(unicode)
    codeArray7e1680[28] = 0x3A1B; // ぴ(unicode)

    codeArray7e1680[30] = 0x000F; // そ(unicode)
    codeArray7e1680[32] = 0x0021; // む(unicode)
    codeArray7e1680[34] = 0x0019; // の(unicode)
    codeArray7e1680[36] = 0x0008; // く(unicode)
    codeArray7e1680[38] = 0x0008; // く(unicode)

    codeArray7e1680[40] = 0x0028; // り(unicode)
    codeArray7e1680[42] = 0x0025; // ゆ(unicode)
    codeArray7e1680[44] = 0x0021; // む(unicode)
    codeArray7e1680[46] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[48] = 0x0021; // む(unicode)

    codeArray7e1680[50] = 0x3913; // で(unicode)
    codeArray7e1680[52] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[54] = 0x0019; // の(unicode)
    codeArray7e1680[56] = 0x0001; // あ(unicode)
    codeArray7e1680[58] = 0x390B; // ざ(unicode)

    codeArray7e1680[60] = 0x390D; // ず(unicode)
    codeArray7e1680[62] = 0x003F;

    bool ret = check_sub_07_b97a(DEBUG_VERIFY_LEVEL_1);
    EXPECT_FALSE(ret);

    /* 7e1640
    39 2A 0C 38 38 1C 3B 1E 08 32 38 02 09 38 3C 0E
    20 18 07 07 28 24 20 3C 20 39 3C 18 00 31 33 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    13 39 2A 00 0D 00 12 39 12 39 1D 00 1A 3A 1F 00
    09 00 0C 39 12 39 03 00 0A 00 12 39 1B 3A 0F 00
    21 00 19 00 08 00 08 00 28 00 25 00 21 00 1B 3A
    21 00 13 39 1B 3A 19 00 01 00 0B 39 0D 39 3F 00
    3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00
    3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00
    3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00 3F 00
    3F 00 3F 00 3F 00 3F 00 3F 00 00 00 00 00 00 00
    */
    hime_t expectedNotsure7e1640[] = {0x39, 0x2a, 0x0c, 0x38, 0x38, 0x1C, 0x3B, 0x1E,
                                      0x08, 0x32, 0x38, 0x02, 0x09, 0x38, 0x3C, 0x0E,
                                      0x20, 0x18, 0x07, 0x07, 0x28, 0x24, 0x20, 0x3C,
                                      0x20, 0x39, 0x3C, 0x18, 0x00, 0x31, 0x33, 0x00};
    constexpr auto CMP_SIZE = sizeof(expectedNotsure7e1640)/sizeof(hime_t);

    for (int i = 0; i < CMP_SIZE; i++)
    {
        EXPECT_EQ(notsure7e1640[i], expectedNotsure7e1640[i]);
    }
}

TEST(HimeTest, deep_verify_check_sub_07_b97a_part_2)
{
    codeArray7e1680[0] = 0x3913; // で(unicode)
    codeArray7e1680[2] = 0x002A; // れ(unicode)
    codeArray7e1680[4] = 0x000D; // す(unicode)
    codeArray7e1680[6] = 0x3912; // づ(unicode)
    codeArray7e1680[8] = 0x3912; // づ(unicode)

    codeArray7e1680[10] = 0x001D; // へ(unicode)
    codeArray7e1680[12] = 0x3A1A; // ぱ(unicode)
    codeArray7e1680[14] = 0x001F; // ま(unicode)
    codeArray7e1680[16] = 0x0009; // け(unicode)
    codeArray7e1680[18] = 0x390C; // じ(unicode)

    codeArray7e1680[20] = 0x3912; // づ(unicode)
    codeArray7e1680[22] = 0x0003; // う(unicode)
    codeArray7e1680[24] = 0x000A; // こ(unicode)
    codeArray7e1680[26] = 0x3912; // づ(unicode)
    codeArray7e1680[28] = 0x3A1B; // ぴ(unicode)

    codeArray7e1680[30] = 0x000F; // そ(unicode)
    codeArray7e1680[32] = 0x0021; // む(unicode)
    codeArray7e1680[34] = 0x0019; // の(unicode)
    codeArray7e1680[36] = 0x0008; // く(unicode)
    codeArray7e1680[38] = 0x0008; // く(unicode)

    codeArray7e1680[40] = 0x0028; // り(unicode)
    codeArray7e1680[42] = 0x0025; // ゆ(unicode)
    codeArray7e1680[44] = 0x0021; // む(unicode)
    codeArray7e1680[46] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[48] = 0x0021; // む(unicode)

    codeArray7e1680[50] = 0x3913; // で(unicode)
    codeArray7e1680[52] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[54] = 0x0019; // の(unicode)
    codeArray7e1680[56] = 0x0001; // あ(unicode)
    codeArray7e1680[58] = 0x390B; // ざ(unicode)

    codeArray7e1680[60] = 0x390D; // ず(unicode)
    codeArray7e1680[62] = 0x003F;

    bool ret = check_sub_07_b97a(DEBUG_VERIFY_LEVEL_2);
    EXPECT_FALSE(ret);

    /* 7e1640
    1B 38 10 02 00 26 19 26 14 04 00 08 29 00 00 00
    01 20 00 00 00 00 28 00 06 01 00 00 08 3C 19 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    13 39 2A 00 0D 00 12 39 12 39 1D 00 1A 3A 1F 00
    09 00 0C 39 12 39 03 00 0A 00 12 39 1B 3A 0F 00
    */
    hime_t expectedNotsure7e1640[] = {0x1B, 0x38, 0x10, 0x02, 0x00, 0x26, 0x19, 0x26,
                                      0x14, 0x04, 0x00, 0x08, 0x29, 0x00, 0x00, 0x00,
                                      0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00,
                                      0x06, 0x01, 0x00, 0x00, 0x08, 0x3c, 0x19, 0x00};
    constexpr auto CMP_SIZE = sizeof(expectedNotsure7e1640)/sizeof(hime_t);

    for (int i = 0; i < CMP_SIZE; i++)
    {
        EXPECT_EQ(notsure7e1640[i], expectedNotsure7e1640[i]);
        if (notsure7e1640[i] != expectedNotsure7e1640[i])
        {
            printf("Exp[%i] 0x%x != 0x%x\n", i, expectedNotsure7e1640[i], notsure7e1640[i]);
        }
    }
}

TEST(HimeTest, verify_check_sub_07_b97a_goes_to_load)
{
    codeArray7e1680[0] = 0x3913; // で(unicode)
    codeArray7e1680[2] = 0x002A; // れ(unicode)
    codeArray7e1680[4] = 0x000D; // す(unicode)
    codeArray7e1680[6] = 0x3912; // づ(unicode)
    codeArray7e1680[8] = 0x3912; // づ(unicode)

    codeArray7e1680[10] = 0x001D; // へ(unicode)
    codeArray7e1680[12] = 0x3A1A; // ぱ(unicode)
    codeArray7e1680[14] = 0x001F; // ま(unicode)
    codeArray7e1680[16] = 0x0009; // け(unicode)
    codeArray7e1680[18] = 0x390C; // じ(unicode)

    codeArray7e1680[20] = 0x3912; // づ(unicode)
    codeArray7e1680[22] = 0x0003; // う(unicode)
    codeArray7e1680[24] = 0x000A; // こ(unicode)
    codeArray7e1680[26] = 0x3912; // づ(unicode)
    codeArray7e1680[28] = 0x3A1B; // ぴ(unicode)

    codeArray7e1680[30] = 0x000F; // そ(unicode)
    codeArray7e1680[32] = 0x0021; // む(unicode)
    codeArray7e1680[34] = 0x0019; // の(unicode)
    codeArray7e1680[36] = 0x0008; // く(unicode)
    codeArray7e1680[38] = 0x0008; // く(unicode)

    codeArray7e1680[40] = 0x0028; // り(unicode)
    codeArray7e1680[42] = 0x0025; // ゆ(unicode)
    codeArray7e1680[44] = 0x0021; // む(unicode)
    codeArray7e1680[46] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[48] = 0x0021; // む(unicode)

    codeArray7e1680[50] = 0x3913; // で(unicode)
    codeArray7e1680[52] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[54] = 0x0019; // の(unicode)
    codeArray7e1680[56] = 0x0001; // あ(unicode)
    codeArray7e1680[58] = 0x390B; // ざ(unicode)

    codeArray7e1680[60] = 0x390D; // ず(unicode)
    codeArray7e1680[62] = 0x003F;
    bool ret = check_sub_07_b97a();

    EXPECT_TRUE(ret);
}

TEST(HimeTest, verify_check_sub_07_b97a_goes_does_not_go_to_load)
{
    codeArray7e1680[0] = 0x3913; // で(unicode)
    codeArray7e1680[2] = 0x002A; // れ(unicode)
    codeArray7e1680[4] = 0x000D; // す(unicode)
    codeArray7e1680[6] = 0x3912; // づ(unicode)
    codeArray7e1680[8] = 0x3912; // づ(unicode)

    codeArray7e1680[10] = 0x001D; // へ(unicode)
    codeArray7e1680[12] = 0x3A1A; // ぱ(unicode)
    codeArray7e1680[14] = 0x001F; // ま(unicode)
    codeArray7e1680[16] = 0x0009; // け(unicode)
    codeArray7e1680[18] = 0x390C; // じ(unicode)

    codeArray7e1680[20] = 0x3912; // づ(unicode)
    codeArray7e1680[22] = 0x0003; // う(unicode)
    codeArray7e1680[24] = 0x000A; // こ(unicode)
    codeArray7e1680[26] = 0x3912; // づ(unicode)
    codeArray7e1680[28] = 0x3A1B; // ぴ(unicode)

    codeArray7e1680[30] = 0x000F; // そ(unicode)
    codeArray7e1680[32] = 0x0021; // む(unicode)
    codeArray7e1680[34] = 0x0019; // の(unicode)
    codeArray7e1680[36] = 0x0008; // く(unicode)
    codeArray7e1680[38] = 0x0008; // く(unicode)

    codeArray7e1680[40] = 0x0028; // り(unicode)
    codeArray7e1680[42] = 0x0025; // ゆ(unicode)
    codeArray7e1680[44] = 0x0021; // む(unicode)
    codeArray7e1680[46] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[48] = 0x0021; // む(unicode)

    codeArray7e1680[50] = 0x3913; // で(unicode)
    codeArray7e1680[52] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[54] = 0x003F;
    bool ret = check_sub_07_b97a();

    EXPECT_FALSE(ret);
}

TEST(HimeTest, verify_check_sub_b767_does_not_work_for_this)
{
    codeArray7e1680[0] = 0x3913; // で(unicode)
    codeArray7e1680[2] = 0x002A; // れ(unicode)
    codeArray7e1680[4] = 0x000D; // す(unicode)
    codeArray7e1680[6] = 0x3912; // づ(unicode)
    codeArray7e1680[8] = 0x3912; // づ(unicode)

    codeArray7e1680[10] = 0x001D; // へ(unicode)
    codeArray7e1680[12] = 0x3A1E; // ぽ(unicode)
    codeArray7e1680[14] = 0x001E; // ほ(unicode)
    codeArray7e1680[16] = 0x0009; // け(unicode)
    codeArray7e1680[18] = 0x390C; // じ(unicode)

    codeArray7e1680[20] = 0x3912; // づ(unicode)
    codeArray7e1680[22] = 0x0003; // う(unicode)
    codeArray7e1680[24] = 0x000A; // こ(unicode)
    codeArray7e1680[26] = 0x3912; // づ(unicode)
    codeArray7e1680[28] = 0x3A1B; // ぴ(unicode)

    codeArray7e1680[30] = 0x000F; // そ(unicode)
    codeArray7e1680[32] = 0x0021; // む(unicode)
    codeArray7e1680[34] = 0x0019; // の(unicode)
    codeArray7e1680[36] = 0x0008; // く(unicode)
    codeArray7e1680[38] = 0x0008; // く(unicode)

    codeArray7e1680[40] = 0x0028; // り(unicode)
    codeArray7e1680[42] = 0x0025; // ゆ(unicode)
    codeArray7e1680[44] = 0x0021; // む(unicode)
    codeArray7e1680[46] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[48] = 0x0021; // む(unicode)

    codeArray7e1680[50] = 0x3913; // で(unicode)
    codeArray7e1680[52] = 0x3A1B; // ぴ(unicode)
    codeArray7e1680[54] = 0x0019; // の(unicode)
    codeArray7e1680[56] = 0x0001; // あ(unicode)
    codeArray7e1680[58] = 0x390B; // ざ(unicode)

    codeArray7e1680[60] = 0x3913; // ず(unicode)
    codeArray7e1680[62] = 0x003F;
    bool ret = check_sub_07_b97a();

    EXPECT_FALSE(ret);
}

static unsigned get_valid_password_32len(HimePassArray& aPasswordP)
{
    aPasswordP[0] = 0x3913; // で(unicode)
    aPasswordP[2] = 0x002A; // れ(unicode)
    aPasswordP[4] = 0x000D; // す(unicode)
    aPasswordP[6] = 0x3912; // づ(unicode)
    aPasswordP[8] = 0x3912; // づ(unicode)

    aPasswordP[10] = 0x001D; // へ(unicode)
    aPasswordP[12] = 0x3A1A; // ぱ(unicode)
    aPasswordP[14] = 0x001F; // ま(unicode)
    aPasswordP[16] = 0x0009; // け(unicode)
    aPasswordP[18] = 0x390C; // じ(unicode)

    aPasswordP[20] = 0x3912; // づ(unicode)
    aPasswordP[22] = 0x0003; // う(unicode)
    aPasswordP[24] = 0x000A; // こ(unicode)
    aPasswordP[26] = 0x3912; // づ(unicode)
    aPasswordP[28] = 0x3A1B; // ぴ(unicode)

    aPasswordP[30] = 0x000F; // そ(unicode)
    aPasswordP[32] = 0x0021; // む(unicode)
    aPasswordP[34] = 0x0019; // の(unicode)
    aPasswordP[36] = 0x0008; // く(unicode)
    aPasswordP[38] = 0x0008; // く(unicode)

    aPasswordP[40] = 0x0028; // り(unicode)
    aPasswordP[42] = 0x0025; // ゆ(unicode)
    aPasswordP[44] = 0x0021; // む(unicode)
    aPasswordP[46] = 0x3A1B; // ぴ(unicode)
    aPasswordP[48] = 0x0021; // む(unicode)

    aPasswordP[50] = 0x3913; // で(unicode)
    aPasswordP[52] = 0x3A1B; // ぴ(unicode)
    aPasswordP[54] = 0x0019; // の(unicode)
    aPasswordP[56] = 0x0001; // あ(unicode)
    aPasswordP[58] = 0x390B; // ざ(unicode)

    aPasswordP[60] = 0x390D; // ず(unicode)
    aPasswordP[62] = 0x003F;

    return 32;
}

TEST(HighLevelHimeTest, password_reading_to_bits_and_length_ok)
{
    hime_t aPassWorord[CODE_MAX_SIZE];
    const std::size_t expectedLength = get_valid_password_32len(aPassWorord);

    const HimePassArray expected7e1640{57,42,12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,24,0,49,51};
    const HimePassArray expected7e1641{};

    HimePassArray got7e1640{};
    HimePassArray got7e1641{};
    const std::size_t gotLength = password_decode_to_bits(aPassWorord, got7e1640, got7e1641);
    EXPECT_EQ(gotLength, expectedLength);
    EXPECT_THAT(got7e1640, testing::ElementsAreArray(expected7e1640));
    EXPECT_THAT(got7e1641, testing::ElementsAreArray(expected7e1641));

    EXPECT_EQ(password_length_to_type_checksum(gotLength), PASSWORD_TYPE_LONG_32);
    EXPECT_TRUE(is_valid_password_type(password_length_to_type_checksum(gotLength)));
}

TEST(HighLevelHimeTest, password_type_check_only_allowed_and_short_and_long_is_distinquished)
{
    EXPECT_EQ(password_length_to_type_checksum(7), PASSWORD_TYPE_SHORT_7);
    EXPECT_EQ(password_length_to_type_checksum(8), PASSWORD_TYPE_SHORT_8);
    EXPECT_EQ(password_length_to_type_checksum(32), PASSWORD_TYPE_LONG_32);
    EXPECT_EQ(password_length_to_type_checksum(56), PASSWORD_TYPE_LONG_56);
    EXPECT_EQ(password_length_to_type_checksum(5), PASSWORD_TYPE_INVALID);
}

TEST(HighLevelHimeTest, password_reading_to_bits_ok_but_then_length_is_not_ok)
{
    hime_t passWord[CODE_MAX_SIZE];
    std::size_t expectedLength = get_valid_password_32len(passWord);
    (void)expectedLength;
    passWord[54] = 0x003F; // ends here, too early
    expectedLength = 28;

    const HimePassArray expected7e1640{57,42,12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,0,0,0,0};

    HimePassArray got7e1640{};
    HimePassArray got7e1641{1,2,3,4,5,6,7,8,9,0xA,1,2,3,4,5,6,7,8,9,0xA,1,2,3,4,5,6,7,8,9,0xA,0xB,0xC,0xD};
    const std::size_t gotLength = password_decode_to_bits(passWord, got7e1640, got7e1641);
    ASSERT_EQ(gotLength, expectedLength);
    for (unsigned i = 0; i < expectedLength-1; ++i)
    {
        EXPECT_EQ(got7e1640[i], expected7e1640[i]);
        EXPECT_EQ(got7e1641[i], 0);
    }
    EXPECT_EQ(got7e1641[expectedLength+0], 9);
    EXPECT_EQ(got7e1641[expectedLength+1], 10);
    EXPECT_EQ(got7e1641[expectedLength+2], 11);
    EXPECT_EQ(got7e1641[expectedLength+3], 12);
    EXPECT_EQ(got7e1641[expectedLength+4], 13);

    const auto result = password_length_to_type_checksum(gotLength);
    EXPECT_NE(result, PASSWORD_TYPE_SHORT_7);
    EXPECT_NE(result, PASSWORD_TYPE_SHORT_8);
    EXPECT_NE(result, PASSWORD_TYPE_LONG_32);
    EXPECT_NE(result, PASSWORD_TYPE_LONG_56);
    EXPECT_FALSE(is_valid_password_type(result));
}

TEST(HighLevelHimeTest, password_checksum_gives_expected_result)
{
    HimePassArray validForPassWord1_7e1640{57,42,12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,24,0,49,51};
    const hime_t passWord1_TypeLength = PASSWORD_TYPE_LONG_32;
    hime_t effectiveLength;

    //0016 = 1b
    //1640 = 1b
    //1641 = 38
    EXPECT_TRUE(verify_password_checksum(passWord1_TypeLength, validForPassWord1_7e1640, effectiveLength));
    EXPECT_EQ(validForPassWord1_7e1640[0], 0x1b); // == PASSWORD_TYPE_LONG_32
    EXPECT_EQ(validForPassWord1_7e1640[1], 0x38);
    EXPECT_EQ(effectiveLength, passWord1_TypeLength + 2);
}

TEST(HighLevelHimeTest, password_checksum_gives_unexpected_result_1)
{
    HimePassArray validForPassWord1_7e1640{58,42,12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,24,0,49,51};
    const std::size_t passWord1_TypeLength = PASSWORD_TYPE_LONG_32;
    hime_t effectiveLength;

    EXPECT_FALSE(verify_password_checksum(passWord1_TypeLength, validForPassWord1_7e1640, effectiveLength));
    EXPECT_EQ(validForPassWord1_7e1640[0], PASSWORD_TYPE_LONG_32-3);
    EXPECT_EQ(validForPassWord1_7e1640[1], 56);
    EXPECT_EQ(effectiveLength, validForPassWord1_7e1640[0]);
}

TEST(HighLevelHimeTest, password_checksum_gives_unexpected_result_2)
{
    HimePassArray validForPassWord1_7e1640{57,43,12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,24,0,49,51};
    const std::size_t passWord1_TypeLength = PASSWORD_TYPE_LONG_32;
    hime_t effectiveLength;

    EXPECT_FALSE(verify_password_checksum(passWord1_TypeLength, validForPassWord1_7e1640, effectiveLength));
    EXPECT_EQ(validForPassWord1_7e1640[0], PASSWORD_TYPE_LONG_32+1);
    EXPECT_EQ(validForPassWord1_7e1640[1], 55);
    EXPECT_EQ(effectiveLength, validForPassWord1_7e1640[0]);
}

TEST(HighLevelHimeTest, data_decode_table_gives_expected_result_for_valid_password)
{
    HimePassArray validForPassWord1_7e1640_after_Checksum{27,56,
        12,56,56,28,59,30,8,50,56,2,9,56,60,14,32,24,7,7,40,36,32,60,32,57,60,24,0,49,51};
    const std::size_t passWord1_LengthPlus2 = PASSWORD_TYPE_LONG_32 + 2;

    decode_data_against_table(passWord1_LengthPlus2, validForPassWord1_7e1640_after_Checksum);

    const HimePassArray expectedForPassWord1_7e1640_After_table{27,56,
        16,2,0,38,25,38,20,4,0,8,41,0,0,0,1,32,0,0,0,0,40,0,6,1,0,0,8,60,25,0};
    EXPECT_THAT(validForPassWord1_7e1640_after_Checksum, testing::ElementsAreArray(expectedForPassWord1_7e1640_After_table));
}

TEST(HighLevelHimeTest, value_loader_part1_test_ok)
{
    //load_values_part1(is_long_password_type(PASSWORD_TYPE_LONG_32));
}

constexpr std::size_t HIRAGANA_LETTER_BUFFER_SIZE = 20;
void get_hiragana_letters(const std::uint8_t bit1,
                          char* const hiragana1,
                          const std::uint8_t bit2,
                          char* const hiragana2,
                          hime_t& gameValue1,
                          hime_t& gameValue2)
{
    std::map<hime_t, const char*> bit_conv;
    bit_conv[0x0000] = "\u3042";

    for (auto i : g_conv)
    {
        char hibyte = 0;
        char lowbyte = 0x82+(i.second.second&0x00FF-0x42);
        if (i.second.first >= 126)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 122)
        {
            hibyte = 0x81;
            lowbyte -= 0x00;
        }
        else if (i.second.first >= 112)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 102)
        {
            hibyte = 0x81;
            lowbyte -= 0x00;
        }
        else if (i.second.first >= 100)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 90)
        {
            hibyte = 0x81;
            lowbyte -= 0x00;
        }
        else if (i.second.first >= 88)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 76)
        {
            hibyte = 0x82;
            lowbyte += 0x80;
        }
        else if (i.second.first >= 64)
        {
            hibyte = 0x82;
            lowbyte += 0x80 - 0x02;
        }
        else if (i.second.first >= 62)
        {
            hibyte = 0x82;
        }
        else if (i.second.first >= 56)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 24)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else if (i.second.first >= 22)
        {
            hibyte = 0x81;
            lowbyte -= 0x00;
        }
        else if (i.second.first >= 20)
        {
            hibyte = 0x81;
            lowbyte -= 0x02;
        }
        else
        {
            hibyte = 0x81;
        }

        if (i.second.first == bit1)
        {
            //printf("Kana1: Hibyte 0x%x Lowbyte 0x%x for gamevalue %x\n", (std::uint8_t)hibyte, (std::uint8_t)lowbyte, i.first);
            snprintf(hiragana1, HIRAGANA_LETTER_BUFFER_SIZE, u8"\xE3%c%c%c", hibyte, lowbyte, 0);
            gameValue1 = i.first;
        }

        if (i.second.first == bit2)
        {
            //printf("Kana2: Hibyte 0x%x Lowbyte 0x%x for bit %u\n", (std::uint8_t)hibyte, (std::uint8_t)lowbyte, bit2);
            snprintf(hiragana2, HIRAGANA_LETTER_BUFFER_SIZE, u8"\xE3%c%c%c", hibyte, lowbyte, 0);
            gameValue2 = i.first;
        }
    }
}

TEST(HighLevelHimeTest, generate_valid_first_two_for_a_short_7_password)
{
    hime_t generatedPassword[CODE_MAX_SIZE];
    generatedPassword[0] = 0x0000;  // computed by the test
    generatedPassword[2] = 0x0000;  // computed by the test
    generatedPassword[4] = 0x0001;  // payload
    generatedPassword[6] = 0x0001;  // payload
    generatedPassword[8] = 0x0002;  // payload
    generatedPassword[10] = 0x0001; // payload
    generatedPassword[12] = 0x003F; // end

    HimePassArray got7e1640{};
    HimePassArray got7e1641{};
    const std::size_t gotLength = password_decode_to_bits(generatedPassword, got7e1640, got7e1641);
    EXPECT_EQ(gotLength, 7);

    const HimePasswordType typeLength = password_length_to_type_checksum(gotLength);
    EXPECT_TRUE(is_valid_password_type(typeLength));
    EXPECT_EQ(password_length_to_type_checksum(gotLength), PASSWORD_TYPE_SHORT_7);

    hime_t effectiveLength;
    constexpr std::uint8_t BIT1_EXPECTED[]{34, 32, 54, 122};
    constexpr std::uint8_t BIT2_EXPECTED[]{42, 84, 70, 18};
    constexpr std::uint8_t MEM16_EXPECTED[]{3, 84, 70, 18};
    constexpr std::uint8_t MEM18_EXPECTED[]{9, 84, 70, 18};
    auto numberFound = 0;
    for (hime_t i = 0; i <= 63; ++i)
    {
        for (hime_t j = 0; j <= 63; ++j)
        {
            got7e1640[0] = i;
            got7e1640[1] = j;
            if (verify_password_checksum(typeLength, got7e1640, effectiveLength))
            {
                char hiragana1[HIRAGANA_LETTER_BUFFER_SIZE], hiragana2[HIRAGANA_LETTER_BUFFER_SIZE];
                std::uint8_t bit1 = i<<1, bit2 = j<<1;
                hime_t gameValue1=0, gameValue2=0;

                get_hiragana_letters(bit1, hiragana1, bit2, hiragana2, gameValue1, gameValue2);
                EXPECT_EQ(effectiveLength, typeLength + 2);

                codeArray7e1680[0] = gameValue1;
                codeArray7e1680[2] = gameValue2;
                codeArray7e1680[4] = generatedPassword[4];
                codeArray7e1680[6] = generatedPassword[6];
                codeArray7e1680[8] = generatedPassword[8];
                codeArray7e1680[10] = generatedPassword[10];
                codeArray7e1680[12] = generatedPassword[12];

                notsure7e0070 = 0x1a;
                notsure7e0072 = 6;
                notsure000000[0x1630] = 2; // proper value set by below sub, 2 -> invalid for this password type
                if (check_sub_07_b97a())
                {
                    EXPECT_EQ(bit1, BIT1_EXPECTED[numberFound]);
                    EXPECT_EQ(bit2, BIT2_EXPECTED[numberFound]);
                    EXPECT_EQ(notsure000000[0x16], MEM16_EXPECTED[numberFound]);
                    EXPECT_EQ(notsure000000[0x18], MEM18_EXPECTED[numberFound]);
                    EXPECT_EQ(notsure000000[0xa8], 3); // both players
                    EXPECT_EQ(notsure000000[0x82], 4); // world 4
                    ++numberFound;

                    char hiragana3[HIRAGANA_LETTER_BUFFER_SIZE], hiragana4[HIRAGANA_LETTER_BUFFER_SIZE];
                    auto bit3 = g_conv[generatedPassword[4]].first;
                    auto bit4 = g_conv[generatedPassword[6]].first;
                    auto bit5 = g_conv[generatedPassword[8]].first;
                    auto bit6 = g_conv[generatedPassword[10]].first;
                    get_hiragana_letters(bit3, hiragana3,
                                         bit4, hiragana4,
                                         gameValue1, gameValue2);

                    char hiragana5[HIRAGANA_LETTER_BUFFER_SIZE], hiragana6[HIRAGANA_LETTER_BUFFER_SIZE];
                    get_hiragana_letters(bit5, hiragana5,
                                         bit6, hiragana6,
                                         gameValue1, gameValue2);

                    printf("Result %u is %s %s %s %s %s %s (bits %u %u %u %u %u %u)\n",
                           numberFound,
                           hiragana1, hiragana2,
                           hiragana3, hiragana4,
                           hiragana5, hiragana6,
                           bit1, bit2, bit3, bit4, bit5, bit6);
                }
                EXPECT_EQ(notsure000000[0x1630], 0);
            }
        }
    }
    EXPECT_EQ(numberFound, 1);
}

TEST(HighVsLowLevelHimeTest, generate_4_valid_semi_random_short_8_passwords)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> disr1(1, 0x2c);
    std::uniform_int_distribution<> disr2(0x3906, 0x3914);
    std::uniform_int_distribution<> disr3(0x3A1A, 0x3A1E);

    std::size_t numberFound = 0;
    for (hime_t trial = 0; trial < 10000; ++trial)
    {
        codeArray7e1680[4] = disr1(gen);
        codeArray7e1680[6] = disr1(gen);
        codeArray7e1680[8] = disr1(gen);
        codeArray7e1680[10] = disr2(gen);
        codeArray7e1680[12] = disr3(gen);
        codeArray7e1680[14] = 0x003F; // end
        for (hime_t i = 0; i <= 63; ++i)
        {
            for (hime_t j = 0; j <= 63; ++j)
            {
                char hiragana1[HIRAGANA_LETTER_BUFFER_SIZE], hiragana2[HIRAGANA_LETTER_BUFFER_SIZE];
                std::uint8_t bit1 = i<<1, bit2 = j<<1;
                hime_t gameValue1=0, gameValue2=0;

                get_hiragana_letters(bit1, hiragana1, bit2, hiragana2, gameValue1, gameValue2);

                codeArray7e1680[0] = gameValue1;
                codeArray7e1680[2] = gameValue2;

                notsure7e0070 = 0x1a;
                notsure7e0072 = 6;

                if (check_sub_07_b97a())
                {
                    ++numberFound;
                    printf("Password: %x %x %x %x %x %x %x\n", codeArray7e1680[0], codeArray7e1680[2],
                            codeArray7e1680[4], codeArray7e1680[6],
                            codeArray7e1680[8],  codeArray7e1680[10],  codeArray7e1680[12]);
                    printf("Players %x and world %x\n", notsure000000[0xa8], notsure000000[0x82]);

                    if (numberFound >= 2)
                    {
                        j = i = 0xF0;
                        trial = 0xFFF0;
                    }
                }
                else
                {
                    //printf("Fails sub!\n");
                    //ASSERT_FALSE(true);
                }
            }
        }
    }

    // Initially it showed that every combo has at least 2 valid (usually 3, sometimes 4, never 5)
    EXPECT_GE(numberFound, 1);
    EXPECT_LE(numberFound, 4);
}

TEST(HighVsLowLevelHimeTest, verify_a_fixed_short_8_password_gen_by_random_is_rejected_by_expected_result)
{
    notsure7e0070 = 0x1a;
    notsure7e0072 = 6;
    codeArray7e1680[0] = 0x0001; // あ
    codeArray7e1680[2] = 0x3A1A; // ぱ
    codeArray7e1680[4] = 0x000D; // す
    codeArray7e1680[6] = 0x3912; // づ
    codeArray7e1680[8] = 0x0016; // に
    codeArray7e1680[10] = 0x390A; // ご
    codeArray7e1680[12] = 0x3A1A; // ぱ
    codeArray7e1680[14] = 0x003F; // stp
    EXPECT_FALSE(check_sub_07_b97a());

    //03 27 21 13 2E 0B 2A
    EXPECT_EQ(notsure7e1640[0], 0x0003);
    EXPECT_EQ(notsure7e1640[1], 0x0027);
    EXPECT_EQ(notsure7e1640[2], 0x0021);
    EXPECT_EQ(notsure7e1640[3], 0x0013);
    EXPECT_EQ(notsure7e1640[4], 0x002e);
    EXPECT_EQ(notsure7e1640[5], 0x000b);
    EXPECT_EQ(notsure7e1640[6], 0x002a);
    EXPECT_EQ(notsure7e1640[7], 0x0000);
    EXPECT_EQ(notsure000000[0x16], 0x2);
    EXPECT_EQ(notsure000000[0x18], 0x4);

    EXPECT_EQ(notsure000000[0xa8], 0x2);
    EXPECT_EQ(notsure000000[0x82], 0x1);

    sub_b767(DEBUG_VERIFY_LEVEL_1);
    EXPECT_EQ(notsure000000[0xa8], 0x2);
    EXPECT_EQ(notsure000000[0x82], 0x1);

    sub_b767(DEBUG_VERIFY_LEVEL_1_SECOND_b7b0);
    EXPECT_EQ(notsure000000[0xa8], 0x2);
    EXPECT_EQ(notsure000000[0x82], 0x1);

    // Verify that the memory outputs are as expected.
    notsure000000[0xa8] = notsure000000[0x82] = notsure000000[0x16] = 0;
    notsure000000[0x1b8c] = notsure000000[0x1b8a] = notsure000000[0x1b86] = 1;
    notsure000000[0x1b88] = 0;
    sub_b767();
    EXPECT_EQ(notsure000000[0xa8], 0x2);
    EXPECT_EQ(notsure000000[0x82], 0x1);
    EXPECT_EQ(notsure000000[0x1b8c], 0x00);
    EXPECT_EQ(notsure000000[0x1b8a], 0x00);
    EXPECT_EQ(notsure000000[0x1b86], 0x00);
    EXPECT_EQ(notsure000000[0x1b88], 0x01);
    EXPECT_EQ(notsure000000[0x16], 0x2);

    notsure000000[0x18] = notsure000000[0x12] = notsure000000[0x14] = notsure000000[0x4] = 0;
    sub_b801();
    EXPECT_EQ(notsure000000[0x18], 0x4);
}

TEST(HighVsLowLevelHimeTest, verify_a_fixed_valid_short_7_password_is_not_rejected_and_gets_expected_result_works_on_a_fucking_real_machine)
{
    notsure7e0070 = 0x1a;
    notsure7e0072 = 6;
    codeArray7e1680[0] = 0x0012; // つ
    codeArray7e1680[2] = 0x0016; // に
    codeArray7e1680[4] = 0x0001; // あ
    codeArray7e1680[6] = 0x0001; // あ
    codeArray7e1680[8] = 0x0001; // あ
    codeArray7e1680[10] = 0x0001; // あ
    codeArray7e1680[12] = 0x003F; // stp
    EXPECT_TRUE(check_sub_07_b97a());

    EXPECT_EQ(notsure7e1640[0], 2);
    EXPECT_EQ(notsure7e1640[1], 57);
    EXPECT_EQ(notsure7e1640[2], 11);
    EXPECT_EQ(notsure7e1640[3], 9);
    EXPECT_EQ(notsure7e1640[4], 7);
    EXPECT_EQ(notsure7e1640[5], 9);
    EXPECT_EQ(notsure7e1640[6], 0);
    EXPECT_EQ(notsure7e1640[7], 0x0000);

    enum PLAYER
    {
        INVALID = 0,
        GOEMON = 1,
        DRMAVIN = 2,
        BOTH = 3
    };

    enum WORLD
    {
        ROCK_BABY_CRIB_SO_LEVEL_4=4
    };

    EXPECT_EQ(notsure000000[0x16], 0x3);
    EXPECT_EQ(notsure000000[0x18], 0x9);

    EXPECT_EQ(notsure000000[0xa8], BOTH);
    EXPECT_EQ(notsure000000[0x82], ROCK_BABY_CRIB_SO_LEVEL_4);

    sub_b767(DEBUG_VERIFY_LEVEL_1);
    EXPECT_EQ(notsure000000[0xa8], BOTH);
    EXPECT_EQ(notsure000000[0x82], ROCK_BABY_CRIB_SO_LEVEL_4);

    sub_b767(DEBUG_VERIFY_LEVEL_1_SECOND_b7b0);
    EXPECT_EQ(notsure000000[0xa8], BOTH);
    EXPECT_EQ(notsure000000[0x82], ROCK_BABY_CRIB_SO_LEVEL_4);

    // Verify that the memory outputs are as expected.
    notsure000000[0xa8] = notsure000000[0x82] = notsure000000[0x16] = 0;
    notsure000000[0x1b8c] = notsure000000[0x1b8a] = notsure000000[0x1b86] = 1;
    notsure000000[0x1b88] = 0;
    sub_b767();
    EXPECT_EQ(notsure000000[0xa8], BOTH);
    EXPECT_EQ(notsure000000[0x82], ROCK_BABY_CRIB_SO_LEVEL_4);
    EXPECT_EQ(notsure000000[0x1b8c], 0x01);
    EXPECT_EQ(notsure000000[0x1b8a], 0x00);
    EXPECT_EQ(notsure000000[0x1b86], 0x00);
    EXPECT_EQ(notsure000000[0x1b88], 0x00);
    EXPECT_EQ(notsure000000[0x16], 0x3);

    notsure000000[0x18] = notsure000000[0x12] = notsure000000[0x14] = notsure000000[0x4] = 0;
    sub_b801();
    EXPECT_EQ(notsure000000[0x18], 0x9);
}

TEST(HighVsLowLevelHimeTest, find_out_the_difference_in_short_7_passwords)
{
    notsure7e0070 = 0x1a;
    notsure7e0072 = 6;

    // ne na mu ha i dzu pe
    codeArray7e1680[0] = 0x0018;
    codeArray7e1680[2] = 0x0015;
    codeArray7e1680[4] = 0x0021;
    codeArray7e1680[6] = 0x001a;
    codeArray7e1680[8] = 0x0002;
    codeArray7e1680[10] = 0x3912;
    codeArray7e1680[12] = 0x3a1d;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 5);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x00);
    EXPECT_EQ(notsure000000[0x1ada], 0x00);
    EXPECT_EQ(notsure000000[0x1adc], 0x00);

    // password 2
    codeArray7e1680[0] = 0x0011;
    codeArray7e1680[2] = 0x002b;
    codeArray7e1680[4] = 0x0016;
    codeArray7e1680[6] = 0x000d;
    codeArray7e1680[8] = 0x0001;
    codeArray7e1680[10] = 0x390f;
    codeArray7e1680[12] = 0x3a1a;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x00);
    EXPECT_EQ(notsure000000[0x1ad8], 0x01);
    EXPECT_EQ(notsure000000[0x1ada], 0x00);
    EXPECT_EQ(notsure000000[0x1adc], 0x01);

    // password 2.2
    codeArray7e1680[0] = 0x0011;
    codeArray7e1680[2] = 0x002b;
    codeArray7e1680[4] = 0x0016;
    codeArray7e1680[6] = 0x0025;
    codeArray7e1680[8] = 0x0002;
    codeArray7e1680[10] = 0x390f;
    codeArray7e1680[12] = 0x3a1c;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x00);
    EXPECT_EQ(notsure000000[0x1ada], 0x01);
    EXPECT_EQ(notsure000000[0x1adc], 0x01);

    // password 3
    codeArray7e1680[0] = 0x0012;
    codeArray7e1680[2] = 0x002a;
    codeArray7e1680[4] = 0x0017;
    codeArray7e1680[6] = 0x0024;
    codeArray7e1680[8] = 0x0002;
    codeArray7e1680[10] = 0x3914;
    codeArray7e1680[12] = 0x3a1e;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x00);
    EXPECT_EQ(notsure000000[0x1ada], 0x01);
    EXPECT_EQ(notsure000000[0x1adc], 0x00);

    // password 4
    codeArray7e1680[0] = 0x0015;
    codeArray7e1680[2] = 0x0018;
    codeArray7e1680[4] = 0x0012;
    codeArray7e1680[6] = 0x001e;
    codeArray7e1680[8] = 0x0005;
    codeArray7e1680[10] = 0x3913;
    codeArray7e1680[12] = 0x3a1b;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x00);
    EXPECT_EQ(notsure000000[0x1ada], 0x00);
    EXPECT_EQ(notsure000000[0x1adc], 0x01);

    // password 5
    codeArray7e1680[0] = 0x0015;
    codeArray7e1680[2] = 0x0018;
    codeArray7e1680[4] = 0x0012;
    codeArray7e1680[6] = 0x0026;
    codeArray7e1680[8] = 0x0006;
    codeArray7e1680[10] = 0x3913;
    codeArray7e1680[12] = 0x3a1c;
    codeArray7e1680[14] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x00);
    EXPECT_EQ(notsure000000[0x1ada], 0x01);
    EXPECT_EQ(notsure000000[0x1adc], 0x01);

    // password 6 (len 6)
    //1 3914 7 25 390d 2a 3f -> a do ki yu zu re
    codeArray7e1680[0] = 0x0001;
    codeArray7e1680[2] = 0x3914;
    codeArray7e1680[4] = 0x0007;
    codeArray7e1680[6] = 0x0025;
    codeArray7e1680[8] = 0x390d;
    codeArray7e1680[10] = 0x002a;
    codeArray7e1680[12] = 0x003F;
    notsure000000[0x1ad6] = notsure000000[0x1ad8] = notsure000000[0x1ada] = notsure000000[0x1adc] = 0x75;
    EXPECT_TRUE(check_sub_07_b97a());
    EXPECT_EQ(notsure000000[0xa8], 1);
    EXPECT_EQ(notsure000000[0x82], 6);
    EXPECT_EQ(notsure000000[0x1ad6], 0x01);
    EXPECT_EQ(notsure000000[0x1ad8], 0x01);
    EXPECT_EQ(notsure000000[0x1ada], 0x01);
    EXPECT_EQ(notsure000000[0x1adc], 0x01);
}


TEST(BruteForceHimeTest, find_short_password_where_world_and_char_is)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> disr1(1, 0x2c);
    std::uniform_int_distribution<> disr2(0x3906, 0x3914);
    std::uniform_int_distribution<> disr3(0x3A1A, 0x3A1E);

    const hime_t world_want = 6;
    const hime_t player_want = 1;
    for (hime_t trial = 0; trial < 65535; ++trial)
    {
        codeArray7e1680[4] = disr1(gen);
        codeArray7e1680[6] = disr1(gen);
        codeArray7e1680[8] = disr1(gen);
        codeArray7e1680[10] = disr2(gen);
        codeArray7e1680[12] = disr3(gen);
        codeArray7e1680[14] = 0x003F; // end
        for (hime_t i = 0; i <= 63; ++i)
        {
            for (hime_t j = 0; j <= 63; ++j)
            {
                char hiragana1[HIRAGANA_LETTER_BUFFER_SIZE], hiragana2[HIRAGANA_LETTER_BUFFER_SIZE];
                std::uint8_t bit1 = i<<1, bit2 = j<<1;
                hime_t gameValue1=0, gameValue2=0;

                get_hiragana_letters(bit1, hiragana1, bit2, hiragana2, gameValue1, gameValue2);

                codeArray7e1680[0] = gameValue1;
                codeArray7e1680[2] = gameValue2;

                notsure7e0070 = 0x1a;
                notsure7e0072 = 6;

                if (check_sub_07_b97a())
                {
                    // Uncomment to limit by players
                    //if (notsure000000[0xa8] == player_want)
                    {
                        // To limit by world
                        if (notsure000000[0x82] <= world_want)
                        {
                            // Set && to limit by the unknown value writes
                            if (true ||
                                    (notsure000000[0x1ad6] == 0x00 &&
                                    notsure000000[0x1ad8] == 0x00 &&
                                    notsure000000[0x1ada] == 0x00 &&
                                    notsure000000[0x1adc] == 0x00))
                            {
                                printf("Password: %x %x %x %x %x %x %x\n", codeArray7e1680[0], codeArray7e1680[2],
                                        codeArray7e1680[4], codeArray7e1680[6],
                                        codeArray7e1680[8],  codeArray7e1680[10],  codeArray7e1680[12]);
                                printf("Players %x and world %x\n", notsure000000[0xa8], notsure000000[0x82]);
                                j = i = 0xF0;
                                trial = 0xFFF0;
                            }
                        }
                    }
                }
            }
        }
    }
}

std::uint64_t tried_count = 0;
void iterate_all_on_index(const unsigned index, const unsigned max)
{
    const hime_t world_want = 6;
    const hime_t player_want = 1;

    if (index == max)
    {
        codeArray7e1680[index] = 0x003F;
        return;
    }

    for (auto value : g_conv)
    {
        codeArray7e1680[index] = value.first;
        iterate_all_on_index(index+2, max);

        if (check_sub_07_b97a())
        {
            if (player_want == notsure000000[0xa8])
            {
                if (world_want == notsure000000[0x82])
                {
                    if (notsure000000[0x1ad6] >= 0x02 ||
                            notsure000000[0x1ad8] >= 0x02 ||
                            notsure000000[0x1ada] >= 0x02 ||
                            notsure000000[0x1adc] >= 0x02)
                    {
                        printf("Password: %x %x %x %x %x %x %x (%x %x %x %x)\n", codeArray7e1680[0], codeArray7e1680[2],
                                codeArray7e1680[4], codeArray7e1680[6],
                                codeArray7e1680[8],  codeArray7e1680[10],  codeArray7e1680[12],
                                notsure000000[0x1ad6], notsure000000[0x1ad8], notsure000000[0x1ada], notsure000000[0x1adc]);
                        printf("Players %x and world %x\n", notsure000000[0xa8], notsure000000[0x82]);
                    }
                }
            }
        }
        if ((++tried_count % 300000) == 0)
        {
            printf("Passwords %lu different tried: %x %x %x %x %x %x %x %x\n", tried_count, codeArray7e1680[0], codeArray7e1680[2],
                    codeArray7e1680[4], codeArray7e1680[6],
                    codeArray7e1680[8],  codeArray7e1680[10],  codeArray7e1680[12], codeArray7e1680[14]);
        }
    }
}

TEST(BruteForceHimeTest, iterate_all_characters_to_find_valid_password_by_given_criteria)
{
    constexpr hime_t MAX_IDNEX = 0; // 0 -> finds nothing. This Disabled by default. Put 12 to iterate about 70 billion values..
    iterate_all_on_index(0, MAX_IDNEX);
}

TEST(BruteForceHimeTest, recalculate_checksum_for_a_single_value_change)
{
    get_valid_password_32len(codeArray7e1680);

    notsure7e0070 = 0x1a;
    notsure7e0072 = 6;

    ASSERT_TRUE(check_sub_07_b97a());
    codeArray7e1680[10] = 0x001A; // was 0x1D
    ASSERT_FALSE(check_sub_07_b97a());

    // TODO: currently this test is rather silly,
    //       very specificly we know that rolling numbers in 20 and 22 leads to a passing checksum (ex. 18 and 20 NO).
    const auto index = 20;
    for (hime_t i = 0; i <= 63; ++i)
    {
        for (hime_t j = 0; j <= 63; ++j)
        {
            char hiragana1[HIRAGANA_LETTER_BUFFER_SIZE], hiragana2[HIRAGANA_LETTER_BUFFER_SIZE];
            std::uint8_t bit1 = i<<1, bit2 = j<<1;
            hime_t gameValue1=0, gameValue2=0;

            get_hiragana_letters(bit1, hiragana1, bit2, hiragana2, gameValue1, gameValue2);

            codeArray7e1680[index+0] = gameValue1;
            codeArray7e1680[index+2] = gameValue2;

            if (check_sub_07_b97a())
            {
                printf("New password:");
                for (int k = 0; k < 64; k+=2)
                {
                    printf(" %x ", codeArray7e1680[k]);
                }
                printf("\n");
                j = i = 64;
            }
        }
    }
    EXPECT_TRUE(check_sub_07_b97a());
}


// Things to test->
// check this todo -> // TODO: does valid passwd always equal the same?
// TODO: long password how works exactly? there is one working in the test
// TODO: most likely there are more 16-bit vs. 8-bit errors in first sub or in the begging of passwd routine

// 1 1 3906 d 16 d 1 -> a a ga su ni su a -> initial length check not good, but otherwise good.

int main(int argc, char **argv)
{
    init_conv();
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
