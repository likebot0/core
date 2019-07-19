#ifndef _core_linux_epoll_handle_add
#define _core_linux_epoll_handle_add ::core_linux_epoll_handle_add

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_linux_epoll_handle_add, core_linux_epoll_handle_add_);

#include <core/Nil.type.h>
#include <core/ieee/std/1003dot1/last_error.h>
#include <core/linux/epoll/Handle.type.h>
#include <core/memory/address.h>

#if __has_include(<sys/epoll.h>)
extern "C" {

#include <sys/epoll.h>

}
#endif

#if __has_include(<sys/epoll.h>)
template<typename Continuation>
inline constexpr auto core_linux_epoll_handle_add_<
    _core_linux_epoll_Handle,
    int,
    struct epoll_event,
    Continuation
> = [] (
    auto & a,
    auto & b,
    auto & c,
    auto & k
) {
    if (::epoll_ctl(a, EPOLL_CTL_ADD, b, _core_memory_address(c)))
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#endif
