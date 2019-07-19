#ifndef _core_mathematics_tuple_length
#define _core_mathematics_tuple_length ::core_mathematics_tuple_length

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_tuple_length, core_mathematics_tuple_length_);

#include <core/Array.type.h>
#include <core/Hash_table.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Pointer.type.h>
#include <core/Product.type.h>
#include <core/Size.type.h>
#include <core/array/size.h>
#include <core/hash_table/size.h>
#include <core/preprocessor/end.h>
#include <core/preprocessor/for_each.h>
#include <core/meta/Tuple.type.h>
#include <core/meta/length.h>

template<typename A>
inline constexpr auto core_mathematics_tuple_length_<
    A
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    auto i = _core_Size{0};

    _core_preprocessor_for_each(_, a)
        i = i + 1;
    _core_preprocessor_end

    return i;
};

template<typename A, _core_Size n>
inline constexpr auto core_mathematics_tuple_length_<
    A [n]
> = _core_array_size;

template<typename ... A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_mathematics_Product0<A ...>
> = [] (
    auto &
) constexpr {
    return _core_meta_length<_core_meta_Tuple<A ...>>;
};

template<typename ... A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_mathematics_Product1<A ...>
> = [] (
    auto &
) constexpr {
    return _core_meta_length<_core_meta_Tuple<A ...>>;
};

template<typename ... A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_mathematics_Product2<A ...>
> = [] (
    auto &
) constexpr {
    return _core_meta_length<_core_meta_Tuple<A ...>>;
};

template<typename ... A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_mathematics_Product3<A ...>
> = [] (
    auto &
) constexpr {
    return _core_meta_length<_core_meta_Tuple<A ...>>;
};

template<typename ... A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_Array<A ...>
> = _core_array_size;

template<typename A>
inline constexpr auto core_mathematics_tuple_length_<
    _core_Null_terminated_string<A>
> = _core_array_size;

#endif
