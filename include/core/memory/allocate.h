#ifndef _core_memory_allocate
#define _core_memory_allocate ::core_memory_allocate

template<typename A>
struct core_memory_Allocate {
    template<typename ... B>
    inline constexpr auto operator ()(
        B && ... b
    ) const noexcept -> decltype(auto);
};

template<typename A>
inline constexpr auto core_memory_allocate = core_memory_Allocate<A>{};

#include <core/mathematics/map/apply.h>

template<typename A>
template<typename ... B>
inline constexpr auto core_memory_Allocate<A>::operator ()(
    B && ... b
) const noexcept -> decltype(auto) {
    return _core_mathematics_map_apply(* this, static_cast<B &&>(b) ...);
}

#include <core/ieee/std/1003dot1/memory/allocate.h>

template<typename A, typename N, typename Continuation>
inline constexpr auto core_mathematics_map_apply_<
    core_memory_Allocate<A>,
    N,
    Continuation
> = [] (
    auto,
    auto & n,
    auto & k
) {
    return _core_ieee_std_1003dot1_memory_allocate<A>(n, k);
};

#endif
