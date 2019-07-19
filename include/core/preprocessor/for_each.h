#ifndef _core_preprocessor_for_each
#define _core_preprocessor_for_each(l, ...) \
    {\
        auto && _core_preprocessor_for_each_a = __VA_ARGS__;\
        \
        decltype(auto) _core_preprocessor_for_each_b = _core_iterable_iterator(\
            _core_preprocessor_for_each_a\
        );\
        \
        auto _core_preprocessor_for_each_c = true;\
        \
        while (_core_preprocessor_for_each_c) {\
            _core_iterable_fetch(\
                _core_preprocessor_for_each_a,\
                _core_preprocessor_for_each_b,\
                [&] (auto && l) {\
                    if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(l)>, _core_Nil>) {\
                        _core_preprocessor_for_each_c = false;\
                    }\
                    else {\

#include <core/Nil.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/iterable/fetch.h>
#include <core/iterable/iterator.h>
#include <core/meta/is_equal_to.h>

#endif
