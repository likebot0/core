#ifndef _core_meta_is_defined
#define _core_meta_is_defined ::core_meta_is_defined

template<typename A>
struct core_meta_is_defined_;

template<typename A>
inline constexpr auto core_meta_is_defined = core_meta_is_defined_<A>::value;

#include <core/False.type.h>
#include <core/True.type.h>

template<typename A>
struct core_meta_is_defined_ {
    template<typename B>
    static auto Value(
        decltype(sizeof(B), nullptr)
    ) -> _core_True;

    template<typename B>
    static auto Value(
        ...
    ) -> _core_False;

    static constexpr auto value = decltype(Value<A>(nullptr)){};
};

#endif
