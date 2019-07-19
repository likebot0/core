#ifndef _core_array_allocate
#define _core_array_allocate ::core_array_allocate

template<typename A>
struct core_array_Allocate {
    template<typename ... B>
    inline constexpr auto operator ()(
        B && ... b
    ) const noexcept -> decltype(auto);
};

template<typename A>
inline constexpr auto core_array_allocate = core_array_Allocate<A>{};

#include <core/mathematics/map/apply.h>

template<typename A>
template<typename ... B>
inline constexpr auto core_array_Allocate<A>::operator ()(
    B && ... b
) const noexcept -> decltype(auto) {
    return _core_mathematics_map_apply(* this, static_cast<B &&>(b) ...);
}

#include <core/memory/allocate.h>

template<typename A, typename N, typename Continuation>
inline constexpr auto core_mathematics_map_apply_<
    core_array_Allocate<A>,
    N,
    Continuation
> = [] (
    auto,
    auto & n,
    auto & k
) {
    return _core_memory_allocate<A>(n, k);
};

#endif
