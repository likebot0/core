#ifndef _core_ieee_std_1003dot1_Memory
#define _core_ieee_std_1003dot1_Memory ::core_ieee_std_1003dot1_Memory

template<typename A, typename N>
struct core_ieee_std_1003dot1_Memory;

#include <core/Pointer.type.h>
#include <core/Product.type.h>

template<typename A, typename N>
struct core_ieee_std_1003dot1_Memory : _core_Product<_core_Pointer<A>, N> {
    using Base_object = _core_Product<_core_Pointer<A>, N>;

    using Base_object::Base_object;
};

template<typename A, typename N>
core_ieee_std_1003dot1_Memory(_core_Pointer<A>, N) -> core_ieee_std_1003dot1_Memory<A, N>;

#endif
