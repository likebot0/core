#ifndef _core_stack_pop
#define _core_stack_pop ::core_stack_pop

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_stack_pop, core_stack_pop_);

#include <core/Remove_all_qualifiers.type.h>
#include <core/array/base_address.h>
#include <core/array/shrink.h>
#include <core/array/size.h>
#include <core/meta/is_equal_to.h>
#include <core/operator""_literal.h>
#include <core/system/Error.type.h>

template<typename Array, typename Continuation>
inline constexpr auto core_stack_pop_<
    Array,
    Continuation
> = [] (
    auto & f,
    auto & k
) {
    auto e = _core_array_base_address(f)[array_size(f) - 1];

    _core_array_shrink(
        f,
        1_literal,
        [&] (auto && x) {
            if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_system_Error>)
                k(x);
            else
                k(e, x);
        }
    );
};

#endif
