#ifndef _core_mathematics_Projection
#define _core_mathematics_Projection ::core_mathematics_Projection

template<typename I>
struct core_mathematics_Projection;

#include <core/mathematics/Product.type.h>
#include <core/mathematics/map/apply.h>

template<typename I>
struct core_mathematics_Projection : _core_mathematics_Product<I> {
    using Base_object = _core_mathematics_Product<I>;

    using Base_object::Base_object;

    template<typename A>
    inline constexpr auto operator ()(
        A && a
    ) const noexcept -> decltype(auto) {
        return _core_mathematics_map_apply(* this, static_cast<A &&>(a));
    }
};

#endif
