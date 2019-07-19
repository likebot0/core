#ifndef _core_meta_mathematics_set_contains
#define _core_meta_mathematics_set_contains ::core_meta_mathematics_set_contains

template<typename A, typename B>
struct core_meta_mathematics_set_contains_;

template<typename A, typename B>
inline constexpr auto core_meta_mathematics_set_contains = core_meta_mathematics_set_contains_<A, B>::value;

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/meta/mathematics/Set.type.h>

template<typename A>
struct core_meta_mathematics_set_contains_<_core_meta_mathematics_Set<A>, A> {
    static constexpr auto value = _core_True{};
};

template<typename A, typename B>
struct core_meta_mathematics_set_contains_<_core_meta_mathematics_Set<A>, B> {
    static constexpr auto value = _core_False{};
};

template<typename ... A, typename B>
struct core_meta_mathematics_set_contains_<_core_meta_mathematics_Set<A ...>, B> {
    static constexpr auto value = [] () {
        if constexpr ((_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<A>, B> || ...))
            return _core_True{};
        else
            return _core_False{};
    }();
};

#endif
