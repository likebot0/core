#ifndef _core_file_handle_allocate
#define _core_file_handle_allocate ::core_file_handle_allocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map2(core_file_handle_allocate, core_file_handle_allocate_);

#include <core/C_string.type.h>
#include <core/file/Handle.type.h>
#include <core/file/Read_only_handle.type.h>
#include <core/file/Read_write_handle.type.h>
#include <core/file/Write_only_handle.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<sys/types.h>)
extern "C" {

#include <sys/types.h>

}
#endif

#if __has_include(<sys/stat.h>)
extern "C" {

#include <sys/stat.h>

}
#endif

#if __has_include(<fcntl.h>)
extern "C" {

#include <fcntl.h>

}
#endif

#if __has_include(<sys/stat.h>)
template<typename A, typename Continuation>
inline constexpr auto core_file_handle_allocate_<
    _core_C_string<A>,
    Continuation
> = [] (
    auto & a,
    auto & k
) {
    auto x = ::open(a, O_CLOEXEC | O_PATH);

    if (x == -1)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_file_Handle{x});
};
#endif

#endif
