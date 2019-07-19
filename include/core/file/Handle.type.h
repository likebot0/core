#ifndef _core_file_Handle
#define _core_file_Handle ::core_file_Handle

struct core_file_Handle;

#include <core/Product.type.h>

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<unistd.h>)
struct core_file_Handle : _core_Product<int> {
    using Base_object = _core_Product<int>;

    using Base_object::Base_object;
};
#endif

#endif
