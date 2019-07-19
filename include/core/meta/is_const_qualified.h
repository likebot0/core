#ifndef _core_meta_is_const_qualified
#define _core_meta_is_const_qualified ::core_meta_is_const_qualified

template<typename A>
struct core_meta_is_const_qualified_;

template<typename A>
inline constexpr auto core_meta_is_const_qualified = core_meta_is_const_qualified_<A>::value;

#include <core/False.type.h>
#include <core/True.type.h>

template<typename A>
struct core_meta_is_const_qualified_ {
    static constexpr auto value = _core_False{};
};

template<typename A>
struct core_meta_is_const_qualified_<const A> {
    static constexpr auto value = _core_True{};
};

template<typename A>
struct core_meta_is_const_qualified_<const A &> {
    static constexpr auto value = _core_True{};
};

template<typename A>
struct core_meta_is_const_qualified_<const A &&> {
    static constexpr auto value = _core_True{};
};

#endif
