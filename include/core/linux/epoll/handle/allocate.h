#ifndef _core_linux_epoll_handle_allocate
#define _core_linux_epoll_handle_allocate ::core_linux_epoll_handle_allocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_linux_epoll_handle_allocate, core_linux_epoll_handle_allocate_);

#include <core/ieee/std/1003dot1/last_error.h>
#include <core/linux/epoll/Handle.type.h>

#if __has_include(<sys/epoll.h>)
extern "C" {

#include <sys/epoll.h>

}
#endif

#if __has_include(<sys/epoll.h>)
template<typename Continuation>
inline constexpr auto core_linux_epoll_handle_allocate_<
    Continuation
> = [] (
    auto & k
) {
    auto b = ::epoll_create1(EPOLL_CLOEXEC);

    if (b == -1)
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_linux_epoll_Handle{b});
};
#endif

#endif
