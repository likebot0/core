#ifndef _core_ieee_std_1003dot1_iovec_base_address
#define _core_ieee_std_1003dot1_iovec_base_address ::core_ieee_std_1003dot1_iovec_base_address

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_iovec_base_address, core_ieee_std_1003dot1_iovec_base_address_);

#include <core/ieee/std/1003dot1/Iovec.type.h>

template<>
inline constexpr auto core_ieee_std_1003dot1_iovec_base_address_<
    _core_ieee_std_1003dot1_Iovec
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return (f.iov_base);
};

#endif
