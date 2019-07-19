#ifndef _core_projection
#define _core_projection ::core_projection

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_projection, core_projection_);

#include <core/mathematics/Projection.type.h>

template<typename I>
inline constexpr auto core_projection_<
    I
> = [] (
    auto & i
) -> decltype(auto) {
    return _core_mathematics_Projection<I>{i};
};

#endif
