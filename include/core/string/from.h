#ifndef _core_string_from
#define _core_string_from ::core_string_from

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_string_from, core_string_from_);

#include <core/Array.type.h>
#include <core/C_string.type.h>
#include <core/False.type.h>
#include <core/True.type.h>
#include <core/Utf8.type.h>
#include <core/unicode/ScalarValue.type.h>

template<typename A, typename Continuation>
inline constexpr auto core_string_from_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & f,
    auto & k
) {
    k(f);
};

template<typename Continuation>
inline constexpr auto core_string_from_<
    _core_False,
    Continuation
> = [] (
    auto &,
    auto & k
) constexpr {
    k(u8"False");
};

template<typename Continuation>
inline constexpr auto core_string_from_<
    _core_True,
    Continuation
> = [] (
    auto &,
    auto & k
) constexpr {
    k(u8"True");
};

template<typename Continuation>
inline constexpr auto core_string_from_<
    bool,
    Continuation
> = [] (
    auto & a,
    auto & k
) constexpr {
    if (a)
        _core_string_from(_core_True{}, k);
    else
        _core_string_from(_core_False{}, k);
};

#endif
