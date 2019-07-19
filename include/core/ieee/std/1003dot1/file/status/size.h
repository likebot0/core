#ifndef _core_ieee_std_1003dot1_file_status_size
#define _core_ieee_std_1003dot1_file_status_size ::core_ieee_std_1003dot1_file_status_size

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_file_status_size, core_ieee_std_1003dot1_file_status_size_);

#include <core/ieee/std/1003dot1/file/Status.type.h>

template<>
inline constexpr auto core_ieee_std_1003dot1_file_status_size_<
    _core_ieee_std_1003dot1_file_Status
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return (a.st_size);
};

#endif
