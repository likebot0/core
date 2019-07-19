#ifndef _core_meta_is_invocable
#define _core_meta_is_invocable ::core_meta_is_invocable

template<typename F, typename ... A>
struct core_meta_is_invocable_;

template<typename F, typename ... A>
inline constexpr auto core_meta_is_invocable = core_meta_is_invocable_<F, A ...>::value;

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/meta/declval.h>

template<typename F, typename ... A>
struct core_meta_is_invocable_ {
    template<typename G, typename ... B>
    static auto Value(
        decltype(_core_meta_declval<G>()(_core_meta_declval<B>() ...), nullptr)
    ) -> _core_True;

    template<typename G, typename ... B>
    static auto Value(
        ...
    ) -> _core_False;

    static constexpr auto value = decltype(Value<F, A ...>(nullptr)){};
};

#endif
