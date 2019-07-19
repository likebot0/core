#ifndef _core_is
#define _core_is ::core_is

template<typename A>
struct core_Is {
    template<typename B>
    inline constexpr auto operator ()(
        B && b
    ) const noexcept -> decltype(auto);
};

template<typename A>
inline constexpr auto core_is = core_Is<A>{};

#include <core/mathematics/map/apply.h>

template<typename A>
template<typename B>
inline constexpr auto core_Is<A>::operator ()(
    B && b
) const noexcept -> decltype(auto) {
    return _core_mathematics_map_apply(* this, static_cast<B &&>(b));
}

#include <core/Array.type.h>
#include <core/Default_tagged_union.type.h>
#include <core/False.type.h>
#include <core/Fmap.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/True.type.h>
#include <core/meta/Set.type.h>
#include <core/meta/Tuple.type.h>
#include <core/meta/contains.h>
#include <core/meta/index.h>
#include <core/tagged_union/tag.h>

template<typename A>
inline constexpr auto core_mathematics_map_apply_<
    core_Is<A>,
    A
> = [] (
    auto &
) constexpr {
    return _core_True{};
};

template<typename A, typename B>
inline constexpr auto core_mathematics_map_apply_<
    core_Is<A>,
    B
> = [] (
    auto &
) constexpr {
    return _core_False{};
};

template<typename A, typename ... B>
inline constexpr auto core_mathematics_map_apply_<
    core_Is<A>,
    _core_Default_tagged_union<B ...>
> = [] (
    auto & b
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_contains<_core_meta_Set<B ...>, A>)
        return _core_tagged_union_tag(b) == _core_meta_index<_core_meta_Tuple<B ...>, A>;
    else
        return _core_Fmap{(_core_meta_Set<B>{}, _core_is<A>) ...}(b);
};

template<typename A, typename ... B>
inline constexpr auto core_mathematics_map_apply_<
    core_Is<A>,
    _core_Simple_tagged_union<B ...>
> = [] (
    auto & b
) constexpr -> decltype(auto) {
    if constexpr (_core_meta_contains<_core_meta_Set<B ...>, A>)
        return _core_tagged_union_tag(b) == _core_meta_index<_core_meta_Tuple<B ...>, A>;
    else
        return _core_Fmap{(_core_meta_Set<B>{}, _core_is<A>) ...}(b);
};

#endif
