#ifndef _core_mathematics_join
#define _core_mathematics_join ::core_mathematics_join

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_join, core_mathematics_join_);

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/mathematics/id.h>

template<typename A>
inline constexpr auto core_mathematics_join_<
    A
> = _core_mathematics_id;

template<typename A, typename B>
inline constexpr auto core_mathematics_join_<
    A,
    B
> = [] (
    auto & a,
    auto & b
) constexpr -> decltype(auto) {
    return a | b;
};

template<typename A, typename B, typename ... X>
inline constexpr auto core_mathematics_join_<
    A,
    B,
    X ...
> = [] (
    auto & a,
    auto & b,
    auto & ... x
) constexpr -> decltype(auto) {
    return _core_mathematics_join(_core_mathematics_join(a, b), x ...);
};

template<>
inline constexpr auto core_mathematics_join_<
    _core_False,
    _core_False
> = [] (
    auto,
    auto &
) constexpr -> decltype(auto) {
    return _core_False{};
};

template<>
inline constexpr auto core_mathematics_join_<
    _core_False,
    _core_True
> = [] (
    auto,
    auto &
) constexpr -> decltype(auto) {
    return _core_True{};
};

template<>
inline constexpr auto core_mathematics_join_<
    _core_True,
    _core_False
> = [] (
    auto,
    auto &
) constexpr -> decltype(auto) {
    return _core_True{};
};

template<>
inline constexpr auto core_mathematics_join_<
    _core_True,
    _core_True
> = [] (
    auto,
    auto &
) constexpr -> decltype(auto) {
    return _core_True{};
};

#endif
