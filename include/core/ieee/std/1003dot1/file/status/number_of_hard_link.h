#ifndef _core_ieee_std_1003dot1_file_status_number_of_hard_link
#define _core_ieee_std_1003dot1_file_status_number_of_hard_link ::core_ieee_std_1003dot1_file_status_number_of_hard_link

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_file_status_number_of_hard_link, core_ieee_std_1003dot1_file_status_number_of_hard_link_);

#include <core/ieee/std/1003dot1/file/Status.type.h>

template<>
inline constexpr auto core_ieee_std_1003dot1_file_status_number_of_hard_link_<
    _core_ieee_std_1003dot1_file_Status
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return (a.st_nlink);
};

#endif
