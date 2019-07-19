#ifndef _core_mathematics_id
#define _core_mathematics_id ::core_mathematics_id

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_id, core_mathematics_id_);

template<typename A>
inline constexpr auto core_mathematics_id_<
    A
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return (a);
};

#endif
