#ifndef _core_ieee_std_1003dot1_memory_reallocate
#define _core_ieee_std_1003dot1_memory_reallocate ::core_ieee_std_1003dot1_memory_reallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_memory_reallocate, core_ieee_std_1003dot1_memory_reallocate_);

#include <core/Pointer.type.h>
#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<stdlib.h>)
extern "C" {

#include <stdlib.h>

}
#endif

#if __has_include(<stdlib.h>)
template<typename A, typename N, typename M, typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_memory_reallocate_<
    _core_ieee_std_1003dot1_Memory<A, N>,
    M,
    Continuation
> = [] (
    auto & f,
    auto & m,
    auto & k
) {
    auto x = ::realloc(_core_array_base_address(f), sizeof(A) * m);

    if (x == nullptr)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_ieee_std_1003dot1_Memory{static_cast<_core_Pointer<A>>(x), m});
};
#endif

#endif
