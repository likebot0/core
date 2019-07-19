#ifndef _core_ieee_std_1003dot1_last_error
#define _core_ieee_std_1003dot1_last_error ::core_ieee_std_1003dot1_last_error

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_last_error, core_ieee_std_1003dot1_last_error_);

#include <core/ieee/std/1003dot1/Error.type.h>

#if __has_include(<errno.h>)
extern "C" {

#include <errno.h>

}
#elif __has_include(<cerrno>)
#include <cerrno>
#endif

#if (\
    __has_include(<errno.h>)\
 || __has_include(<cerrno>)\
)
template<typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_last_error_<
    Continuation
> = [] (
    auto & k
) {
    k(_core_Nil{}, reinterpret_cast<_core_ieee_std_1003dot1_Error &>(errno));
};
#endif

#endif
