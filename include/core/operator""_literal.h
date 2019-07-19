#ifndef _core_operatorU0022U0022_literal
#define _core_operatorU0022U0022_literal ::core_operator""_literal

#include <core/Literal.type.h>
#include <core/Array.type.h>

template<char ... a>
inline constexpr auto operator""_literal(
) -> decltype(auto) {
    return _core_Literal<char32_t{a} ...>{};
};

#endif
