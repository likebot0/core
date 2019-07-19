#ifndef _core_ieee_std_1003dot1_current_time
#define _core_ieee_std_1003dot1_current_time ::core_ieee_std_1003dot1_current_time

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_current_time, core_ieee_std_1003dot1_current_time_);

#include <core/ieee/std/1003dot1/Time.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<time.h>)
extern "C" {

#include <time.h>

}
#endif

#if __has_include(<time.h>)
template<typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_current_time_<
    Continuation
> = [] (
    auto & k
) {
    auto a = ::time(nullptr);

    if (a == -1)
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_ieee_std_1003dot1_Time{a});
};
#endif

#endif
