#ifndef _core_mathematics_complement
#define _core_mathematics_complement ::core_mathematics_complement

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_complement, core_mathematics_complement_);

#include <core/False.type.h>
#include <core/True.type.h>

template<typename A>
inline constexpr auto core_mathematics_complement_<
    A
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return ~ a;
};

template<>
inline constexpr auto core_mathematics_complement_<
    bool
> = [] (
    auto & a
) constexpr -> bool {
    return ! a;
};

template<>
inline constexpr auto core_mathematics_complement_<
    _core_False
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return _core_True{};
};

template<>
inline constexpr auto core_mathematics_complement_<
    _core_True
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return _core_False{};
};

#endif
