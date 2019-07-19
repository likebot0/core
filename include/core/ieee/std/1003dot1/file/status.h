#ifndef _core_ieee_std_1003dot1_file_status
#define _core_ieee_std_1003dot1_file_status ::core_ieee_std_1003dot1_file_status

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_file_status, core_ieee_std_1003dot1_file_status_);

#include <core/C_string.type.h>
#include <core/ieee/std/1003dot1/file/Status.type.h>
#include <core/ieee/std/1003dot1/last_error.h>
#include <core/memory/address.h>

#if __has_include(<sys/types.h>)
extern "C" {

#include <sys/types.h>

}
#endif

#if __has_include(<sys/stat.h>)
extern "C" {

#include <sys/stat.h>

}
#endif

#if __has_include(<fcntl.h>)
extern "C" {

#include <fcntl.h>

}
#endif

#if __has_include(<sys/stat.h>)
template<typename A, typename Continuation>
inline constexpr auto core_ieee_std_1003dot1_file_status_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & a,
    auto & k
) {
    _core_ieee_std_1003dot1_file_Status b;

    if (::stat(a, _core_memory_address(b)))
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(b);
};
#endif

#endif
