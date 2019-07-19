#ifndef _core_process_environment_unset
#define _core_process_environment_unset ::core_process_environment_unset

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_process_environment_unset, core_process_environment_unset_);

#include <core/C_string.type.h>
#include <core/ieee/std/1003dot1/environment/unset.h>

template<typename A, typename Continuation>
inline constexpr auto core_process_environment_unset_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & i,
    auto & k
) {
    return _core_ieee_std_1003dot1_environment_unset(i, k);
};

#endif
