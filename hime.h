#ifndef HIME_H
#define HIME_H

#include <cstdint>
#include <cstddef>
#include <map>

void init_conv();

enum DEBUG_VERIFY
{
    DEBUG_VERIFY_LEVEL_1,
    DEBUG_VERIFY_LEVEL_2,
    DEBUG_VERIFY_LEVEL_3,
    DEBUG_VERIFY_LEVEL_ALL,
    DEBUG_VERIFY_LEVEL_1_SECOND_b7b0,
    DEBUG_VERIFY_LEVEL_1_THIRD_b7b0
};

bool check_sub_07_b97a(DEBUG_VERIFY debug_level = DEBUG_VERIFY_LEVEL_ALL);

void sub_b767(DEBUG_VERIFY debug_level = DEBUG_VERIFY_LEVEL_ALL);
void sub_b801();

typedef uint16_t hime_t;

constexpr size_t CODE_MAX_SIZE = 2 * 15*4;
constexpr size_t SIMU_MEMORY_SIZE = 60 * CODE_MAX_SIZE;

constexpr hime_t TERMINATOR_CHAR = 0x3f;

using HimePassArray = hime_t[CODE_MAX_SIZE];

extern hime_t codeArray7e1680[CODE_MAX_SIZE];
extern hime_t notsure7e1640[CODE_MAX_SIZE];
extern hime_t notsure000000[SIMU_MEMORY_SIZE];
extern std::map<hime_t, std::pair<uint16_t, char16_t> > g_conv;

extern hime_t notsure7e0070;
extern hime_t notsure7e0072;


std::size_t password_decode_to_bits(HimePassArray aPassword, HimePassArray aOut7e1640, HimePassArray aOut7e1641);

enum HimePasswordType
{
    PASSWORD_TYPE_INVALID = 0,

    // the value is checksum for length, and only these lengths are allowed
    PASSWORD_TYPE_SHORT_7 = 2,
    PASSWORD_TYPE_SHORT_8 = 3,
    PASSWORD_TYPE_LONG_32 = 27,
    PASSWORD_TYPE_LONG_56 = 51
};

bool is_long_password_type(const HimePasswordType passtype);

bool is_short_password_type(const HimePasswordType passtype);

bool is_valid_password_type(const HimePasswordType passtype);

HimePasswordType password_length_to_type_checksum(const hime_t length);

bool verify_password_checksum(const hime_t length,
                              HimePassArray aOut7e1640,
                              hime_t& newLength);

void decode_data_against_table(const hime_t plus2Length,
                               HimePassArray aOut7e1640);


void load_values_part1(const bool isLongPasswordType);

#endif // HIME_H
