#ifndef _core_array_from
#define _core_array_from ::core_array_from

#include <core/Boxed_array.type.h>

template<typename K, typename A, typename ... B>
inline constexpr auto core_array_from(
    K && k,
    A && a,
    B && ... b
) {
    using E = _core_Remove_all_qualifiers<A>;

    constexpr auto n = _core_meta_length<_core_meta_Tuple<A, B ...>>;

    k(_core_Boxed_array<E, n> {a, b ...});
}

#endif
