#ifndef _core_ieee_std_1003dot1_Error
#define _core_ieee_std_1003dot1_Error ::core_ieee_std_1003dot1_Error

struct core_ieee_std_1003dot1_Error;

#include <core/Product.type.h>
#include <core/Remove_all_qualifiers.type.h>

#if __has_include(<errno.h>)
extern "C" {

#include <errno.h>

}
#endif

#if (\
    __has_include(<errno.h>)\
 || __has_include(<cerrno>)\
)
struct core_ieee_std_1003dot1_Error : _core_Product<_core_Remove_all_qualifiers<decltype(errno)>> {
    using Base_object = _core_Product<_core_Remove_all_qualifiers<decltype(errno)>>;

    using Base_object::Base_object;
};
#endif

#endif
