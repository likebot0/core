#ifndef _core_mathematics_map_apply
#define _core_mathematics_map_apply ::core_mathematics_map_apply

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_map_apply, core_mathematics_map_apply_);

#include <core/Default_tagged_union.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/Untagged_union.type.h>
#include <core/base_object.h>
#include <core/mathematics/Product.type.h>
#include <core/mathematics/Product0.type.h>
#include <core/mathematics/Product1.type.h>
#include <core/mathematics/Product2.type.h>
#include <core/mathematics/Product3.type.h>
#include <core/mathematics/map/call_with_indices.h>
#include <core/operator""_literal.h>
#include <core/tagged_union/Unsafe_cast.h>
#include <core/untagged_union/Unsafe_cast.h>
#include <core/projection.h>

template<typename F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    F,
    _core_mathematics_Product0<A ...>
> = [] (
    auto & f,
    auto & a
) -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) -> decltype(auto) {
            return f(_core_projection(i)(a) ...);
        }
    );
};

template<typename F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    F,
    _core_mathematics_Product1<A ...>
> = [] (
    auto & f,
    auto & a
) -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) -> decltype(auto) {
            return f(_core_projection(i)(a) ...);
        }
    );
};

template<typename F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    F,
    _core_mathematics_Product2<A ...>
> = [] (
    auto & f,
    auto & a
) -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) -> decltype(auto) {
            return f(_core_projection(i)(a) ...);
        }
    );
};

template<typename F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    F,
    _core_mathematics_Product3<A ...>
> = [] (
    auto & f,
    auto & a
) -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) -> decltype(auto) {
            return f(_core_projection(i)(a) ...);
        }
    );
};

template<typename I, typename A, typename ... B>
inline constexpr auto core_mathematics_map_apply_<
    _core_mathematics_Projection<I>,
    _core_mathematics_Product0<A, B ...>
> = [] (
    auto,
    auto & x
) constexpr -> decltype(auto) {
    if constexpr (I{} == 0)
        return A{};
    else
        return _core_projection(I{} - 1_literal)(x.x);
};

template<typename I, typename A, typename ... B>
inline constexpr auto core_mathematics_map_apply_<
    _core_mathematics_Projection<I>,
    _core_mathematics_Product1<A, B ...>
> = [] (
    auto,
    auto & x
) constexpr -> decltype(auto) {
    if constexpr (I{} == 0)
        return A{};
    else
        return _core_projection(I{} - 1_literal)(x.x);
};

template<typename I, typename A, typename ... B>
inline constexpr auto core_mathematics_map_apply_<
    _core_mathematics_Projection<I>,
    _core_mathematics_Product2<A, B ...>
> = [] (
    auto,
    auto & x
) constexpr -> decltype(auto) {
    if constexpr (I{} == 0)
        return (x.a);
    else
        return _core_projection(I{} - 1_literal)(x.x);
};

template<typename I, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_mathematics_Projection<I>,
    _core_mathematics_Product3<A ...>
> = [] (
    auto,
    auto & x
) constexpr -> decltype(auto) {
    if constexpr (I{} == 0)
        return (x.a);
    else
        return _core_projection(I{} - 1_literal)(x.x);
};

template<typename I, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_tagged_union_Unsafe_cast<I>,
    _core_Default_tagged_union<A ...>
> = [] (
    auto,
    auto & a
) constexpr -> decltype(auto) {
    return _core_untagged_union_Unsafe_cast{I{}}(
        _core_projection(1_literal)(_core_base_object(a))
    );
};

template<typename I, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_tagged_union_Unsafe_cast<I>,
    _core_Simple_tagged_union<A ...>
> = [] (
    auto,
    auto &
) constexpr -> decltype(auto) {
    return _core_projection(I{})(_core_Product<A ...>{});
};

template<typename I, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_untagged_union_Unsafe_cast<I>,
    _core_Untagged_union<A ...>
> = [] (
    auto,
    auto & a
) constexpr -> decltype(auto) {
    if constexpr (I{} == 0)
        return (a.a);
    else
        return _core_untagged_union_Unsafe_cast{I{} - 1_literal}(a.rest);
};

#endif
