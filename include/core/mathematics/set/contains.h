#ifndef _core_mathematics_set_contains
#define _core_mathematics_set_contains ::core_mathematics_set_contains

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_mathematics_set_contains, core_mathematics_set_contains_);

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/Size.type.h>
#include <core/preprocessor/end.h>
#include <core/preprocessor/for_each.h>

template<typename A, _core_Size n, typename Continuation>
inline constexpr auto core_mathematics_set_contains_<
    A [n],
    A,
    Continuation
> = [] (
    auto & f,
    auto & x,
    auto & k
) constexpr {
    _core_preprocessor_for_each(y, f)
    if (y == x)
        k(_core_True{});
    _core_preprocessor_end

    k(_core_False{});
};

#endif
