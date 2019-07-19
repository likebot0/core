#ifndef _core_Hash_table
#define _core_Hash_table ::core_Hash_table

#include <core/hash_table/Default_hash_function.type.h>

template<typename A, typename B, typename HashFunction = _core_hash_table_Default_hash_function>
struct core_Hash_table;

#include <core/Array.type.h>
#include <core/Maybe.type.h>
#include <core/Product.type.h>
#include <core/Size.type.h>

template<typename A, typename B, typename HashFunction>
struct core_Hash_table : _core_Product<_core_Size, _core_Array<_core_Maybe<_core_Product<A, B>>, _core_Size>, HashFunction> {
    using Base_object = _core_Product<_core_Size, _core_Array<_core_Maybe<_core_Product<A, B>>, _core_Size>, HashFunction>;

    using Base_object::Base_object;
};

#endif
