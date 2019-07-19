#ifndef _core_ieee_std_1003dot1_environment_get_pwd
#define _core_ieee_std_1003dot1_environment_get_pwd ::core_ieee_std_1003dot1_environment_get_pwd

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_environment_get_pwd, core_ieee_std_1003dot1_environment_get_pwd_);

#include <core/ieee/std/1003dot1/environment/get.h>
#include <core/operator""_c_string.h>

template<typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_environment_get_pwd_<
    Continuation
> = [] (
    auto & k
) {
    return _core_ieee_std_1003dot1_environment_get(
        u8"PWD"_c_string,
        k
    );
};

#endif
