#ifndef _core_ieee_std_1003dot1_iovec_from
#define _core_ieee_std_1003dot1_iovec_from ::core_ieee_std_1003dot1_iovec_from

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_ieee_std_1003dot1_iovec_from, core_ieee_std_1003dot1_iovec_from_);

#include <core/Array.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Pointer.type.h>
#include <core/Size.type.h>
#include <core/array/base_address.h>
#include <core/array/size.h>
#include <core/ieee/std/1003dot1/Iovec.type.h>
#include <core/ieee/std/1003dot1/iovec/base_address.h>
#include <core/ieee/std/1003dot1/iovec/size.h>
#include <core/memory/address.h>

#if __has_include(<sys/uio.h>)
extern "C" {

#include <sys/uio.h>

}
#endif

template<typename Continuation, typename ... X>
inline constexpr auto core_ieee_std_1003dot1_iovec_from_<
    Continuation,
    X ...
> = [] (
    auto & k,
    auto & ... x
) {
    k(
        _core_ieee_std_1003dot1_Iovec {
            const_cast<_core_Pointer<void>>(static_cast<_core_Pointer<const void>>(_core_array_base_address(x))),
            _core_array_size(x)
        } ...
    );
};

#endif
