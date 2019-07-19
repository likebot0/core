#ifndef _core_tagged_union_Hoge
#define _core_tagged_union_Hoge ::core_tagged_union_Hoge

template<typename F, typename A, typename I, typename B>
struct core_tagged_union_Hoge;

#include <core/Default_tagged_union.type.h>
#include <core/Pointer.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/projection.h>
#include <core/tagged_union/Unsafe_cast.h>

template<typename F, typename A, typename I, typename ... B>
struct core_tagged_union_Hoge<F, A, I, _core_Default_tagged_union<B ...>> {
    using Value = _core_Pointer<_core_Default_tagged_union<B ...> (F, A)>;

    constexpr operator Value(
    ) const {
        return [] (
            F f,
            A a
        ) constexpr -> _core_Default_tagged_union<B ...> {
            return {
                {I{}},
                _core_projection(I{})(f)(_core_tagged_union_Unsafe_cast{I{}}(a))
            };
        };
    }
};

template<typename F, typename A, typename I, typename ... B>
struct core_tagged_union_Hoge<F, A, I, _core_Simple_tagged_union<B ...>> {
    using Value = _core_Pointer<_core_Simple_tagged_union<B ...> (F, A)>;

    constexpr operator Value(
    ) const {
        return [] (
            F f,
            A a
        ) constexpr -> _core_Simple_tagged_union<B ...> {
            return {
                {I{}},
                _core_projection(I{})(f)(_core_tagged_union_Unsafe_cast{I{}}(a))
            };
        };
    }
};

#endif
