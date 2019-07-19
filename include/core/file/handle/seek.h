#ifndef _core_file_handle_seek
#define _core_file_handle_seek ::core_file_handle_seek

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_file_handle_seek, core_file_handle_seek_);

#include <core/Nil.type.h>
#include <core/file/Handle.type.h>
#include <core/file/handle/seek_origins/Begin.type.h>
#include <core/file/handle/seek_origins/Current.type.h>
#include <core/file/handle/seek_origins/End.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<sys/types.h>)
extern "C" {

#include <sys/types.h>

}
#endif

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<unistd.h>)
template<typename Continuation>
inline constexpr auto core_file_handle_seek_<
    _core_file_Handle,
    _core_file_handle_seek_origins_Begin,
    off_t,
    Continuation
> = [] (
    auto & a,
    auto,
    auto & n,
    auto & k
) {
    if (::lseek(a, n, SEEK_SET) == -1)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#if __has_include(<unistd.h>)
template<typename Continuation>
inline constexpr auto core_file_handle_seek_<
    _core_file_Handle,
    _core_file_handle_seek_origins_Current,
    off_t,
    Continuation
> = [] (
    auto & a,
    auto,
    auto & n,
    auto & k
) {
    if (::lseek(a, n, SEEK_CUR) == -1)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#if __has_include(<unistd.h>)
template<typename Continuation>
inline constexpr auto core_file_handle_seek_<
    _core_file_Handle,
    _core_file_handle_seek_origins_End,
    off_t,
    Continuation
> = [] (
    auto & a,
    auto,
    auto & n,
    auto & k
) {
    if (::lseek(a, n, SEEK_END) == -1)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#endif
