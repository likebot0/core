#ifndef _core_ieee_std_1003dot1_environment_get
#define _core_ieee_std_1003dot1_environment_get ::core_ieee_std_1003dot1_environment_get

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_environment_get, core_ieee_std_1003dot1_environment_get_);

#include <core/C_string.type.h>
#include <core/Product.type.h>

#if __has_include(<stdlib.h>)
extern "C" {

#include <stdlib.h>

}
#endif

#if __has_include(<stdlib.h>)
template<typename A, typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_environment_get_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & i,
    auto & k
) {
    auto x = ::getenv(i);

    if (x == nullptr)
        k(_core_Product<>{});
    else
        k(_core_C_string{x});
};
#endif

#endif
