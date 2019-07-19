#ifndef _core_tagged_union_Tag
#define _core_tagged_union_Tag ::core_tagged_union_Tag

template<typename ... A>
struct core_tagged_union_Tag_;

template<typename ... A>
using core_tagged_union_Tag = typename core_tagged_union_Tag_<A ...>::Value;

#include <core/Product.type.h>
#include <core/Hextet.type.h>
#include <core/Octet.type.h>
#include <core/Octlet.type.h>
#include <core/Quadlet.type.h>
#include <core/Size.type.h>
#include <core/meta/Tuple.type.h>
#include <core/meta/declval.h>
#include <core/meta/length.h>

template<typename A, typename ... B>
struct core_tagged_union_Tag_<A, B ...> {
    using Value = decltype([] {
        constexpr auto n = _core_meta_length<_core_meta_Tuple<A, B ...>>;

        if constexpr (n == 1u)
            return _core_meta_declval<_core_Product<>>();
        else if constexpr (n <= 256u)
            return _core_meta_declval<_core_Octet>();
        else if constexpr (n <= 65536ul)
            return _core_meta_declval<_core_Hextet>();
        else if constexpr (n <= 4294967296ull)
            return _core_meta_declval<_core_Quadlet>();
        else if constexpr (n <= 18446744073709551615ull)
            return _core_meta_declval<_core_Octlet>();
        else
            return _core_meta_declval<_core_Size>();
    }());
};

#endif
