#ifndef _core_Tagged_union
#define _core_Tagged_union ::core_Tagged_union

template<typename ... A>
struct core_Tagged_union_;

template<typename ... A>
using core_Tagged_union = typename core_Tagged_union_<A ...>::Value;

#include <core/Default_tagged_union.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/meta/Conditional.type.h>
#include <core/meta/is_unit_type.h>

template<>
struct core_Tagged_union_<> {
    using Value = void;
};

template<typename ... A>
struct core_Tagged_union_ {
    using Value = _core_meta_Conditional<
        (_core_meta_is_unit_type<A> && ...),
        _core_Simple_tagged_union<A ...>,
        _core_Default_tagged_union<A ...>
    >;
};

#endif
