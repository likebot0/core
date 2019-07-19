#ifndef _core_file_handle_deallocate
#define _core_file_handle_deallocate ::core_file_handle_deallocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map2(core_file_handle_deallocate, core_file_handle_deallocate_);

#include <core/Nil.type.h>
#include <core/file/Handle.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<unistd.h>)
template<typename A, typename Continuation>
inline constexpr auto core_file_handle_deallocate_<
    A,
    Continuation
> = [] (
    auto & a,
    auto & k
) {
    if (::close(a))
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else
        k(_core_Nil{}, _core_Nil{});
};
#endif

#endif
