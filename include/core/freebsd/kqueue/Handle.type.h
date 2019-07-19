#ifndef _core_freebsd_kqueue_Handle
#define _core_freebsd_kqueue_Handle ::core_freebsd_kqueue_Handle

struct core_freebsd_kqueue_Handle;

#include <core/Product.type.h>

struct core_freebsd_kqueue_Handle : _core_Product<int> {
    using Base_object = _core_Product<int>;

    using Base_object::Base_object;
};

#endif
