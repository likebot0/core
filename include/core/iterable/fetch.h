#ifndef _core_iterable_fetch
#define _core_iterable_fetch ::core_iterable_fetch

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_iterable_fetch, core_iterable_fetch_);

#include <core/Array.type.h>
#include <core/Hash_table.type.h>
#include <core/Nil.type.h>
#include <core/Null_terminated_string.type.h>
#include <core/Product.type.h>
#include <core/Quadlet.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/Utf8.type.h>
#include <core/array/base_address.h>
#include <core/base_object.h>
#include <core/is_equal_to.h>
#include <core/hash_table/buckets.h>
#include <core/length.h>
#include <core/meet.h>
#include <core/meta/is_equal_to.h>
#include <core/operator""_literal.h>
#include <core/projection.h>
#include <core/tagged_union/Unsafe_cast.h>
#include <core/unicode/ScalarValue.type.h>

template<typename A, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    A *,
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    k(f[i ++]);
};

template<typename A, auto n, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    A [n],
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    if (i == _core_length(f))
        k(_core_Nil{});
    else
        k(f[i ++]);
};

template<typename ... A, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    _core_Array<A ...>,
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    if (i == _core_length(f))
        k(_core_Nil{});
    else
        k(_core_array_base_address(f)[i ++]);
};

template<typename A, typename B, typename HashFunction, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    _core_Hash_table<A, B, HashFunction>,
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    if (_core_projection(0_literal)(i) == _core_length(f))
        k(_core_Nil{});
    else {
        while (_core_is_equal_to(_core_array_base_address(_core_hash_table_buckets(f))[_core_projection(1_literal)(i)], _core_Product<>{}))
            _core_projection(1_literal)(i) = {_core_projection(1_literal)(i) + 1};

        decltype(auto) x = _core_tagged_union_Unsafe_cast{1_literal}(
            _core_array_base_address(_core_hash_table_buckets(f))[_core_projection(1_literal)(i)]
        );

        i = I{
            _core_projection(0_literal)(i) + 1,
            _core_projection(1_literal)(i) + 1
        };

        k(x);
    }
};

template<typename A, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    _core_Null_terminated_string<A>,
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    _core_iterable_fetch(
        _core_base_object(f),
        i,
        [&] (auto && x) {
            if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_Nil>)
                k(x);
            else {
                if (x == '\0')
                    k(_core_Nil{});
                else
                    k(x);
            }
        }
    );
};

template<typename G, typename I, typename Continuation>
inline constexpr auto core_iterable_fetch_<
    _core_Utf8<G>,
    I,
    Continuation
> = [] (
    auto & f,
    auto & i,
    auto & k
) constexpr {
    decltype(auto) g = _core_base_object(f);

    _core_iterable_fetch(
        g,
        i,
        [&] (auto && x) {
            if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_Nil>)
                k(x);
            else
                k(_core_unicode_ScalarValue{
                    x < 0x80 ?
                        _core_Quadlet{x}
                  : x < 0xE0 ?
                        (_core_Quadlet{_core_meet(x, 0b11111)} << 6)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)})
                  : x < 0xF0 ?
                        (_core_Quadlet{_core_meet(x, 0b1111)} << 12)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)} << 6)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)})
                  :
                        (_core_Quadlet{_core_meet(x, 0b111)} << 18)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)} << 12)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)} << 6)
                  bitor (_core_Quadlet{_core_meet(_core_iterable_fetch(g, i), 0b111111)})
                });
        }
    );
};

#endif
