#ifndef _core_iterable_iterator
#define _core_iterable_iterator ::core_iterable_iterator

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_iterable_iterator, core_iterable_iterator_);

#include <core/Array.type.h>
#include <core/Hash_table.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Size.type.h>
#include <core/Utf8.type.h>
#include <core/base_object.h>

template<typename A>
inline constexpr auto core_iterable_iterator_<
    A *
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return _core_Size{0};
};

template<typename A, auto n>
inline constexpr auto core_iterable_iterator_<
    A [n]
> = core_iterable_iterator_<
    A *
>;

template<typename ... A>
inline constexpr auto core_iterable_iterator_<
    _core_Array<A ...>
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return 0;
};

template<typename A, typename B, typename HashFunction>
inline constexpr auto core_iterable_iterator_<
    _core_Hash_table<A, B, HashFunction>
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return _core_Product<_core_Size, _core_Size>{_core_Size{0}, _core_Size{0}};
};

template<typename A>
inline constexpr auto core_iterable_iterator_<
    _core_Null_terminated_string<A>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_iterable_iterator(_core_base_object(f));
};

template<typename A>
inline constexpr auto core_iterable_iterator_<
    _core_Utf8<A>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_iterable_iterator(_core_base_object(f));
};

#endif
