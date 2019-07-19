#ifndef _core_memory_deallocate
#define _core_memory_deallocate ::core_memory_deallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_memory_deallocate, core_memory_deallocate_);

#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/ieee/std/1003dot1/memory/deallocate.h>

template<typename A, typename N>
inline constexpr auto core_memory_deallocate_<
    _core_ieee_std_1003dot1_Memory<A, N>
> = [] (
    auto & x
) {
    return _core_ieee_std_1003dot1_memory_deallocate(x);
};

#endif
