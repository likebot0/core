#ifndef _core_ieee_std_1003dot1_file_Status
#define _core_ieee_std_1003dot1_file_Status ::core_ieee_std_1003dot1_file_Status

#if __has_include(<sys/stat.h>)
extern "C" {

#include <sys/stat.h>

}
#endif

#if __has_include(<sys/uio.h>)
using core_ieee_std_1003dot1_file_Status = struct stat;
#else
struct core_ieee_std_1003dot1_file_Status;
#endif

#endif
