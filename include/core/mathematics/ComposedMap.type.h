#ifndef _core_mathematics_ComposedMap
#define _core_mathematics_ComposedMap ::core_mathematics_ComposedMap

template<typename ... F>
struct core_mathematics_ComposedMap;

#include <core/Product.type.h>
#include <core/base_object.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<>
struct core_mathematics_ComposedMap<> {
};

template<typename F>
struct core_mathematics_ComposedMap<F> : _core_Product<F> {
    using Base_object = _core_Product<F>;

    using Base_object::Base_object;

    template<typename ... A>
    constexpr auto operator ()(
        A && ... a
    ) const -> decltype(auto) {
        return _core_projection(0_literal)(_core_base_object(* this))(
            static_cast<decltype(a) &&>(a) ...
        );
    }
};

template<typename F, typename ... G>
struct core_mathematics_ComposedMap<F, G ...> : _core_Product<F, _core_mathematics_ComposedMap<G ...>> {
    using Base_object = _core_Product<F, _core_mathematics_ComposedMap<G ...>>;

    using Base_object::Base_object;

    template<typename ... A>
    constexpr auto operator ()(
        A && ... a
    ) const -> decltype(auto) {
        return
            _core_projection(0_literal)(_core_base_object(* this))(
                _core_projection(1_literal)(_core_base_object(* this))(
                    static_cast<decltype(a) &&>(a) ...
                )
            )
        ;
    }
};

#endif
