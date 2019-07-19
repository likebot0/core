#ifndef _core_meta_is_unit_type
#define _core_meta_is_unit_type ::core_meta_is_unit_type

template<typename A>
struct core_meta_is_unit_type_;

template<typename A>
inline constexpr auto core_meta_is_unit_type = core_meta_is_unit_type_<A>::value;

#include <core/False.type.h>
#include <core/Nullptr.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/True.type.h>

#if __has_include(<type_traits>)
#include <type_traits>
#endif

#if __has_include(<type_traits>)
template<typename A>
struct core_meta_is_unit_type_ {
    static constexpr auto value = [] () constexpr {
        if constexpr (std::is_empty_v<A>)
            return _core_True{};
        else
            return _core_False{};
    }();
};
#endif

template<>
struct core_meta_is_unit_type_<_core_Nullptr> {
    static constexpr auto value = _core_True{};
};

#endif
