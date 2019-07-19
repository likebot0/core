#ifndef _core_io_print_line
#define _core_io_print_line ::core_io_print_line

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map2(core_io_print_line, core_io_print_line_);

#include <core/Product.type.h>
#include <core/apply.h>
#include <core/array/from.h>
#include <core/base_object.h>
#include <core/io/print.h>

template<typename ... A, typename Continuation>
inline constexpr auto core_io_print_line_<
    _core_Targets<A ...>,
    Continuation
> = [] (
    auto & targets,
    auto & k
) {
    _core_apply(
        [&] (auto && ... a) {
            _core_array_from(
                [&] (auto && f) {
                    _core_io_print(_core_Targets{a ..., f}, k);
                },
                '\n'
            );
        },
        _core_base_object(targets)
    );
};

template<typename ... A, typename B, typename Continuation>
inline constexpr auto core_io_print_line_<
    B,
    _core_Targets<A ...>,
    Continuation
> = [] (
    auto & output,
    auto & targets,
    auto & k
) {
    _core_apply(
        [&] (auto && ... a) {
            _core_io_print(
                output,
                _core_Targets{a ..., '\n'},
                k
            );
        },
        _core_base_object(targets)
    );
};

#endif
