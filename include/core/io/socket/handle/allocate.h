#ifndef _core_io_socket_handle_allocate
#define _core_io_socket_handle_allocate ::core_io_socket_handle_allocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_io_socket_handle_allocate, core_io_socket_handle_allocate_);

#include <core/ieee/std/1003dot1/last_error.h>
#include <core/io/socket/Handle.type.h>
#include <core/io/socket/protocols/Ipv4.type.h>
#include <core/io/socket/protocols/Ipv6.type.h>
#include <core/io/socket/protocols/Local.type.h>
#include <core/io/socket/protocols/Packet.type.h>
#include <core/io/socket/types/Datagram.type.h>
#include <core/io/socket/types/Raw.type.h>
#include <core/io/socket/types/Stream.type.h>

#if __has_include(<sys/socket.h>)
extern "C" {

#include <sys/socket.h>

}
#endif

/*
#if defined(SOCK_DGRAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Datagram<
            _core_io_socket_protocols::Ipv4<core_io_socket::Handle>
        >
    >
> = [] (
    auto &
) -> Sum<system::Error, core_io_socket_types::Datagram<core_io_socket_protocols::Ipv4<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv4,
        _core_io_socket_types::Datagram;

    auto a = ::socket(AF_INET, SOCK_DGRAM, 0);

    if (a == -1)
        return thread_last_error();
    else
        return Datagram{Ipv4{Handle{a}}};
};
#endif

#if defined(AF_INET)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Raw<
            _core_io_socket_protocols::Ipv4<core_io_socket::Handle>
        >
    >,
    int
> = [] (
    auto & p
) -> Sum<system::Error, core_io_socket_types::Raw<core_io_socket_protocols::Ipv4<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv4,
        _core_io_socket_types::Raw;

    auto a = ::socket(AF_INET, SOCK_RAW, p);

    if (a == -1)
        return thread_last_error();
    else
        return Raw{Ipv4{Handle{a}}};
};
#endif

#if defined(SOCK_STREAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Stream<
            _core_io_socket_protocols::Ipv4<core_io_socket::Handle>
        >
    >
> = [] (
    auto &
) -> Sum<system::Error, core_io_socket_types::Stream<core_io_socket_protocols::Ipv4<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv4,
        _core_io_socket_types::Stream;

    auto a = ::socket(AF_INET, SOCK_STREAM, 0);

    if (a == -1)
        return thread_last_error();
    else
        return Stream{Ipv4{Handle{a}}};
};
#endif

#if defined(SOCK_DGRAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Datagram<
            _core_io_socket_protocols::Ipv6<core_io_socket::Handle>
        >
    >,
    int
> = [] (
    auto & p
) -> Sum<system::Error, core_io_socket_types::Datagram<core_io_socket_protocols::Ipv6<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv6,
        _core_io_socket_types::Datagram;

    auto a = ::socket(AF_INET6, SOCK_DGRAM, p);

    if (a == -1)
        return thread_last_error();
    else
        return Datagram{Ipv6{Handle{a}}};
};
#endif

#if defined(SOCK_RAW)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Raw<
            _core_io_socket_protocols::Ipv6<core_io_socket::Handle>
        >
    >,
    int
> = [] (
    auto & p
) -> Sum<system::Error, core_io_socket_types::Raw<core_io_socket_protocols::Ipv6<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv6,
        _core_io_socket_types::Raw;

    auto a = ::socket(AF_INET6, SOCK_RAW, p);

    if (a == -1)
        return thread_last_error();
    else
        return Raw{Ipv6{Handle{a}}};
};
#endif

#if defined(SOCK_STREAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Stream<
            _core_io_socket_protocols::Ipv6<core_io_socket::Handle>
        >
    >
> = [] (
    auto &
) -> Sum<system::Error, core_io_socket_types::Stream<core_io_socket_protocols::Ipv6<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Ipv6,
        _core_io_socket_types::Stream;

    auto a = ::socket(AF_INET6, SOCK_STREAM, 0);

    if (a == -1)
        return thread_last_error();
    else
        return Stream{Ipv6{Handle{a}}};
};
#endif

#if defined(SOCK_DGRAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Datagram<
            _core_io_socket_protocols::Local<core_io_socket::Handle>
        >
    >
> = [] (
    auto &
) -> Sum<system::Error, core_io_socket_types::Datagram<core_io_socket_protocols::Local<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Local,
        _core_io_socket_types::Datagram;

    auto a = ::socket(AF_LOCAL, SOCK_DGRAM, 0);

    if (a == -1)
        return thread_last_error();
    else
        return Datagram{Local{Handle{a}}};
};
#endif

#if defined(SOCK_STREAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Stream<
            _core_io_socket_protocols::Local<core_io_socket::Handle>
        >
    >
> = [] (
    auto &
) -> Sum<system::Error, core_io_socket_types::Stream<core_io_socket_protocols::Local<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Local,
        _core_io_socket_types::Stream;

    auto a = ::socket(AF_LOCAL, SOCK_STREAM, 0);

    if (a == -1)
        return thread_last_error();
    else
        return Stream{Local{Handle{a}}};
};
#endif

#if defined(SOCK_DGRAM)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Datagram<
            _core_io_socket_protocols::Packet<core_io_socket::Handle>
        >
    >,
    int
> = [] (
    auto & p
) -> Sum<system::Error, core_io_socket_types::Datagram<core_io_socket_protocols::Packet<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Packet,
        _core_io_socket_types::Datagram;

    auto a = ::socket(AF_PACKET, SOCK_DGRAM, p);

    if (a == -1)
        return thread_last_error();
    else
        return Datagram{Packet{Handle{a}}};
};
#endif

#if defined(SOCK_RAW)
template<>
inline constexpr auto implementation<
    _core_io_socket_handle::allocate<
        _core_io_socket_types::Raw<
            _core_io_socket_protocols::Packet<core_io_socket::Handle>
        >
    >,
    int
> = [] (
    auto & p
) -> Sum<system::Error, core_io_socket_types::Raw<core_io_socket_protocols::Packet<core_io_socket::Handle>>> {
    using
        _core_io_socket::Handle,
        _core_io_socket_protocols::Packet,
        _core_io_socket_types::Raw;

    auto a = ::socket(AF_PACKET, SOCK_RAW, p);

    if (a == -1)
        return thread_last_error();
    else
        return Raw{Packet{Handle{a}}};
};
#endif
*/

#endif
