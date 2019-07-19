#ifndef _core_Untagged_union
#define _core_Untagged_union ::core_Untagged_union

template<typename A, typename ... B>
union core_Untagged_union;

#include <core/Nullptr_if.type.h>
#include <core/meta/Set.type.h>
#include <core/meta/contains.h>
#include <core/meta/is_aggregate_initializable.h>

template<typename A>
union core_Untagged_union<A> {
    A a;
};

template<typename A, typename ... Rest>
union core_Untagged_union {
    A a;

    _core_Untagged_union<Rest ...> rest;

    template<
        typename B,
        _core_Nullptr_if<
            ! _core_meta_contains<_core_meta_Set<Rest ...>, B>
         && _core_meta_is_aggregate_initializable<B, A>
        > = nullptr
    >
    constexpr core_Untagged_union(
        const B & b
    ) : a {b} {
    }

    template<
        typename B,
        _core_Nullptr_if<
            ! (
                ! _core_meta_contains<_core_meta_Set<Rest ...>, B>
             && _core_meta_is_aggregate_initializable<B, A>
            )
        > = nullptr
    >
    constexpr core_Untagged_union(
        const B & b
    ) : rest {b} {
    }
};

#endif
