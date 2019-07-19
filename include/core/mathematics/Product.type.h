#ifndef _core_mathematics_Product
#define _core_mathematics_Product ::core_mathematics_Product

template<typename ... A>
struct core_mathematics_Product_;

template<typename ... A>
using core_mathematics_Product = typename core_mathematics_Product_<A ...>::Value;

#include <core/mathematics/Product0.type.h>
#include <core/mathematics/Product1.type.h>
#include <core/mathematics/Product2.type.h>
#include <core/mathematics/Product3.type.h>
#include <core/meta/declval.h>
#include <core/meta/is_unit_type.h>

template<>
struct core_mathematics_Product_<> {
    using Value = _core_mathematics_Product0<>;
};

template<typename A, typename ... B>
struct core_mathematics_Product_<A, B ...> {
    using Value = decltype([] {
        if constexpr (_core_meta_is_unit_type<A> && (_core_meta_is_unit_type<B> && ...))
            return _core_meta_declval<_core_mathematics_Product0<A, B ...>>();
        else if constexpr (_core_meta_is_unit_type<A>)
            return _core_meta_declval<_core_mathematics_Product1<A, B ...>>();
        else if constexpr ((_core_meta_is_unit_type<B> && ...))
            return _core_meta_declval<_core_mathematics_Product2<A, B ...>>();
        else
            return _core_meta_declval<_core_mathematics_Product3<A, B ...>>();
    }());
};

#endif
