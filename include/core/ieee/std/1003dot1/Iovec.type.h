#ifndef _core_ieee_std_1003dot1_Iovec
#define _core_ieee_std_1003dot1_Iovec ::core_ieee_std_1003dot1_Iovec

#if __has_include(<sys/uio.h>)
extern "C" {

#include <sys/uio.h>

}
#endif

#if __has_include(<sys/uio.h>)
using core_ieee_std_1003dot1_Iovec = struct iovec;
#else
struct core_ieee_std_1003dot1_Iovec;
#endif

#endif
