#ifndef _core_hash_table_insert
#define _core_hash_table_insert ::core_hash_table_insert

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_hash_table_insert, core_hash_table_insert_);

#include <core/Hash_table.type.h>
#include <core/Maybe.type.h>
#include <core/Product.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/array/allocate.h>
#include <core/array/base_address.h>
#include <core/array/size.h>
#include <core/hash_table/buckets.h>
#include <core/hash_table/hash_function.h>
#include <core/hash_table/max_size.h>
#include <core/hash_table/size.h>
#include <core/preprocessor/end.h>
#include <core/preprocessor/for_each.h>
#include <core/projection.h>
#include <core/meta/is_equal_to.h>
#include <core/operator""_literal.h>
#include <core/system/Error.type.h>
#include <core/tagged_union/Unsafe_cast.h>

template<typename ... X, typename A, typename B, typename Continuation>
inline constexpr auto core_hash_table_insert_<
    _core_Hash_table<X ...>,
    A,
    B,
    Continuation
> = [] (
    auto & f,
    auto & a,
    auto & b,
    auto & k
) {
    using N = _core_Remove_all_qualifiers<decltype(_core_hash_table_size(f))>;

    decltype(auto) hash = _core_hash_table_hash_function(f);

    auto required_size = (_core_hash_table_size(f) << 1) + 1;

    auto buckets_size = _core_array_size (_core_hash_table_buckets (f));

    if (
        required_size > buckets_size
     && required_size <= _core_hash_table_max_size(f)
    ) {
        auto n = N{buckets_size > 0 ? buckets_size : 1};

        while (n < required_size)
            n = {n << 1};

        _core_array_allocate<_core_Maybe<_core_Product<A, B>>>(
            n,
            [&] (auto && x) {
                if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(x)>, _core_system_Error>)
                    k(x);
                else {
                    _core_preprocessor_for_each(e, x)
                        e = _core_Product<>{};
                    _core_preprocessor_end

                    _core_preprocessor_for_each(e, _core_hash_table_buckets(f))
                    if (_core_tagged_union_tag(e) == 1) {
                        decltype(auto) ab = _core_tagged_union_Unsafe_cast{1_literal}(e);

                        auto i = N{hash(_core_projection(0_literal)(ab)) & (n - 1)};

                        while (_core_tagged_union_tag(_core_array_base_address(x)[i]) == 1)
                            i = {(i + 1) & (n - 1)};

                        _core_array_base_address(x)[i] = e;
                    }
                    _core_preprocessor_end

                    auto i = N{hash(a) & (_core_array_size(x) - 1)};

                    while (_core_tagged_union_tag(_core_array_base_address(x)[i]) == 1)
                    if (_core_projection(0_literal)(_core_tagged_union_Unsafe_cast{1_literal}(_core_array_base_address(x)[i])) == a) {
                        _core_projection(1_literal)(_core_tagged_union_Unsafe_cast{1_literal}(_core_array_base_address(x)[i])) = b;

                        k(
                            _core_Hash_table<X ...>{
                                _core_hash_table_size(f),
                                x,
                                hash
                            }
                        );
                    }
                    else
                        i = {(i + 1) & (_core_array_size(x) - 1)};

                    _core_array_base_address(x)[i] = {a, b};

                    k(
                        _core_Hash_table<X ...>(
                            _core_hash_table_size(f) + 1_literal,
                            x,
                            hash
                        )
                    );
                }
            }
        );
    }
    else {
        auto i = N{hash(a) & (buckets_size - 1)};

        while (_core_tagged_union_tag(_core_array_base_address(_core_hash_table_buckets(f))[i]) == 1)
        if (_core_projection(0_literal)(_core_tagged_union_Unsafe_cast{1_literal}(_core_array_base_address(_core_hash_table_buckets(f))[i])) == a) {
            _core_projection(1_literal)(_core_tagged_union_Unsafe_cast{1_literal}(_core_array_base_address(_core_hash_table_buckets(f))[i])) = b;

            k(f);
        }
        else
            i = {(i + 1) & (buckets_size - 1)};

        _core_array_base_address(_core_hash_table_buckets(f))[i] = {a, b};

        k(
            _core_Hash_table<X ...>{
                _core_hash_table_size(f) + 1,
                _core_hash_table_buckets(f),
                hash
            }
        );
    }
};

#endif
