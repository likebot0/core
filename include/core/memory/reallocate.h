#ifndef _core_memory_reallocate
#define _core_memory_reallocate ::core_memory_reallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_memory_reallocate, core_memory_reallocate_);

#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/memory/reallocate.h>

template<typename A, typename N, typename M, typename Continuation>
inline constexpr auto core_memory_reallocate_<
    _core_ieee_std_1003dot1_Memory<A, N>,
    M,
    Continuation
> = [] (
    auto & x,
    auto & m,
    auto & k
) {
    return _core_ieee_std_1003dot1_memory_reallocate(x, m, k);
};

#endif
