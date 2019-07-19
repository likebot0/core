#ifndef _core_Tree
#define _core_Tree ::core_Tree

template<typename A>
struct core_Tree;

#include <core/Array.type.h>
#include <core/Product.type.h>
#include <core/Size.type.h>
#include <core/base_object.h>
#include <core/operator""_literal.h>
#include <core/projection.h>
/*
template<typename A>
struct core_Tree : _core_Product<A, _core_Array<_core_Tree<A>>> {
    using Base_object = _core_Product<A, _core_Array<_core_Tree<A>>>;

    constexpr auto operator ()(
        _core_Size i
    ) && -> core_Tree<A> && {
        return static_cast<_core_Tree<A> &&>(_core_projection(1_literal)(_core_base_object(* this))(i));
    }

    constexpr auto operator ()(
        _core_Size i
    ) const & -> core_Tree<A> & {
        return _core_projection(1_literal)(_core_base_object(* this))(i);
    }

    constexpr operator A &(
    ) & {
        return _core_projection(0_literal)(_core_base_object(* this));
    }

    constexpr operator A &&(
    ) && {
        return static_cast<A &&>(_core_projection(0_literal)(_core_base_object(* this)));
    }

    constexpr operator const A &(
    ) const & {
        return _core_projection(0_literal)(_core_base_object(* this));
    }
};
*/
#endif
