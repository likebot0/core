#ifndef _core_array_deallocate
#define _core_array_deallocate ::core_array_deallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_array_deallocate, core_array_deallocate_);

#include <core/ieee/std/1003dot1/Memory.type.h>
#include <core/memory/deallocate.h>

template<typename A, typename N>
inline constexpr auto core_array_deallocate_<
    _core_ieee_std_1003dot1_Memory<A, N>
> = [] (
    auto & f
) {
    return _core_memory_deallocate(f);
};

#endif
