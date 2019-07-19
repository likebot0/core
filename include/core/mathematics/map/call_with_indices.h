#ifndef _core_mathematics_map_call_with_indices
#define _core_mathematics_map_call_with_indices ::core_mathematics_map_call_with_indices

template<typename ... A>
struct core_mathematics_map_CallWithIndices_;

template<typename ... A>
using core_mathematics_map_CallWithIndices = typename core_mathematics_map_CallWithIndices_<A ...>::Value;

template<typename ... A>
inline constexpr auto core_mathematics_map_call_with_indices = core_mathematics_map_CallWithIndices<A ...>{};

#include <core/Product.type.h>

template<typename ... A>
struct core_mathematics_map_CallWith {
    template<typename F>
    constexpr auto operator ()(
        F && f
    ) const noexcept -> decltype(auto) {
        return static_cast<F &&>(f)(A{} ...);
    }
};

template<>
struct core_mathematics_map_CallWithIndices_<
> {
    using Value = core_mathematics_map_CallWith<>;
};

template<typename ... A>
struct core_mathematics_map_CallWithIndices_ {
    template<typename I, typename ... J>
    static constexpr auto value(
        I i,
        J ... j
    ) -> decltype(auto) {
        constexpr auto k = I{} - 1_literal;

        if constexpr (k == 0)
            return core_mathematics_map_CallWith<decltype(k), J ...>{};
        else
            return value(k, k, j ...);
    };

    using Value = decltype(value((0_literal + ... + (sizeof(A), 1_literal))));
};

#endif
