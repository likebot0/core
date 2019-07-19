#ifndef _core_untagged_union_Unsafe_cast
#define _core_untagged_union_Unsafe_cast ::core_untagged_union_Unsafe_cast

template<typename I>
struct core_untagged_union_Unsafe_cast {
    template<typename A>
    inline constexpr auto operator ()(
        A && a
    ) const noexcept -> decltype(auto);
};

#include <core/mathematics/map/apply.h>

template<typename I>
template<typename A>
inline constexpr auto core_untagged_union_Unsafe_cast<I>::operator ()(
    A && a
) const noexcept -> decltype(auto) {
    return _core_mathematics_map_apply(* this, static_cast<A &&>(a));
}

#endif
