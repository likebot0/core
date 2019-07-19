#ifndef _core_process_environment_get
#define _core_process_environment_get ::core_process_environment_get

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_process_environment_get, core_process_environment_get_);

#include <core/C_string.type.h>
#include <core/ieee/std/1003dot1/environment/get.h>

template<typename A, typename Continuation>
inline constexpr auto core_process_environment_get_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & i,
    auto & k
) {
    return _core_ieee_std_1003dot1_environment_get(i, k);
};

#endif
