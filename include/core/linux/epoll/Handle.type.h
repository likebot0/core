#ifndef _core_linux_epoll_Handle
#define _core_linux_epoll_Handle ::core_linux_epoll_Handle

struct core_linux_epoll_Handle;

#include <core/Product.type.h>

struct core_linux_epoll_Handle : _core_Product<int> {
    using Base_object = _core_Product<int>;

    using Base_object::Base_object;
};

#endif
