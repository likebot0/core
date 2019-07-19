#ifndef _core_ieee_std_1003dot1_memory_allocate
#define _core_ieee_std_1003dot1_memory_allocate ::core_ieee_std_1003dot1_memory_allocate

template<typename A>
struct core_ieee_std_1003dot1_memory_Allocate {
    template<typename ... B>
    inline constexpr auto operator ()(
        B && ... b
    ) const noexcept -> decltype(auto);
};

template<typename A>
inline constexpr auto core_ieee_std_1003dot1_memory_allocate = core_ieee_std_1003dot1_memory_Allocate<A>{};

#include <core/mathematics/map/apply.h>

template<typename A>
template<typename ... B>
inline constexpr auto core_ieee_std_1003dot1_memory_Allocate<A>::operator ()(
    B && ... b
) const noexcept -> decltype(auto) {
    _core_mathematics_map_apply(* this, static_cast<B &&>(b) ...);
}

#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<stdlib.h>)
extern "C" {

#include <stdlib.h>

}
#endif

#if __has_include(<stdlib.h>)
template<typename A, typename N, typename Continuation>
inline constexpr auto core_mathematics_map_apply_<
    core_ieee_std_1003dot1_memory_Allocate<A>,
    N,
    Continuation
> = [] (
    auto,
    auto & n,
    auto & k
) {
    auto x = ::malloc(n);

    if (x == nullptr)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_ieee_std_1003dot1_Memory{static_cast<A *>(x), n});
};
#endif

#endif
