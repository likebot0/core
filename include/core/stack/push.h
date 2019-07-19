#ifndef _core_stack_push
#define _core_stack_push ::core_stack_push

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_stack_push, core_stack_push_);

#include <core/Nil.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/array/base_address.h>
#include <core/array/grow.h>
#include <core/array/size.h>
#include <core/meta/is_equal_to.h>
#include <core/system/Error.type.h>

template<typename Array, typename A, typename Continuation>
inline constexpr auto core_stack_push_<
    Array,
    A,
    Continuation
> = [] (
    auto & f,
    auto & a,
    auto & k
) {
    _core_array_grow(
        f,
        1_literal,
        [&] (auto && x) {
            if constexpr (! _core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_system_Error>)
                _core_array_base_address(f)[_core_array_size(f) - 1] = a;

            k(_core_Nil{}, x);
        }
    );
};

#endif
