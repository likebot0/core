#ifndef _core_file_handle_read_data
#define _core_file_handle_read_data ::core_file_handle_read_data

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map2(core_file_handle_read_data, core_file_handle_read_data_);

#include <core/LessThanSignedSizeMax.type.h>
#include <core/Nil.type.h>
#include <core/Size.type.h>
#include <core/array/base_address.h>
#include <core/array/size.h>
#include <core/file/Read_only_handle.type.h>
#include <core/file/Read_write_handle.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<unistd.h>)
template<typename Array, typename Continuation>
inline constexpr auto core_file_handle_read_data_<
    _core_file_Read_only_handle,
    Array,
    Continuation
> = [] (
    auto & handle,
    auto & buffer,
    auto & k
) {
    auto n = ::read(handle, _core_array_base_address(buffer), _core_array_size(buffer));

    if (n == -1)
        _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
            k(x, _core_Nil{});
        });
    else if (n == 0)
        k(_core_Nil{}, _core_Nil{});
    else
        k(_core_Nil{}, n);
};
#endif

#endif
