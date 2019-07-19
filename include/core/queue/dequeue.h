#ifndef _core_queue_dequeue
#define _core_queue_dequeue ::core_queue_dequeue

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_queue_dequeue, core_queue_dequeue_);

#include <core/Remove_all_qualifiers.type.h>
#include <core/array/base_address.h>
#include <core/array/size.h>
#include <core/array/shrink.h>
#include <core/meta/is_equal_to.h>
#include <core/system/Error.type.h>

template<typename Array, typename Continuation>
inline constexpr auto core_queue_dequeue_<
    Array,
    Continuation
> = [] (
    auto & f,
    auto & k
) {
    auto e = _core_array_base_address(f)[0];

    for (auto i = _core_Size{0}; i != _core_array_size(f) - 1; ++i)
        _core_array_base_address(f)[i] = _core_array_base_address(f)[i + 1];

    _core_array_shrink(
        f,
        1,
        [&] (auto && x) {
            if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_system_Error>)
                k(x);
            else
                k(e);
        }
    );
};

#endif
