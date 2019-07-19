#ifndef _core_memory_address_dereference
#define _core_memory_address_dereference ::core_memory_address_dereference

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_memory_address_dereference, core_memory_address_dereference_);

#include <core/Pointer.type.h>

template<typename A>
inline constexpr auto core_memory_address_dereference_<
    _core_Pointer<A>
> = [] (
    auto & x
) constexpr -> A & {
    return * x;
};

#endif
