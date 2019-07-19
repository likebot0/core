#ifndef _core_hash_table_buckets
#define _core_hash_table_buckets ::core_hash_table_buckets

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_hash_table_buckets, core_hash_table_buckets_);

#include <core/Hash_table.type.h>
#include <core/base_object.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<typename ... X>
inline constexpr auto core_hash_table_buckets_<
    _core_Hash_table<X ...>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(1_literal)(_core_base_object(f));
};

#endif
