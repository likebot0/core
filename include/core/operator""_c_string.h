#ifndef _core_operatorU0022U0022_c_string
#define _core_operatorU0022U0022_c_string ::core_operator""_c_string

#include <core/C_string.type.h>
#include <core/Pointer.type.h>
#include <core/Size.type.h>

inline constexpr auto operator""_c_string(
    _core_Pointer<const char> a,
    _core_Size n
) {
    return _core_C_string {a};
};

inline auto operator""_c_string(
    _core_Pointer<const char8_t> a,
    _core_Size n
) {
    return _core_C_string {a};
};

#endif
