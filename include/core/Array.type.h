#ifndef _core_Array
#define _core_Array ::core_Array

#include <core/Size.type.h>

template<typename Address, typename Size = _core_Size>
struct core_Array;

#include <core/Pointer.type.h>
#include <core/Product.type.h>

template<typename Address, typename Size>
struct core_Array : _core_Product<Address, Size> {
    using Base_object = _core_Product<Address, Size>;

    using Base_object::Base_object;
};

template<typename Address, typename Size>
core_Array(Address, Size) -> core_Array<Address, Size>;

template <typename Element, _core_Size n>
struct core_Array3 {
    Element elements[n];

    constexpr core_Array3(
        const Element (& array)[n]
    ) : elements {} {
    }
};

template <typename Element, _core_Size n>
core_Array3(const Element (&array)[n]) -> core_Array3<Element, n>;

#endif
