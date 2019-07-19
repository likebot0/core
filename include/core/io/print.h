#ifndef _core_io_print
#define _core_io_print ::core_io_print

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map2(core_io_print, core_io_print_);

#include <core/Product.type.h>
#include <core/Utf8.type.h>
#include <core/file/handle/write.h>
#include <core/process/output_stream.h>

template<typename ... A, typename Continuation>
inline constexpr auto core_io_print_<
    _core_Targets<A ...>,
    Continuation
> = [] (
    auto & targets,
    auto & k
) {
    _core_process_output_stream([&] (auto && x) {
        _core_io_print(
            x,
            targets,
            k
        );
    });
};

template<typename ... A, typename B, typename Continuation>
inline constexpr auto core_io_print_<
    B,
    _core_Targets<A ...>,
    Continuation
> = [] (
    auto & output,
    auto & targets,
    auto & k
) {
    _core_file_handle_write(
        output,
        targets,
        k
    );
};

#endif
