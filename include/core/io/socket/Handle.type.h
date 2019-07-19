#ifndef _core_io_socket_Handle
#define _core_io_socket_Handle ::core_io_socket_Handle

struct core_io_socket_Handle;

#include <core/Product.type.h>

#if __has_include(<sys/socket.h>)
struct core_io_socket_Handle : _core_Product<int> {
    using Base_object = _core_Product<int>;

    using Base_object::Base_object;
};
#endif

#endif
