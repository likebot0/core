#ifndef _core_meta_is_convertible
#define _core_meta_is_convertible ::core_meta_is_convertible

template<typename A, typename B>
struct core_meta_is_convertible_;

template<typename A, typename B>
inline constexpr auto core_meta_is_convertible = core_meta_is_convertible_<A, B>::value;

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/meta/declval.h>

template<typename A, typename B>
struct core_meta_is_convertible_ {
    template<typename Y, typename X>
    static auto Value(
        const X & x
    ) -> decltype((Y) x, _core_True{});

    template<typename Y>
    static auto Value(
        ...
    ) -> _core_False;

    static constexpr auto value = decltype(Value<B>(_core_meta_declval<A>())){};
};

#endif
