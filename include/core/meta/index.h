#ifndef _core_meta_index
#define _core_meta_index ::core_meta_index

template<typename F, typename A>
struct core_meta_index_;

template<typename F, typename A>
inline constexpr auto core_meta_index = core_meta_index_<F, A>::value;

#include <core/meta/Tuple.type.h>
#include <core/meta/is_equal_to.h>
#include <core/operator""_literal.h>

template<typename A, typename ... Rest, typename B>
struct core_meta_index_<
    _core_meta_Tuple<A, Rest ...>,
    B
> {
    template<typename X>
    static constexpr auto value_ = [] () {
        if constexpr (_core_meta_is_equal_to<A, X>)
            return 0_literal;
        else
            return 1_literal + _core_meta_index<_core_meta_Tuple<Rest ...>, X>;
    };

    static constexpr auto value = value_<B>;
};

#endif
