#ifndef _core_ieee_std_1003dot1_Time
#define _core_ieee_std_1003dot1_Time ::core_ieee_std_1003dot1_Time

struct core_ieee_std_1003dot1_Time;

#include <core/Product.type.h>

#if __has_include(<time.h>)
extern "C" {

#include <time.h>

}
#endif

#if __has_include(<time.h>)
struct core_ieee_std_1003dot1_Time : _core_Product<::time_t> {
    using Base_object = _core_Product<::time_t>;

    using Base_object::Base_object;
};
#endif

#endif
