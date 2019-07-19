#ifndef _core_process_environment_set
#define _core_process_environment_set ::core_process_environment_set

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_process_environment_set, core_process_environment_set_);

#include <core/C_string.type.h>
#include <core/ieee/std/1003dot1/environment/set.h>

template<typename A, typename B, typename Continuation>
inline constexpr auto core_process_environment_set_<
    _core_C_string<A>,
    _core_C_string<B>,
    Continuation
> = [] (
    auto & i,
    auto & a,
    auto & k
) {
    return _core_ieee_std_1003dot1_environment_set(i, a, k);
};

#endif
