#ifndef _core_hash_table_max_size
#define _core_hash_table_max_size ::core_hash_table_max_size

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_hash_table_max_size, core_hash_table_max_size_);

#include <core/Hash_table.type.h>
#include <core/hash_table/size.h>

template<typename ... X>
inline constexpr auto core_hash_table_max_size_<
    _core_Hash_table<X ...>
> = [] (
    auto & f
) constexpr -> decltype(auto) {
    using N = _core_Remove_all_qualifiers<decltype(_core_hash_table_size(f))>;

    return N{~(N{0})};
};

#endif
