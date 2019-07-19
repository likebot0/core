#ifndef _core_mathematics_tuple_concat
#define _core_mathematics_tuple_concat ::core_mathematics_tuple_concat

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_tuple_concat, core_mathematics_tuple_concat_);

#include <core/Array.type.h>
#include <core/Size.type.h>
#include <core/array/allocate.h>
#include <core/array/base_address.h>
#include <core/array/size.h>

template<typename A, typename N, typename M>
inline constexpr auto core_mathematics_tuple_concat_<
    _core_Array<A, N>,
    _core_Array<A, M>
> = [] (
    auto & f,
    auto & g
) {
    auto n = _core_array_size(f) + _core_array_size(g);

    auto h = _core_array_allocate<A *>(n);

    auto i = _core_Size{0};

    for (; i != _core_array_size(f); ++i)
        h[i] = f(i);

    for (; i != n; ++i)
        h[i] = g(i);

    return _core_Array<A>{h, n};
};

template<typename A, typename N, typename M>
inline constexpr auto core_mathematics_tuple_concat_<
    _core_Array<const A, N>,
    _core_Array<const A, M>
> = [] (
    auto & f,
    auto & g
) {
    auto n = _core_array_size(f) + _core_array_size(g);

    auto h = _core_array_allocate<A *>(n);

    auto i = _core_Size{0};

    for (; i != _core_array_size(f); ++i)
        h[i] = f(i);

    for (; i != n; ++i)
        h[i] = g(i);

    return _core_Array<A>{h, n};
};

template<typename A, _core_Size n>
inline constexpr auto core_mathematics_tuple_concat_<
    _core_Array<A, _core_Size>,
    A [n]
> = [] (
    auto & f,
    auto & g
) -> decltype(auto) {
    return concat(
        f,
        _core_Array{_core_array_base_address(g), _core_array_size(g)}
    );
};

template<typename A, _core_Size n>
inline constexpr auto core_mathematics_tuple_concat_<
    A [n],
    _core_Array<A, _core_Size>
> = [] (
    auto & f,
    auto & g
) -> decltype(auto) {
    return concat(
        _core_Array{_core_array_base_address(f), _core_array_size(f)},
        g
    );
};

#endif
