#ifndef _core_meta_mathematics_is_equal_to
#define _core_meta_mathematics_is_equal_to ::core_meta_mathematics_is_equal_to

template<typename A, typename B>
struct core_meta_mathematics_is_equal_to_;

template<typename A, typename B>
inline constexpr auto core_meta_mathematics_is_equal_to = core_meta_mathematics_is_equal_to_<A, B>::value;

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/meta/mathematics/Set.type.h>
#include <core/meta/mathematics/set/contains.h>

template<typename A, typename B>
struct core_meta_mathematics_is_equal_to_ {
    static constexpr auto value = _core_False{};
};

template<typename A>
struct core_meta_mathematics_is_equal_to_<A, A> {
    static constexpr auto value = _core_True{};
};

template<typename ... A>
struct core_meta_mathematics_is_equal_to_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<A ...>> {
    static constexpr auto value = _core_True{};
};

template<typename ... A, typename ... B>
struct core_meta_mathematics_is_equal_to_<_core_meta_mathematics_Set<A ...>, _core_meta_mathematics_Set<B ...>> {
    static constexpr auto value = [] () {
        if constexpr (
            (_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<B ...>, A> && ...)
         && (_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<A ...>, B> && ...)
        )
            return _core_True{};
        else
            return _core_False{};
    }();
};

#endif
