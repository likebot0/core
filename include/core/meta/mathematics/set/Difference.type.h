#ifndef _core_meta_mathematics_set_Difference
#define _core_meta_mathematics_set_Difference ::core_meta_mathematics_set_Difference

template<typename ... A>
struct core_meta_mathematics_set_Difference_;

template<typename A, typename B>
using core_meta_mathematics_set_Difference = typename core_meta_mathematics_set_Difference_<A, B>::Value;

#include <core/meta/Conditional.type.h>
#include <core/meta/mathematics/Set.type.h>
#include <core/meta/mathematics/set/Union.type.h>
#include <core/meta/mathematics/set/contains.h>

template<typename ... A, typename ... B>
struct core_meta_mathematics_set_Difference_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<B ...>> {
    using Value = _core_meta_mathematics_set_Union<
        _core_meta_Conditional<
            _core_meta_mathematics_set_contains<_core_meta_mathematics_Set<B ...>, A>,
            _core_meta_mathematics_Set<>,
            _core_meta_mathematics_Set<A>
        > ...
    >;
};

#endif
