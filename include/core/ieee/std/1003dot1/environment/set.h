#ifndef _core_ieee_std_1003dot1_environment_set
#define _core_ieee_std_1003dot1_environment_set ::core_ieee_std_1003dot1_environment_set

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_environment_set, core_ieee_std_1003dot1_environment_set_);

#include <core/C_string.type.h>
#include <core/Nil.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<stdlib.h>)
extern "C" {

#include <stdlib.h>

}
#endif

#if __has_include(<stdlib.h>)
template<typename A, typename B, typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_environment_set_<
    _core_C_string<A>,
    _core_C_string<B>,
    Continuation
> = [] (
    auto & i,
    auto & a,
    auto & k
) {
    if (::setenv(i, a, 1))
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#endif
