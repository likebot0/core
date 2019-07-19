#ifndef _core_mathematics_Product3
#define _core_mathematics_Product3 ::core_mathematics_Product3

template<typename A, typename ... B>
struct core_mathematics_Product3;

#include <core/mathematics/Product.type.h>

template<typename A, typename ... B>
struct core_mathematics_Product3 {
    A a;

    _core_mathematics_Product<B ...> x;

    constexpr core_mathematics_Product3(const A & a, const B & ... b) : a {a}, x {b ...} {
    }
};

#endif
