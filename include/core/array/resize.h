#ifndef _core_array_resize
#define _core_array_resize ::core_array_resize

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_array_resize, core_array_resize_);

#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/memory/reallocate.h>

template<typename A, typename N, typename M, typename Continuation>
inline constexpr auto core_array_resize_<
    _core_ieee_std_1003dot1_Memory<A, N>,
    M,
    Continuation
> = [] (
    auto & f,
    auto & m,
    auto & k
) {
    return _core_memory_reallocate(f, m, k);
};

#endif
