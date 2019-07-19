#ifndef _core_meta_mathematics_tuple_length
#define _core_meta_mathematics_tuple_length ::core_meta_mathematics_tuple_length

template<typename A>
struct core_meta_mathematics_tuple_length_;

template<typename A>
inline constexpr auto core_meta_mathematics_tuple_length = core_meta_mathematics_tuple_length_<A>::value;

#include <core/meta/mathematics/Tuple.type.h>
#include <core/operator""_literal.h>

template<typename ... A>
struct core_meta_mathematics_tuple_length_<_core_meta_mathematics_Tuple<A ...>> {
    static constexpr auto value = (0_literal + ... + (sizeof(A), 1_literal));
};

#endif
