#ifndef _core_mathematics_digits
#define _core_mathematics_digits ::core_mathematics_digits

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_digits, core_mathematics_digits_);

#include <core/Literal.type.h>

template<typename A>
inline constexpr auto core_mathematics_digits_<
    A
> = [] (
    auto & a
) constexpr -> A {
    auto x = A{1};

    for (auto z = a; z > 9; x = x + 1)
        z = z / 10;

    return x;
};

template<char32_t ... a>
inline constexpr auto core_mathematics_digits_<
    _core_Literal<a ...>
> = [] (
    auto &
) constexpr {
};

#endif
