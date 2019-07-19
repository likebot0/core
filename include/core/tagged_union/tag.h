#ifndef _core_tagged_union_tag
#define _core_tagged_union_tag ::core_tagged_union_tag

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_tagged_union_tag, core_tagged_union_tag_);

#include <core/Default_tagged_union.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/base_object.h>
#include <core/operator""_literal.h>
#include <core/projection.h>

template<typename ... A>
inline constexpr auto core_tagged_union_tag_<
    _core_Default_tagged_union<A ...>
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return _core_projection(0_literal)(_core_base_object(a));
};

template<typename ... A>
inline constexpr auto core_tagged_union_tag_<
    _core_Simple_tagged_union<A ...>
> = [] (
    auto & a
) constexpr -> decltype(auto) {
    return _core_projection(0_literal)(_core_base_object(a));
};

#endif
