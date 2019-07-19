#ifndef _core_meta_mathematics_set_Union
#define _core_meta_mathematics_set_Union ::core_meta_mathematics_set_Union

template<typename ... A>
struct core_meta_mathematics_set_Union_;

template<typename ... A>
using core_meta_mathematics_set_Union = typename core_meta_mathematics_set_Union_<A ...>::Value;

#include <core/Remove_all_qualifiers.type.h>
#include <core/meta/mathematics/Set.type.h>
#include <core/meta/mathematics/set/contains.h>

template<>
struct core_meta_mathematics_set_Union_<> {
    using Value = _core_meta_mathematics_Set<>;
};

template<typename A>
struct core_meta_mathematics_set_Union_<A> {
    using Value = A;
};

template<typename A, typename ... B>
struct core_meta_mathematics_set_Union_<A, B ...> {
    using Value = _core_meta_mathematics_set_Union<A, _core_meta_mathematics_set_Union<B ...>>;
};

template<typename ... A>
struct core_meta_mathematics_set_Union_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<>> {
    using Value = _core_meta_mathematics_Set<A ...>;
};

template<
    typename ... A,
    typename B,
    typename ... Rest
>
struct core_meta_mathematics_set_Union_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<B, Rest ...>> {
    using Value = _core_Remove_all_qualifiers<decltype([] {
        if constexpr (_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<A ...>, B>)
            return _core_meta_declval<_core_meta_mathematics_set_Union<_core_meta_mathematics_Set<A ...>,    _core_meta_mathematics_Set<Rest ...>>>();
        else
            return _core_meta_declval<_core_meta_mathematics_set_Union<_core_meta_mathematics_Set<A ..., B>, _core_meta_mathematics_Set<Rest ...>>>();
    }())>;
};

#endif
