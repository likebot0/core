#ifndef _core_operatorU0022U0022_array
#define _core_operatorU0022U0022_array ::core_operator""_array

#include <core/Array.type.h>
#include <core/Hextet.type.h>
#include <core/Octet.type.h>
#include <core/Pointer.type.h>
#include <core/Quadlet.type.h>
#include <core/Size.type.h>

inline constexpr auto operator""_array(
    _core_Pointer<const char> a,
    _core_Size n
) {
    return _core_Array<
        _core_Pointer<const char>,
        _core_Size
    >{
        a,
        n
    };
}

inline constexpr auto operator""_array(
    _core_Pointer<const char8_t> a,
    _core_Size n
) {
    return _core_Array<
        _core_Pointer<const char8_t>,
        _core_Size
    >{
        a,
        n
    };
}

inline constexpr auto operator""_array(
    _core_Pointer<const char16_t> a,
    _core_Size n
) {
    return _core_Array<
        _core_Pointer<const char16_t>,
        _core_Size
    >{
        a,
        n
    };
}

inline constexpr auto operator""_array(
    _core_Pointer<const char32_t> a,
    _core_Size n
) {
    return _core_Array<
        _core_Pointer<const char32_t>,
        _core_Size
    >{
        a,
        n
    };
}

#endif
