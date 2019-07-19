#ifndef _core_tagged_union_Unsafe_cast
#define _core_tagged_union_Unsafe_cast ::core_tagged_union_Unsafe_cast

template<typename I>
struct core_tagged_union_Unsafe_cast;

template<typename I>
core_tagged_union_Unsafe_cast(I) -> core_tagged_union_Unsafe_cast<I>;

#include <core/Product.type.h>
#include <core/mathematics/map/apply.h>

template<typename I>
struct core_tagged_union_Unsafe_cast : _core_Product<I> {
    using Base_object = _core_Product<I>;

    using Base_object::Base_object;

    template<typename A>
    inline constexpr auto operator ()(
        A && a
    ) const noexcept -> decltype(auto) {
        return _core_mathematics_map_apply(* this, static_cast<A &&>(a));
    }
};

#endif
