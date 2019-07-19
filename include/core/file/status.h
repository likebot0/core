#ifndef _core_file_status
#define _core_file_status ::core_file_status

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_file_status, core_file_status_);

#include <core/C_string.type.h>
#include <core/ieee/std/1003dot1/file/status.h>

template<typename A, typename Continuation>
inline constexpr auto core_file_status_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & a,
    auto & k
) {
    return _core_ieee_std_1003dot1_file_status(a, k);
};

#endif
