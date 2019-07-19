#ifndef _core_Default_tagged_union
#define _core_Default_tagged_union ::core_Default_tagged_union

template<typename ... A>
struct core_Default_tagged_union;

#include <core/Nullptr_if.type.h>
#include <core/Product.type.h>
#include <core/Untagged_union.type.h>
#include <core/meta/Multiset.type.h>
#include <core/meta/Tuple.type.h>
#include <core/meta/index.h>
#include <core/meta/is_equal_to.h>
#include <core/meta/multiplicity.h>
#include <core/tagged_union/Tag.type.h>

template<typename ... A>
struct core_Default_tagged_union : _core_Product<_core_tagged_union_Tag<A ...>, _core_Untagged_union<A ...>> {
    using Base_object = _core_Product<_core_tagged_union_Tag<A ...>, _core_Untagged_union<A ...>>;

    using Base_object::Base_object;

    template<
        typename X,
        _core_Nullptr_if<_core_meta_multiplicity<X, _core_meta_Multiset<A ...>> == 1> = nullptr
    >
    constexpr core_Default_tagged_union(
        const X & x
    ) : Base_object {
        {_core_meta_index<_core_meta_Tuple<A ...>, X>},
        x
    } {
    }
};

#endif
