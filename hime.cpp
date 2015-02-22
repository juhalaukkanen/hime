#include "hime.h"

#include <cstdint>
#include <cstddef>
#include <stack>
#include <map>

#include <cstdio>

#include <random>

//ninja goemon
//
//7e0560 - cursor
//7E1630 - top = 0, bottom = 1
//7E1640 - password
//7E1680 - -==-
//
//$00/AD5D -> check?
//$07/B98D -> check -> B98D:B9B4

hime_t codeArray7e1680[CODE_MAX_SIZE]; // code input (encoded)
hime_t& notsure7e1630 = notsure000000[0x1630]; // if long or short password
hime_t notsure7e1640[CODE_MAX_SIZE]; // code output (decoded)
hime_t *notsure7e1641 = &notsure7e1640[1];
hime_t *notsure7e1642 = &notsure7e1640[2];
hime_t notsure7e0070 = 0; // apparently ctrls screen to show
hime_t notsure7e0072 = 0;

hime_t& notsure000016 = notsure000000[0x16]; // sub_b767 sets this as output
hime_t& notsure000018 = notsure000000[0x18]; // sub_b801 sets this as output

hime_t& notsure7e0082 = notsure000000[0x82]; // Controls the world to be loaded (major, max 10)
hime_t& notsure7e008e = notsure000000[0x8e]; // Controls the world to be loaded (minor, max 8)
hime_t& notsure0000a8 = notsure000000[0xa8]; // Players: 0->?, 1->goemon, 2->dr, 3->both

hime_t& player1Money = notsure000000[0x1aac]; // Goemon's monies

bool initialLengthCheckPassed = true;
/*
04 82 00 02 AA 00 04 8E 00 02 A8 00 04 F6 19 00
FF FF 10 1C 00 04 1E 00 04 20 00 05 22 00 04 24
00 06 2A 00 05 18 00 05 1A 00 01 46 00 01 48 00
01 4A 00 01 4C 00 08 50 00 08 52 00 08 54 00 08
60 00 08 62 00 08 64 00 08 70 00 08 80 00 08 82
00 08 84 00 01 90 00 01 92 00 01 94 00 01 96 00
01 98 00 01 9A 00 02 28 00 00
FF FF 04 82 00 02
A8 00 00 FF FF 01 46 00 01 48 00 01 4A 00
01 4C
00 00 FF FF 01 00 02 00 03 00 04 00 05 00 06 00
07 00 08 00 09 00 0A 00 0B 00 0C 00 0D 00 0E 00
0F 00 10 00 11 00 12 00 13 00 14 00 15 00 16 00
17 00 18 00 19 00 1A 00 1B 00 1C 00 1D 00 1E 00
1F 00 20 00 21 00 22 00 23 00 24 00 25 00 26 00
2C 00 27 00 28 00 29 00 2A 00 2B 00 06 39 07 39
08 39 09 39 0A 39 0B 39 0C 39 0D 39 0E 39 0F 39
10 39 11 39 12 39 13 39 14 39 1A 3A 1B 3A 1C 3A
1D 3A 1E 3A
*/
constexpr hime_t notsure02ef36[] = {  0x8204, 0x0200, 0x00AA, 0x8E04, 0x0200, 0x00A8, 0xF604, 0x0019, 0xFFFF, 0x1C10, // swapped
                            0x0400, 0x001E, 0x2004, 0x0500, 0x0022, 0x2404, 0x0600, 0x002A, 0x1805,
                            0x0500, 0x001A, 0x4601, 0x0100, 0x0048, 0x4A01, 0x0100, 0x004C, 0x5008, 0x0800,
                            0x0052, 0x5408, 0x0800, 0x0060, 0x6208, 0x0800, 0x0064, 0x7008, 0x0800, 0x0080,
                            0x8208, 0x0800, 0x0084, 0x9001, 0x0100, 0x0092, 0x9401, 0x0100, 0x0096, 0x9801,
                            0x0100, 0x009A, 0x2802, 0x0000, /*0xef36 - 0xef9f here*/
          /* 0xefa0 here */ 0xFFFF, 0x8204, 0x0200, 0x00a8, 0xff00, 0x01ff, 0x0046, 0x4801, 0x0100, 0x004a,
                            0x4c01, 0x0000, 0xFFFF, 0x0001
                         };

std::map<hime_t, std::pair<uint16_t, char16_t> > g_conv;
void init_conv()
{
    //g_conv[0x003F] = std::make_pair(1, 0);
    g_conv[0x0001] = std::make_pair(0, 0x3042); // 0x1(gamevalue) = 0(bitvalue) = あ(unicode)
    g_conv[0x0002] = std::make_pair(2, 0x3044); // 0x2(gamevalue) = 2(bitvalue) = い(unicode)
    g_conv[0x0003] = std::make_pair(4, 0x3046); // 0x3(gamevalue) = 4(bitvalue) = う(unicode)
    g_conv[0x0004] = std::make_pair(6, 0x3048); // 0x4(gamevalue) = 6(bitvalue) = え(unicode)
    g_conv[0x0005] = std::make_pair(8, 0x304a); // 0x5(gamevalue) = 8(bitvalue) = お(unicode)

    g_conv[0x0006] = std::make_pair(10, 0x304b); // 0x6(gamevalue) = 10(bitvalue) = か(unicode)
    g_conv[0x0007] = std::make_pair(12, 0x304d); // 0x7(gamevalue) = 12(bitvalue) = き(unicode)
    g_conv[0x0008] = std::make_pair(14, 0x304f); // 0x8(gamevalue) = 14(bitvalue) = く(unicode)
    g_conv[0x0009] = std::make_pair(16, 0x3051); // 0x9(gamevalue) = 16(bitvalue) = け(unicode)
    g_conv[0x000A] = std::make_pair(18, 0x3053); // 0xA(gamevalue) = 18(bitvalue) = こ(unicode)

    g_conv[0x000B] = std::make_pair(20, 0x3055); // 0xB(gamevalue) = 20(bitvalue) = さ(unicode)
    g_conv[0x000C] = std::make_pair(22, 0x3057); // 0xC(gamevalue) = 22(bitvalue) = し(unicode)
    g_conv[0x000D] = std::make_pair(24, 0x3059); // 0xD(gamevalue) = 24(bitvalue) = す(unicode)
    g_conv[0x000E] = std::make_pair(26, 0x305b); // 0xE(gamevalue) = 26(bitvalue) = せ(unicode)
    g_conv[0x000F] = std::make_pair(28, 0x305d); // 0xF(gamevalue) = 28(bitvalue) = そ(unicode)

    g_conv[0x0010] = std::make_pair(30, 0x305f); // 0x10(gamevalue) = 30(bitvalue) = た(unicode)
    g_conv[0x0011] = std::make_pair(32, 0x3061); // 0x11(gamevalue) = 32(bitvalue) = ち(unicode)
    g_conv[0x0012] = std::make_pair(34, 0x3064); // 0x12(gamevalue) = 34(bitvalue) = つ(unicode)
    g_conv[0x0013] = std::make_pair(36, 0x3066); // 0x13(gamevalue) = 36(bitvalue) = て(unicode)
    g_conv[0x0014] = std::make_pair(38, 0x3068); // 0x14(gamevalue) = 38(bitvalue) = と(unicode)

    g_conv[0x0015] = std::make_pair(40, 0x306a); // 0x15(gamevalue) = 40(bitvalue) = な(unicode)
    g_conv[0x0016] = std::make_pair(42, 0x306b); // 0x16(gamevalue) = 42(bitvalue) = に(unicode)
    g_conv[0x0017] = std::make_pair(44, 0x306c); // 0x17(gamevalue) = 44(bitvalue) = ぬ(unicode)
    g_conv[0x0018] = std::make_pair(46, 0x306d); // 0x18(gamevalue) = 46(bitvalue) = ね(unicode)
    g_conv[0x0019] = std::make_pair(48, 0x306e); // 0x19(gamevalue) = 48(bitvalue) = の(unicode)

    g_conv[0x001A] = std::make_pair(50, 0x306f); // 0x1A(gamevalue) = 50(bitvalue) = は(unicode)
    g_conv[0x001B] = std::make_pair(52, 0x3072); // 0x1B(gamevalue) = 52(bitvalue) = ひ(unicode)
    g_conv[0x001C] = std::make_pair(54, 0x3075); // 0x1C(gamevalue) = 54(bitvalue) = ふ(unicode)
    g_conv[0x001D] = std::make_pair(56, 0x3078); // 0x1D(gamevalue) = 56(bitvalue) = へ(unicode)
    g_conv[0x001E] = std::make_pair(58, 0x307b); // 0x1E(gamevalue) = 58(bitvalue) = ほ(unicode)

    g_conv[0x001F] = std::make_pair(60, 0x307e); // 0x1F(gamevalue) = 60(bitvalue) = ま(unicode)
    g_conv[0x0020] = std::make_pair(62, 0x307f); // 0x20(gamevalue) = 62(bitvalue) = み(unicode)
    g_conv[0x0021] = std::make_pair(64, 0x3080); // 0x21(gamevalue) = 64(bitvalue) = む(unicode)
    g_conv[0x0022] = std::make_pair(66, 0x3081); // 0x22(gamevalue) = 66(bitvalue) = め(unicode)
    g_conv[0x0023] = std::make_pair(68, 0x3082); // 0x23(gamevalue) = 68(bitvalue) = も(unicode)

    g_conv[0x0024] = std::make_pair(70, 0x3084); // 0x24(gamevalue) = 70(bitvalue) = や(unicode)
    g_conv[0x0025] = std::make_pair(72, 0x3086); // 0x25(gamevalue) = 72(bitvalue) = ゆ(unicode)
    g_conv[0x0026] = std::make_pair(74, 0x3088); // 0x26(gamevalue) = 74(bitvalue) = よ(unicode)
    g_conv[0x002C] = std::make_pair(76, 0x308f); // 0x2C(gamevalue) = 76(bitvalue) = わ(unicode)
    g_conv[0x0027] = std::make_pair(78, 0x3089); // 0x27(gamevalue) = 78(bitvalue) = ら(unicode)

    g_conv[0x0028] = std::make_pair(80, 0x308a); // 0x28(gamevalue) = 80(bitvalue) = り(unicode)
    g_conv[0x0029] = std::make_pair(82, 0x308b); // 0x29(gamevalue) = 82(bitvalue) = る(unicode)
    g_conv[0x002A] = std::make_pair(84, 0x308c); // 0x2A(gamevalue) = 84(bitvalue) = れ(unicode)
    g_conv[0x002B] = std::make_pair(86, 0x308d); // 0x2B(gamevalue) = 86(bitvalue) = ろ(unicode)

    g_conv[0x3906] = std::make_pair(88, 0x304c); // 0x3906(gamevalue) = 88(bitvalue) = が(unicode)
    g_conv[0x3907] = std::make_pair(90, 0x304e); // 0x3907(gamevalue) = 90(bitvalue) = ぎ(unicode)
    g_conv[0x3908] = std::make_pair(92, 0x3050); // 0x3908(gamevalue) = 92(bitvalue) = ぐ(unicode)
    g_conv[0x3909] = std::make_pair(94, 0x3052); // 0x3909(gamevalue) = 94(bitvalue) = げ(unicode)
    g_conv[0x390A] = std::make_pair(96, 0x3054); // 0x390A(gamevalue) = 96(bitvalue) = ご(unicode)

    g_conv[0x390B] = std::make_pair(98,  0x3056); // 0x390B(gamevalue) =  98(bitvalue) = ざ(unicode)
    g_conv[0x390C] = std::make_pair(100, 0x3058); // 0x390C(gamevalue) = 100(bitvalue) = じ(unicode)
    g_conv[0x390D] = std::make_pair(102, 0x305a); // 0x390D(gamevalue) = 102(bitvalue) = ず(unicode)
    g_conv[0x390E] = std::make_pair(104, 0x305c); // 0x390E(gamevalue) = 104(bitvalue) = ぜ(unicode)
    g_conv[0x390F] = std::make_pair(106, 0x305e); // 0x390F(gamevalue) = 106(bitvalue) = ぞ(unicode)

    g_conv[0x3910] = std::make_pair(108, 0x3060); // 0x3910(gamevalue) = 108(bitvalue) = だ(unicode)
    g_conv[0x3911] = std::make_pair(110, 0x3062); // 0x3911(gamevalue) = 110(bitvalue) = ぢ(unicode)
    g_conv[0x3912] = std::make_pair(112, 0x3065); // 0x3912(gamevalue) = 112(bitvalue) = づ(unicode)
    g_conv[0x3913] = std::make_pair(114, 0x3067); // 0x3913(gamevalue) = 114(bitvalue) = で(unicode)
    g_conv[0x3914] = std::make_pair(116, 0x3069); // 0x3914(gamevalue) = 116(bitvalue) = ど(unicode)

    g_conv[0x3A1A] = std::make_pair(118, 0x3071); // 0x3A1A(gamevalue) = 118(bitvalue) = ぱ(unicode)
    g_conv[0x3A1B] = std::make_pair(120, 0x3074); // 0x3A1B(gamevalue) = 120(bitvalue) = ぴ(unicode)
    g_conv[0x3A1C] = std::make_pair(122, 0x3077); // 0x3A1C(gamevalue) = 122(bitvalue) = ぷ(unicode)
    g_conv[0x3A1D] = std::make_pair(124, 0x307a); // 0x3A1D(gamevalue) = 124(bitvalue) = ぺ(unicode)
    g_conv[0x3A1E] = std::make_pair(126, 0x307d); // 0x3A1E(gamevalue) = 126(bitvalue) = ぽ(unicode)
}

std::stack<hime_t> g_stack;

hime_t getFromValueTable(uint8_t eightBitIndex)
{
    const uint16_t* valueTable = notsure02ef36;
    const std::uint8_t* ptrIndex = reinterpret_cast<const std::uint8_t*>(valueTable);
    hime_t value = *reinterpret_cast<const uint16_t*>(&ptrIndex[eightBitIndex]);

    constexpr hime_t MAX_INDEX = sizeof(notsure02ef36);
    if (eightBitIndex > MAX_INDEX)
    {
        printf("Detected pulling outside of the value table! (%u vs. %u)\n", eightBitIndex, MAX_INDEX);
    }
    return value;
}

hime_t getFromValueTable(hime_t valueOffset, uint8_t eightBitIndex)
{
    const uint16_t* const valueTable = notsure02ef36 + (valueOffset - 0xef37);
    const std::uint8_t* ptrIndex = reinterpret_cast<const std::uint8_t*>(valueTable);
    hime_t value = *reinterpret_cast<const uint16_t*>(&ptrIndex[eightBitIndex]);
    return value;
}

static bool bit16EmuMode = true;
hime_t readWeird16BitValue(const hime_t* const baseAddr)
{
    if (bit16EmuMode)
    {
        const hime_t value16 = baseAddr[1] << 8 | baseAddr[0];
        return value16;
    }
    else
    {
        const hime_t value8 = baseAddr[0];
        return value8;
    }
}

void writeWeird16BitValue(hime_t* const baseAddr, const hime_t value)
{
    if (bit16EmuMode)
    {
        baseAddr[1] = (value & 0xFF00) >> 8;
        baseAddr[0] = value & 0x00FF;
    }
    else
    {
        baseAddr[0] = value & 0x00FF;
    }
}

std::size_t password_decode_to_bits(HimePassArray aPassword,
                                    HimePassArray aOut7e1640,
                                    HimePassArray aOut7e1641)
{
    unsigned indeX = 0;
    unsigned length = 0;
    while (length <= CODE_MAX_SIZE)
    {
        const hime_t ch = aPassword[indeX];
        if (ch == TERMINATOR_CHAR)
        {
            break;
        }
        const hime_t bitsValue = g_conv[ch].first;
        aOut7e1640[length] = bitsValue >> 1;
        aOut7e1641[length] = 0;

        ++length;
        indeX += 2;
    }

    return length + 1;
}

bool is_long_password_type(const HimePasswordType passtype)
{
    return passtype == HimePasswordType::PASSWORD_TYPE_LONG_32 ||
            passtype == HimePasswordType::PASSWORD_TYPE_LONG_56;
}

bool is_short_password_type(const HimePasswordType passtype)
{
    return passtype == HimePasswordType::PASSWORD_TYPE_SHORT_7 ||
            passtype == HimePasswordType::PASSWORD_TYPE_SHORT_8;
}

bool is_valid_password_type(const HimePasswordType passtype)
{
    return is_long_password_type(passtype) || is_short_password_type(passtype);
}

HimePasswordType password_length_to_type_checksum(const hime_t length)
{
    hime_t len_minus_4_is_notsure7e0016 = length - 4 - 1; // minus one since the original code used 0 as length 1
    hime_t some_counter_is_notsure7e1630 = 0; // TODO: remember to give 1 here if long

    constexpr hime_t PASSLEN_32_CHARS = 0x1b;
    constexpr hime_t PASSLEN_56_CHARS = 0x33;
    constexpr hime_t PASSLEN_7_CHARS = 0x2;
    constexpr hime_t PASSLEN_8_CHARS = 0x3;

    return static_cast<HimePasswordType>(len_minus_4_is_notsure7e0016);
}

bool verify_password_checksum(const hime_t typeLength,
                              HimePassArray aOut7e1640,
                              hime_t& newLength)
{
    uint8_t u8Arit = aOut7e1640[1];
    u8Arit ^= 0x15;
    u8Arit -= 7;
    u8Arit &= 0x3f;
    aOut7e1640[1] = u8Arit;

    u8Arit = aOut7e1640[0];
    u8Arit ^= 0x2a;
    u8Arit -= aOut7e1640[1];
    u8Arit &= 0x3f;
    aOut7e1640[0] = u8Arit;

    // TODO: does valid passwd always equal the same?
    if (typeLength != aOut7e1640[0])
    {
        //notsure7e0016 = *notsure7e1640;
        newLength = aOut7e1640[0];
        return false; // TODO: why?
    }

    newLength = typeLength + 2;
    return true;
}

void decode_data_against_table(const hime_t plus2Length,
                               HimePassArray aOut7e1640)
{
    for (hime_t i = 0; i < plus2Length; ++i)
    {
        const uint8_t* const notsure02ef36_8 = reinterpret_cast<const uint8_t*>(notsure02ef36);
        aOut7e1640[2+i] ^= notsure02ef36_8[i];
        aOut7e1640[2+i] -= aOut7e1640[1];
        aOut7e1640[2+i] &= 0x3f;
    }
}

void load_values_aka_sub_b7b0(hime_t valueOffset)
{
    // X-> 0x7e0000 (valueoffset A)
    // Y-> 0x7e0002 (valueoffset B)
    // A,X,Y=0
    // Stack 1 -> 2
    // A<-0x7e0000

    //notsure000012 = curA;

    // gets from X high value
    //sub_b7f1();
    //notsure00000c = 6;
    //curA = (notsure7e1641[curX] << 2) & 0xFF00;
    //notsure00000e = curA;
}

void compute_checksum_from_loaded_values_aka_sub_b801()
{

}

//$07/B97A 8B          PHB                     A:0000 X:FFFE Y:0008 P:envmxdIZc
//$07/B97B E2 20       SEP #$20                A:0000 X:FFFE Y:0008 P:envmxdIZc
//$07/B97D A9 02       LDA #$02                A:0000 X:FFFE Y:0008 P:envMxdIZc
//$07/B97F 48          PHA                     A:0002 X:FFFE Y:0008 P:envMxdIzc
//$07/B980 AB          PLB                     A:0002 X:FFFE Y:0008 P:envMxdIzc
//$07/B981 C2 20       REP #$20                A:0002 X:FFFE Y:0008 P:envMxdIzc
//$07/B983 A0 00 00    LDY #$0000              A:0002 X:FFFE Y:0008 P:envmxdIzc
//$07/B986 A2 00 00    LDX #$0000              A:0002 X:FFFE Y:0000 P:envmxdIZc
bool check_sub_07_b97a(DEBUG_VERIFY debug_level)
{
    // TODO pulls something from caller
    while (!g_stack.empty())
    {
        g_stack.pop();
    }

    hime_t rA = 2;
    g_stack.push(rA);
    hime_t rY = 0, rX = 0;

lbl_b989:	
    //$07/B989 5A          PHY                     A:0000 X:0002 Y:0001 P:envmxdIzc
    //$07/B98A A0 00 00    LDY #$0000              A:0000 X:0002 Y:0001 P:envmxdIzc
    //$07/B98D BD 80 16    LDA $1680,x[$02:1680]   A:0002 X:0000 Y:0000 P:envmxdIZc
    //$07/B990 C9 3F 00    CMP #$003F              A:0001 X:0000 Y:0000 P:envmxdIzc
    //$07/B993 F0 1F       BEQ $1F    [$B9B4]      A:0001 X:0000 Y:0000 P:eNvmxdIzc
    //$07/B995 E0 78 00    CPX #$0078              A:0001 X:0000 Y:0000 P:eNvmxdIzc
    g_stack.push(rY); // TODO rY is ctr
    rY = 0;
    hime_t ch = codeArray7e1680[rX];
    if ((ch != 0x3f) && rX <= 0x78)
    {
        //$07/B99A D9 BA EF    CMP $EFBA,y[$02:EFBA]   A:0001 X:0000 Y:0000 P:eNvmxdIzc
        //$07/B99D F0 04       BEQ $04    [$B9A3]      A:0001 X:0000 Y:0000 P:envmxdIZC
        //$07/B99F C8          INY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9A0 C8          INY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        rY = g_conv[ch].first;

        //$07/B9A3 98          TYA                     A:0001 X:0000 Y:0000 P:envmxdIZC
        //$07/B9A4 4A          LSR A                   A:0000 X:0000 Y:0000 P:envmxdIZC
        //$07/B9A5 7A          PLY                     A:0000 X:0000 Y:0000 P:envmxdIZc
        //$07/B9A6 99 40 16    STA $1640,y[$02:1640]   A:0000 X:0000 Y:0000 P:envmxdIZc
        // TODO: this saves as little endian assumed.
        hime_t bitsValue = rY;
        bitsValue >>= 1;
        rY = g_stack.top(); g_stack.pop();
        notsure7e1640[rY] = bitsValue;
        //printf("Debg%i %x %x %x\n", rX, ch, rY, bitsValue);
        //$07/B9A9 A9 00 00    LDA #$0000              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9AC 99 41 16    STA $1641,y[$7E:1641]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        rA = 0;
        notsure7e1641[rY] = rA;

        //printf("%u,", notsure7e1640[rY]);
        //printf("1640[%u] = %x\n", rY, notsure7e1640[rY]);
        //printf("1641[%u] = %x\n", rY, notsure7e1641[rY]);

        //$07/B9AF C8          INY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9B0 E8          INX                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9B1 E8          INX                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9B2 80 D5       BRA $D5    [$B989]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        rY++;
        rX+=2;

        goto lbl_b989;
    }

    if (debug_level == DEBUG_VERIFY_LEVEL_1)
    {
        return false;
    }

    // B9B4
    //$07/B9B4 7A          PLY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9B5 9C 30 16    STZ $1630  [$7E:1630]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9B8 88          DEY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9B9 88          DEY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9BA 88          DEY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9BB 88          DEY                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    //$07/B9BC 84 16       STY $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    rY = g_stack.top(); g_stack.pop();
    notsure7e1630 = 0;
    rY -= 4;
    notsure000016 = rY;
    if (rY > 0) //$07/B9BE 10 03       BPL $03    [$B9C3]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    {
        //printf("Debg3 %x\n", rY);
        //B9C3
        //$07/B9C3 C0 02 00    CPY #$0002              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9C6 F0 12       BEQ $12    [$B9DA]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9C8 C0 03 00    CPY #$0003              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9CB F0 0D       BEQ $0D    [$B9DA]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9CD C0 1B 00    CPY #$001B              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9D0 F0 05       BEQ $05    [$B9D7]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9D2 C0 33 00    CPY #$0033              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/B9D5 D0 78       BNE $78    [$BA4F]      A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        switch (rY)
        {
            default:
                break;

            case 0x33:
            case 0x1b:
                //$07/B9D7 EE 30 16    INC $1630  [$7E:1630]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                notsure7e1630++;

            case 2:
            case 3:
            {
                //printf("Debg4 %x %x\n", rY, notsure7e1630);
                //$07/B9DA A5 16       LDA $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                //$07/B9DC 29 FF 00    AND #$00FF              A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                //$07/B9DF 85 16       STA $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                notsure000016 &= 0x00FF;

                //$07/B9E1 E2 20       SEP #$20                A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                //$07/B9E3 AD 41 16    LDA $1641  [$7E:1641]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9E6 49 15       EOR #$15                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9E8 38          SEC                     A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9E9 E9 07       SBC #$07                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9EB 29 3F       AND #$3F                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9ED 8D 41 16    STA $1641  [$7E:1641]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                *notsure7e1641 ^= 0x15;
                *notsure7e1641 -= 7;
                *notsure7e1641 &= 0x3f;

                //$07/B9F0 AD 40 16    LDA $1640  [$7E:1640]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9F3 49 2A       EOR #$2A                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9F5 38          SEC                     A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/B9F6 ED 41 16    SBC $1641  [$7E:1641]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                *notsure7e1640 ^= 0x2a;
                *notsure7e1640 -= *notsure7e1641;
                *notsure7e1640 &= 0x3f; // TODO maybe 0xff3f

                //$07/B9FE C5 16       CMP $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/BA00 F0 0E       BEQ $0E    [$BA10]      A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                if (notsure000016 != *notsure7e1640)
                {
                    // TODO: this is a bit uncertaining what this section means, so it is flagged as final warning
                    initialLengthCheckPassed = false;

                    //printf("1640 = %x\n", *notsure7e1640);
                    //printf("1641 = %x\n", *notsure7e1641);
                    //$07/BA02 85 16       STA $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                    notsure000016 = *notsure7e1640;

                    //$07/BA04 A5 70       LDA $70    [$00:0070]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                    //$07/BA06 C9 1A       CMP #$1A                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                    //$07/BA08 D0 06       BNE $06    [$BA10]      A:4AF0 X:1520 Y:0000 P:eNvMxdIzc

                    // This controls whether to actually load game (or just verify checksum)
                    if (notsure7e0070 == 0x1a)
                    {
                        //$07/BA0A A5 72       LDA $72    [$00:0072]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                        //$07/BA0C C9 06       CMP #$06                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                        //$07/BA0E B0 3F       BCS $3F    [$BA4F]      A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                        if (notsure7e0072 >= 0x06) // TODO carry? try to find test case here
                        {
                            goto lbl_ba4f;
                        }
                    }
                }
                else
                {
                    initialLengthCheckPassed = true;
                }

                /*
                 notsure7e0016 = 0x1b
                 notsure7e0070 = 0x1a
                 notsure7e0072 = 6
                 notsure7e1630 = 0x1
                 */

                //$07/BA10 E6 16       INC $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/BA12 E6 16       INC $16    [$00:0016]   A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                notsure000016 += 2;
                //$07/BA14 A2 00 00    LDX #$0000              A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                rX = 0;

                do
                {
                    // NOTE B9E1 sep made the accu 8bit
                    uint8_t* notsure02ef36_8 = (uint8_t*)notsure02ef36;
                    //$07/BA17 BD 42 16    LDA $1642,x[$02:1642]   A:001B X:0000 Y:001B P:envMxdIZC
                    //$07/BA1A 5D 36 EF    EOR $EF36,x[$02:EF36]   A:000C X:0000 Y:001B P:envMxdIzC
                    notsure7e1642[rX] ^= notsure02ef36_8[rX];

                    //if (rX > 0x18)printf("D1 %x %x %x\n", rX, notsure7e1642[rX], notsure02ef36_8[rX]);

                    //$07/BA1D 38          SEC                     A:0008 X:0000 Y:001B P:envMxdIzC
                    //$07/BA1E ED 41 16    SBC $1641  [$02:1641]   A:0008 X:0000 Y:001B P:envMxdIzC
                    //$07/BA21 29 3F       AND #$3F                A:00D0 X:0000 Y:001B P:eNvMxdIzc
                    //$07/BA23 9D 42 16    STA $1642,x[$02:1642]   A:0010 X:0000 Y:001B P:envMxdIzc
                    notsure7e1642[rX] -= *notsure7e1641;
                    //if (notsure7e1642[rX] > *notsure7e1641) notsure7e1642[rX] =0;
                    //if (rX > 0x18) printf("D2 %x %x %x\n", *notsure7e1641, notsure7e1642[rX], notsure7e0016);
                    notsure7e1642[rX] &= 0x3f;

                    //$07/BA26 E8          INX                     A:0010 X:0000 Y:001B P:envMxdIzc
                    rX++;
                    //$07/BA27 E4 16       CPX $16    [$00:0016]   A:0010 X:0001 Y:001B P:envMxdIzc
                    //$07/BA29 D0 EC       BNE $EC    [$BA17]      A:0010 X:0001 Y:001B P:eNvMxdIzc
                } while (rX < notsure000016);

                if (debug_level <= DEBUG_VERIFY_LEVEL_3)
                {
                    return false;
                }

                // TODO these subs load the values apparently
                //$07/BA2B C2 20       REP #$20                A:4AF0 X:1520 Y:0000 P:eNvMxdIzc
                //$07/BA2D 22 67 B7 07 JSL $07B767[$07:B767]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                //$07/BA31 22 01 B8 07 JSL $07B801[$07:B801]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
                //printf("Before subs: X: %x 0018: %x\n", rX, notsure7e0018);
                //for (unsigned i = 0; i < 60; ++i)
                //{
                //    printf("1640[%u] = %x\n", i, notsure7e1640[i]);
                //}
                sub_b767();
                //printf("After sub1 0016: %x 0018: %x\n", notsure000016, notsure000018);
                //for (unsigned i = 0; i < 60; ++i)
                //{
                //    printf("0000[%u] = %x\n", i, notsure000000[i]);
                //}
                sub_b801();
                //printf("After sub2 0016: %x 0018: %x\n", notsure000016, notsure000018);
                //for (unsigned i = 0; i < 60; ++i)
                //{
                //    printf("0000[%u] = %x\n", i, notsure000000[i]);
                //}

                //$07/BA35 A6 16       LDX $16    [$00:0016]   A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA37 A5 18       LDA $18    [$00:0018]   A:000F X:0002 Y:1A90 P:envmxdIzc
                rX = notsure000016;
                //$07/BA39 DD 42 16    CMP $1642,x[$02:1644]   A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA3C D0 11       BNE $11    [$BA4F]      A:000F X:0002 Y:1A90 P:envmxdIzc
                //printf("After subs: X: 0x%x 0018: %x 1640[2+%u] = %x\n", rX, notsure000018, rX, notsure7e1640[2+rX]);
                //for (unsigned i = 0; i < 60; ++i)
                //{
                //    printf("1640[%u] = %x\n", i, notsure7e1640[i]);
                //}
                //if (notsure7e1642[rX] != notsure7e0018)
                if (readWeird16BitValue(&notsure7e1640[2+rX]) != notsure000018)
                //if (notsure7e1640[2+rX] != notsure000018) // apparently 16bit, so need to use weidr read
                {
                    goto lbl_ba4f;
                }
                //printf("%x vs. %x (%x %x)\n", notsure7e1640[2+rX], notsure000018, readWeird16BitValue(&notsure7e1640[1+rX]), readWeird16BitValue(&notsure7e1640[3+rX]));
                //$07/BA3E A5 82       LDA $82    [$00:0082]   A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA40 C9 0A 00    CMP #$000A              A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA43 B0 0A       BCS $0A    [$BA4F]      A:000F X:0002 Y:1A90 P:envmxdIzc
                if (notsure7e0082 >= 0xa)
                {
                    printf("Passwd valid, but resulted in 82 overflow. %x %x\n", notsure7e0082, notsure000000[0x82]);
                    // TODO: negerate a case that goes here
                    goto lbl_ba4f;
                }
                //$07/BA45 A5 8E       LDA $8E    [$00:008E]   A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA47 C9 08 00    CMP #$0008              A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA4A B0 03       BCS $03    [$BA4F]      A:000F X:0002 Y:1A90 P:envmxdIzc
                if (notsure7e008e >= 0x8)
                {
                    printf("Passwd valid, but resulted in 8e overflow. %x\n", notsure7e008e);
                    goto lbl_ba4f;
                }

                if (!initialLengthCheckPassed)
                {
                    printf("Password resulted in length check segment!\n");
                    goto lbl_ba4f;
                }
                //$07/BA4C 38          SEC                     A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA4D AB          PLB                     A:000F X:0002 Y:1A90 P:envmxdIzc
                //$07/BA4E 6B          RTL                     A:000F X:0002 Y:1A90 P:envmxdIzc
                // TODO return values here are for success
                return true;
            }
        }
    }
lbl_ba4f:
    //$07/B9C0 4C 4F BA    JMP $BA4F  [$7E:BA4F]   A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
    {

        // TODO return values here are for failures
        //$07/BA4F C2 20       REP #$20                A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/BA51 18          CLC                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/BA52 AB          PLB                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        //$07/BA53 6B          RTL                     A:4AF0 X:1520 Y:0000 P:eNvmxdIzc
        return false;
    }
}

hime_t curX = 0;
hime_t curY = 0;
hime_t curA = 0;

hime_t notsure000000[SIMU_MEMORY_SIZE];
hime_t& notsure000002 = notsure000000[2];
hime_t& notsure000004 = notsure000000[4];
hime_t& notsure000008 = notsure000000[8];
hime_t& notsure00000a = notsure000000[0xa];
hime_t& notsure00000c = notsure000000[0xc];
hime_t& notsure00000e = notsure000000[0xe];

hime_t& notsure000010 = notsure000000[0x10];
hime_t& notsure000012 = notsure000000[0x12]; //uint16_t& notsure000012 = reinterpret_cast<uint16_t>(notsure000000[0x12]);
hime_t& notsure000014 = notsure000000[0x14];

const hime_t* notsure02ef48 = &notsure02ef36[9];
/*
00 04 1E 00 04 20 00 05 22 00 04 24 00 06
2A 00 05 18 00 05 1A 00 01 46 00 01 48 00 01 4A
00 01 4C 00 08 50 00 08 52 00 08 54 00 08 60 00
08 62 00 08 64 00 08 70 00 08 80 00 08 82 00 08
84 00 01 90 00 01 92 00 01 94 00 01 96 00 01 98
00 01 9A 00 02 28 00 00 FF FF 04 82 00 02 A8 00
00 FF FF 01 46 00 01 48 00 01 4A 00 01 4C 00 00
FF FF 01 00 02 00 03 00 04 00 05 00 06 00 07 00
08 00 09 00 0A 00 0B 00 0C 00 0D 00 0E 00 0F 00
10 00 11 00 12 00 13 00 14 00 15 00 16 00 17 00
18 00 19 00 1A 00 1B 00 1C 00 1D 00 1E 00 1F 00
20 00 21 00 22 00 23 00 24 00 25 00 26 00 2C 00
*/

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
}

void sub_b83d()
{
    hime_t& offset = notsure000012;
    hime_t& baseAddr = curY;
    offset = curA - 0xef36;

    hime_t count = 0;
    hime_t& checksum = notsure000018;
    while ((count = getFromValueTable(offset) & 0x00FF) != 0)
    {
        const hime_t mask = (1 << count) - 1;

        hime_t& storedAddress = notsure000014;
        storedAddress = getFromValueTable(++offset);

        hime_t& value = notsure000004;
        value = notsure000000[storedAddress + baseAddr] & mask;
        checksum += value;

        //printf("Value %x at %x with mask %x checksum %x count %u\n", value, storedAddress, mask, checksum, count);
        offset += 2;
    }
}

void sub_b801()
{
    //$07/B801 DA          PHX                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B802 8B          PHB                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B803 E2 20       SEP #$20                A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B805 A9 02       LDA #$02                A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B807 48          PHA                     A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B808 AB          PLB                     A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B809 C2 20       REP #$20                A:0019 X:001D Y:001B P:envMxdIZC
    g_stack.push(curX);
    curA = 2;
    g_stack.push(curA); // TODO broken.

    //$07/B80B 64 18       STZ $18    [$00:0018]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B80D A0 00 00    LDY #$0000              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B810 A5 00       LDA $00    [$00:0000]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B812 20 3D B8    JSR $B83D  [$07:B83D]   A:0019 X:001D Y:001B P:envmxdIZC
    notsure000018 = 0;
    curY = 0;
    curA = notsure000000[0];
    sub_b83d(); // TODO inputs and ouputs?

    //$07/B815 A5 A8       LDA $A8    [$00:00A8]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B817 29 01 00    AND #$0001              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B81A F0 08       BEQ $08    [$B824]      A:0019 X:001D Y:001B P:envmxdIZC
    curA = (notsure0000a8 & 1);
    if (curA)
    {
        //printf("Went here1 because %x %x\n", curA, notsure0000a8);
        //$07/B81C A0 90 1A    LDY #$1A90              A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B81F A5 02       LDA $02    [$00:0002]   A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B821 20 3D B8    JSR $B83D  [$07:B83D]   A:0019 X:001D Y:001B P:envmxdIZC
        curY = 0x1a90;
        curA = notsure000002;
        sub_b83d(); // TODO inputs and outputs?
    }
    //$07/B824 A5 A8       LDA $A8    [$00:00A8]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B826 29 02 00    AND #$0002              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B829 F0 08       BEQ $08    [$B833]      A:0019 X:001D Y:001B P:envmxdIZC
    curA = (notsure0000a8 & 2);
    if (curA)
    {
        //printf("Went here2 because %x %x\n", curA, notsure0000a8);
        //$07/B82B A0 40 1B    LDY #$1B40              A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B82E A5 02       LDA $02    [$00:0002]   A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B830 20 3D B8    JSR $B83D  [$07:B83D]   A:0019 X:001D Y:001B P:envmxdIZC
        curY = 0x1b40;
        curA = notsure000002;
        sub_b83d(); // TODO inputs and outputs?
    }


    //$07/B833 A5 18       LDA $18    [$00:0018]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B835 29 3F 3F    AND #$3F3F              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B838 85 18       STA $18    [$00:0018]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B83A AB          PLB                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B83B FA          PLX                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B83C 6B          RTL                     A:0019 X:001D Y:001B P:envmxdIZC
    notsure000018 &= 0x3f3f;
    curX = g_stack.top(); g_stack.pop();
}

void sub_b7f1()
{
    //$07/B7F1 A9 06 00    LDA #$0006              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7F4 85 0C       STA $0C    [$00:000C]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7F6 BD 41 16    LDA $1641,x[$02:165E]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7F9 0A          ASL A                   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7FA 0A          ASL A                   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7FB 29 00 FF    AND #$FF00              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7FE 85 0E       STA $0E    [$00:000E]   A:0019 X:001D Y:001B P:envmxdIZC
    notsure00000c = 6;
    curA = (readWeird16BitValue(&notsure7e1641[curX]) << 2) & 0xFF00;
#ifdef UNALIGNED_READ_WRITE
    writeWeird16BitValue(&notsure000000[0xe], curA);
#else
    notsure00000e = curA;
#endif
    //printf("B7f1 (e storer): curX: %x, 1641[curX]: %x %x, curA: %x -> 000e: %x 000f: %x\n",
    //       curX, notsure7e1641[curX+0], notsure7e1641[curX+1], curA, notsure00000e, notsure000000[0xf]);
    //$07/B800 60          RTS                     A:0019 X:001D Y:001B P:envmxdIZC
}

void sub_b7b0()
{
    // Store current A and call subroutine
    notsure000012 = curA;
    sub_b7f1(); // TODO: input x output = e

    const hime_t valueBase = notsure000012 - 0xef36;
    notsure000012 = valueBase;

    hime_t& offset = notsure000012;
    hime_t count;

    while ((count = getFromValueTable(offset) & 0x00FF) != 0)
    {
        // Store current values
        notsure000008 = count;
        notsure00000a = count;
        notsure000012++;

        // Get the next value from the table
        curA = getFromValueTable(notsure000012);
        notsure000014 = curA;
        notsure000010 = 0;

#define printBits(...)
#define printf(...)
        printf("binary1(%u): ", notsure000008);
        hime_t& payloadValue1 = notsure000010;
        for (hime_t i = count; i > 0; --i)
        {
            payloadValue1 <<= 1;
            if (notsure00000e & 0b1000000000000000)
            {
                payloadValue1 |= 1;
            }

            notsure00000e <<= 1;

            notsure00000c--;
            printBits(sizeof(payloadValue), &payloadValue);
            printf(" --> ");

            if (notsure00000c == 0)
            {
                curX++;
                sub_b7f1(); // TODO: input x output = e
            }
        }
        printf("%x\n", payloadValue);

        // Process the final shifts for curA
        printf("binary2(%u): ", notsure00000a);
        hime_t payloadValue2 = 0;
        while (notsure00000a > 0)
        {
            payloadValue2 <<= 1;
            if (payloadValue1 & 0b1)
            {
                payloadValue2 |= 1;
            }
            payloadValue1 >>= 1;
            notsure00000a--;
            printBits(sizeof(payloadValue2), &payloadValue2);
            printf(" ( ");
            printBits(sizeof(payloadValue), &payloadValue);
            printf(" ) ");
            printf(" --> ");
        }
        printf("%x\n", payloadValue2);
#undef printf
#undef printBits
        notsure000000[notsure000014 + curY] = payloadValue2;

        notsure000012 += 2;
    }

    // Final check and increment
    curA = notsure00000c;
    if (curA != 6) {
        curX++; // TODO output
    }
}

void sub_b767(DEBUG_VERIFY debug_level)
{
    //$07/B767 A2 36 EF    LDX #$EF36              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B76A A0 48 EF    LDY #$EF48              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B76D AD 30 16    LDA $1630  [$02:1630]   A:0019 X:001D Y:001B P:envmxdIZC
    curX = 0xEF36; //notsure7eef36;
    curY = 0xEF48; //notsure7eef48;
    curA = notsure7e1630;

    //$07/B770 D0 06       BNE $06    [$B778]      A:0019 X:001D Y:001B P:envmxdIZC
    if (!notsure7e1630)
    {
        //$07/B772 A2 A2 EF    LDX #$EFA2              A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B775 A0 AB EF    LDY #$EFAB              A:0019 X:001D Y:001B P:envmxdIZC
        curX = 0xEFA2; //notsure7eef2a;
        curY = 0xEFAB; //notsure7eefab;
    }
    //$07/B778 86 00       STX $00    [$00:0000]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B77A 84 02       STY $02    [$00:0002]   A:0019 X:001D Y:001B P:envmxdIZC
    notsure000000[0] = curX;
    notsure000002 = curY;

    //$07/B77C 8B          PHB                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B77D E2 20       SEP #$20                A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B77F A9 02       LDA #$02                A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B781 48          PHA                     A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B782 AB          PLB                     A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B783 C2 20       REP #$20                A:0019 X:001D Y:001B P:envMxdIZC
    //$07/B785 A2 00 00    LDX #$0000              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B788 9B          TXY                     A:0019 X:001D Y:001B P:envmxdIZC
    // NOTE: REP #$20 makes 16-bit now!
    bit16EmuMode = true;
    curA = 2;
    g_stack.push(curA);
    curX = curY = 0; // TODO what pull?

    //$07/B789 A5 00       LDA $00    [$00:0000]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B78B 20 B0 B7    JSR $B7B0  [$07:B7B0]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B78E A5 A8       LDA $A8    [$00:00A8]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B790 29 01 00    AND #$0001              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B793 F0 08       BEQ $08    [$B79D]      A:0019 X:001D Y:001B P:envmxdIZC
    curA = notsure000000[0];
    sub_b7b0();

    if (debug_level == DEBUG_VERIFY_LEVEL_1)
    {
        return;
    }

    curA = notsure0000a8 & 1;
    if (curA)
    {
        //printf("wrpng1: curA: %x 0002: %x and 00a8: %x\n", curA, notsure000002, notsure0000a8);
        //$07/B795 A0 90 1A    LDY #$1A90              A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B798 A5 02       LDA $02    [$00:0002]   A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B79A 20 B0 B7    JSR $B7B0  [$07:B7B0]   A:0019 X:001D Y:001B P:envmxdIZC
        curY = 0x1a90;
        curA = notsure000002;

        sub_b7b0();
    }

    if (debug_level == DEBUG_VERIFY_LEVEL_1_SECOND_b7b0)
    {
        return;
    }

    //$07/B79D A5 A8       LDA $A8    [$00:00A8]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B79F 29 02 00    AND #$0002              A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7A2 F0 08       BEQ $08    [$B7AC]      A:0019 X:001D Y:001B P:envmxdIZC
    curA = notsure0000a8 & 2;
    if (curA)
    {
        //printf("wrpng2: curA: %x 0002: %x and 00a8: %x\n", curA, notsure000002, notsure0000a8);
        //$07/B7A4 A0 40 1B    LDY #$1B40              A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B7A7 A5 02       LDA $02    [$00:0002]   A:0019 X:001D Y:001B P:envmxdIZC
        //$07/B7A9 20 B0 B7    JSR $B7B0  [$07:B7B0]   A:0019 X:001D Y:001B P:envmxdIZC
        curY = 0x1b40;
        curA = notsure000002;
        sub_b7b0();
    }

    //$07/B7AC 86 16       STX $16    [$00:0016]   A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7AE AB          PLB                     A:0019 X:001D Y:001B P:envmxdIZC
    //$07/B7AF 6B          RTL                     A:0019 X:001D Y:001B P:envmxdIZC
    notsure000016 = curX;
}
