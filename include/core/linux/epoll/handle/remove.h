#ifndef _core_linux_epoll_handle_remove
#define _core_linux_epoll_handle_remove ::core_linux_epoll_handle_remove

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_linux_epoll_handle_remove, core_linux_epoll_handle_remove_);

#include <core/Nil.type.h>
#include <core/ieee/std/1003dot1/last_error.h>
#include <core/linux/epoll/Handle.type.h>

#if __has_include(<sys/epoll.h>)
extern "C" {

#include <sys/epoll.h>

}
#endif

#if __has_include(<sys/epoll.h>)
template<typename Continuation>
inline constexpr auto core_linux_epoll_handle_remove_<
    _core_linux_epoll_Handle,
    int,
    Continuation
> = [] (
    auto & a,
    auto & b,
    auto & k
) {
    if (::epoll_ctl(a, EPOLL_CTL_DEL, b, nullptr))
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#endif
