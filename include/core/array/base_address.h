#ifndef _core_array_base_address
#define _core_array_base_address ::core_array_base_address

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_array_base_address, core_array_base_address_);

#include <core/Array.type.h>
#include <core/Boxed_array.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Octet.type.h>
#include <core/Pointer.type.h>
#include <core/Size.type.h>
#include <core/base_object.h>
#include <core/ieee/std/1003dot1/Iovec.type.h>
#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/iovec/base_address.h>
#include <core/meta/is_const_qualified.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<typename A, _core_Size n>
inline constexpr auto core_array_base_address_<
    A [n]
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_is_const_qualified<decltype(f)>)
        return (_core_Pointer<const A>) f;
    else
        return (_core_Pointer<A>) f;
};

template<typename ... A>
inline constexpr auto core_array_base_address_<
    _core_Array<A ...>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(0_literal)(_core_base_object(f));
};

template<typename A, _core_Size n>
inline constexpr auto core_array_base_address_<
    _core_Boxed_array<A, n>
> = [] (
    auto & f
) -> _core_Pointer<A> {
    return f.array;
};

template<typename A>
inline constexpr auto core_array_base_address_<
    _core_Null_terminated_string<A>
> = _core_base_object;

template<>
inline constexpr auto core_array_base_address_<
    _core_ieee_std_1003dot1_Iovec
> = _core_ieee_std_1003dot1_iovec_base_address;

template<typename A, typename N>
inline constexpr auto core_array_base_address_<
    _core_ieee_std_1003dot1_Memory<A, N>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(0_literal)(_core_base_object(f));
};

#endif
