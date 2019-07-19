#ifndef _core_array_shrink
#define _core_array_shrink ::core_array_shrink

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_array_shrink, core_array_shrink_);

#include <core/array/resize.h>
#include <core/array/size.h>

template<typename Array, typename N, typename Continuation>
inline constexpr auto core_array_shrink_<
    Array,
    N,
    Continuation
> = [] (
    auto & f,
    auto & n,
    auto & k
) {
    return _core_array_resize(f, _core_array_size(f) - n, k);
};

#endif
