#ifndef _core_hash_table_size
#define _core_hash_table_size ::core_hash_table_size

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_hash_table_size, core_hash_table_size_);

#include <core/Hash_table.type.h>
#include <core/base_object.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<typename ... X>
inline constexpr auto core_hash_table_size_<
    _core_Hash_table<X ...>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    return _core_projection(0_literal)(_core_base_object(f));
};

#endif
