#ifndef _core_meta_is_aggregate_initializable
#define _core_meta_is_aggregate_initializable ::core_meta_is_aggregate_initializable

template<typename A, typename B>
struct core_meta_is_aggregate_initializable_;

template<typename A, typename B>
inline constexpr auto core_meta_is_aggregate_initializable = core_meta_is_aggregate_initializable_<A, B>::value;

#include <core/False.type.h>
#include <core/True.type.h>
#include <core/meta/declval.h>

template<typename A, typename B>
struct core_meta_is_aggregate_initializable_ {
    template<typename X>
    static auto Value(
        decltype(B {core_meta_declval<X>()}, nullptr)
    ) -> _core_True;

    template<typename X>
    static auto Value(
        ...
    ) -> _core_False;

    static constexpr auto value = decltype(Value<A>(nullptr))();
};

#endif
