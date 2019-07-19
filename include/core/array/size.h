#ifndef _core_array_size
#define _core_array_size ::core_array_size

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_array_size, core_array_size_);

#include <core/Array.type.h>
#include <core/Boxed_array.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Pointer.type.h>
#include <core/Size.type.h>
#include <core/array/base_address.h>
#include <core/base_object.h>
#include <core/ieee/std/1003dot1/Iovec.type.h>
#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/iovec/size.h>
#include <core/memory/address/dereference.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<typename A, _core_Size n>
inline constexpr auto core_array_size_<
    A [n]
> = [] (
    auto &
) constexpr -> decltype(auto) {
    return n;
};

template<typename ... A>
inline constexpr auto core_array_size_<
    _core_Array<A ...>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(1_literal)(_core_base_object(f));
};

template<typename A, _core_Size n>
inline constexpr auto core_array_size_<
    _core_Boxed_array<A, n>
> = [] (
    auto & f
) {
    return n;
};

template<typename A>
inline constexpr auto core_array_size_<
    _core_Null_terminated_string<A>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    auto i = _core_Size{0};

    while (_core_memory_address_dereference(_core_array_base_address(f) + i))
        i = i + 1;

    return i;
};

template<>
inline constexpr auto core_array_size_<
    _core_ieee_std_1003dot1_Iovec
> = _core_ieee_std_1003dot1_iovec_size;

template<typename A, typename N>
inline constexpr auto core_array_size_<
    _core_ieee_std_1003dot1_Memory<A, N>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(1_literal)(_core_base_object(f));
};

#endif
