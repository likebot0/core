#ifndef _core_meta_mathematics_multiset_multiplicity
#define _core_meta_mathematics_multiset_multiplicity ::core_meta_mathematics_multiset_multiplicity

template<typename A, typename B>
struct core_meta_mathematics_multiset_multiplicity_;

template<typename A, typename B>
inline constexpr auto core_meta_mathematics_multiset_multiplicity = core_meta_mathematics_multiset_multiplicity_<A, B>::value;

#include <core/meta/Multiset.type.h>
#include <core/meta/is_equal_to.h>
#include <core/operator""_literal.h>

template<typename A, typename ... B>
struct core_meta_mathematics_multiset_multiplicity_<A, _core_meta_Multiset<B ...>> {
    static constexpr auto value = (0_literal + ... + _core_Size{_core_meta_is_equal_to<A, B> ? 1 : 0});
};

#endif
