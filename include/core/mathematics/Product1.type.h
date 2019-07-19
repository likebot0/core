#ifndef _core_mathematics_Product1
#define _core_mathematics_Product1 ::core_mathematics_Product1

template<typename A, typename ... B>
struct core_mathematics_Product1;

#include <core/mathematics/Product.type.h>

template<typename A, typename ... B>
struct core_mathematics_Product1 {
    _core_mathematics_Product<B ...> x;

    constexpr core_mathematics_Product1(const A &, const B & ... b) : x {b ...} {
    }
};

#endif
