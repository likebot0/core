#ifndef _core_ieee_std_1003dot1_memory_deallocate
#define _core_ieee_std_1003dot1_memory_deallocate ::core_ieee_std_1003dot1_memory_deallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_memory_deallocate, core_ieee_std_1003dot1_memory_deallocate_);

#include <core/array/base_address.h>
#include <core/ieee/std/1003dot1/Memory.type.h>

#if __has_include(<stdlib.h>)
extern "C" {

#include <stdlib.h>

}
#endif

#if __has_include(<stdlib.h>)
template<typename A, typename N>
inline constexpr auto core_ieee_std_1003dot1_memory_deallocate_<
    _core_ieee_std_1003dot1_Memory<A, N>
> = [] (
    auto & x
) {
    return ::free(_core_array_base_address(x), _core_Nil{});
};
#endif

#endif
