#ifndef _core_mathematics_set_Union
#define _core_mathematics_set_Union ::core_mathematics_set_Union

#include <core/Tagged_union.type.h>
#include <core/meta/Set.type.h>
#include <core/meta/mathematics/set/Difference.type.h>
#include <core/meta/mathematics/set/Union.type.h>

template<typename A>
struct core_meta_ValueOf_;

template<typename A>
using core_meta_ValueOf = typename core_meta_ValueOf_<A>::Value;

template<>
struct core_meta_ValueOf_<_core_meta_Set<>> {
    using Value = void;
};

template<typename A>
struct core_meta_ValueOf_<_core_meta_Set<A>> {
    using Value = A;
};

template<typename ... A>
struct core_meta_ValueOf_<_core_meta_Set<A ...>> {
    using Value = _core_Tagged_union<A ...>;
};

template<typename ... A>
using core_mathematics_set_Union = core_meta_ValueOf<
    _core_meta_mathematics_set_Difference<
        _core_meta_mathematics_set_Union<_core_meta_Set<A> ...>,
        _core_meta_Set<void>
    >
>;

#endif
