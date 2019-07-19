#ifndef _core_meta_mathematics_set_is_subset_of
#define _core_meta_mathematics_set_is_subset_of ::core_meta_mathematics_set_is_subset_of

template<typename A, typename B>
struct core_meta_mathematics_set_is_subset_of_;

template<typename A, typename B>
inline constexpr auto core_meta_mathematics_set_is_subset_of = core_meta_mathematics_set_is_subset_of_<A, B>::value;

#include <core/False.type.h>
#include <core/meta/contains.h>
#include <core/meta/mathematics/Set.type.h>

template<typename A, typename B>
struct core_meta_mathematics_set_is_subset_of_ {
    static constexpr auto value = _core_False{};
};

template<typename ... A, typename ... B>
struct core_meta_mathematics_set_is_subset_of_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<B ...>> {
    static constexpr auto value = [] () {
        if constexpr ((_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<A ...>, B> && ...))
            return _core_True{};
        else
            return _core_False{};
    }();
};

#endif
