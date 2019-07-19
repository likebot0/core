#ifndef _core_memory_address
#define _core_memory_address ::core_memory_address

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_memory_address, core_memory_address_);

template<typename A>
inline constexpr auto core_memory_address_<
    A
> = [] (
    auto & a
) constexpr {
    return & a;
};

#endif
