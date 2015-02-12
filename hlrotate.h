#ifndef HL_ROTATE_H
#define HL_ROTATE_H

#include <cstddef>
#include <cstdint>
#include <climits>

#include <type_traits>

template <typename INT>
constexpr INT rotateLeft(INT val)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Left only makes sense for unsigned types");
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}

template <typename INT>
constexpr INT rotateRight(INT val)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Right only makes sense for unsigned types");
    return (val >> 1) | (val << (sizeof(INT)*CHAR_BIT - 1));
}

#endif
