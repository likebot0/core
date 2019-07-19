#ifndef _core_mathematics_is_equal_to
#define _core_mathematics_is_equal_to ::core_mathematics_is_equal_to

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_is_equal_to, core_mathematics_is_equal_to_);

#include <core/Array.type.h>
#include <core/Default_tagged_union.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/Size.type.h>
#include <core/True.type.h>
#include <core/array/base_address.h>
#include <core/length.h>
#include <core/is.h>
#include <core/meta/Set.type.h>
#include <core/meta/contains.h>
#include <core/meta/is_unit_type.h>

template<typename A>
inline constexpr auto core_mathematics_is_equal_to_<
    A,
    A
> = [] (
    auto & x,
    auto & y
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_is_unit_type<A>)
        return _core_True{};
    else
        return x == y;
};

template<typename A, typename B>
inline constexpr auto core_mathematics_is_equal_to_<
    A,
    B
> = [] (
    auto & a,
    auto & b
) constexpr -> decltype(auto) {
    return a == b;
};

template<typename ... A, typename B>
inline constexpr auto core_mathematics_is_equal_to_<
    _core_Default_tagged_union<A ...>,
    B
> = [] (
    auto & a,
    auto & b
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_is_unit_type<B> && _core_meta_contains<_core_meta_Set<A ...>, B>)
        return _core_is<B>(a);
    else
        return a == b;
};

template<typename ... A, typename B>
inline constexpr auto core_mathematics_is_equal_to_<
    _core_Simple_tagged_union<A ...>,
    B
> = [] (
    auto & a,
    auto & b
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_contains<_core_meta_Set<A ...>, B>)
        return _core_is<B>(a);
    else
        return false;
};

template<typename A, typename B>
inline constexpr auto core_mathematics_is_equal_to_<
    A *,
    B *,
    _core_Size
> = [] (
    auto & a,
    auto & b,
    auto & n
) constexpr -> bool {
    for (auto i = _core_Size{0}; i != n; ++i)
    if  (a[i] != b[i])
        return false;

    return true;
};

template<typename A, typename B, _core_Size n>
inline constexpr auto core_mathematics_is_equal_to_<
    A [n],
    B [n]
> = [] (
    auto & f,
    auto & g
) constexpr -> bool {
    return _core_mathematics_is_equal_to(
        _core_array_base_address(f),
        _core_array_base_address(g),
        n
    );
};

template<typename A, _core_Size n, typename ... B>
inline constexpr auto core_mathematics_is_equal_to_<
    A [n],
    _core_Array<B ...>
> = [] (
    auto & f,
    auto & g
) constexpr -> bool {
    return
        _core_mathematics_is_equal_to(length(f), length(g))
     && _core_mathematics_is_equal_to(
            _core_array_base_address(f),
            _core_array_base_address(g),
            length(f)
        )
    ;
};

template<typename ... A, typename B, _core_Size n>
inline constexpr auto core_mathematics_is_equal_to_<
    _core_Array<A ...>,
    B [n]
> = [] (
    auto & f,
    auto & g
) constexpr -> bool {
    return _core_mathematics_is_equal_to(g, f);
};

template<typename ... A, typename ... B>
inline constexpr auto core_mathematics_is_equal_to_<
    _core_Array<A ...>,
    _core_Array<B ...>
> = [] (
    auto & f,
    auto & g
) constexpr -> bool {
    return
        _core_mathematics_is_equal_to(length(f), length(g))
     && _core_mathematics_is_equal_to(
            _core_array_base_address(f),
            _core_array_base_address(g),
            length(f)
        )
    ;
};

#endif
