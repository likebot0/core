#ifndef _core_hash_table_Default_hash_function
#define _core_hash_table_Default_hash_function ::core_hash_table_Default_hash_function

struct core_hash_table_Default_hash_function;

#include <core/Array.type.h>
#include <core/Nullptr.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/Size.type.h>
#include <core/array/base_address.h>
#include <core/array/size.h>
#include <core/memory/address.h>
#include <core/meta/is_equal_to.h>

struct core_hash_table_Default_hash_function {
    template<typename A>
    constexpr auto operator() (
        const A & a
    ) const -> _core_Size {
        if constexpr (sizeof(A) <= sizeof(_core_Size))
            return _core_Size{a};
        else
            if constexpr (_core_meta_is_equal_to<_core_Remove_all_qualifiers<decltype(core_array_base_address_<A>)>, _core_Nullptr>)
                return _core_array_size(a) xor (
                    _core_array_size(a) == 0 ? 0
                  :                           _core_hash_table_Default_hash_function{}(_core_array_base_address(a)[0])
                );
//            else
//                return _core_hash_table_Default_hash_function{}(_core_Array{sizeof(a), _core_memory_address(a)});
    }
};

#endif
