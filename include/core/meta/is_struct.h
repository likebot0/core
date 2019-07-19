#ifndef _core_meta_is_struct
#define _core_meta_is_struct core_::core_meta_is_struct

template<typename A>
struct core_meta_is_struct_;

template<typename A>
inline constexpr auto core_meta_is_struct = core_meta_is_struct_<A>::value;

#include <core/False.type.h>
#include <core/Nullptr.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/True.type.h>

#if __has_include(<type_traits>)
#include <type_traits>
#endif

#if __has_include(<type_traits>)
template<typename A>
struct core_meta_is_struct_ {
    static constexpr auto value = [] () constexpr {
        if constexpr (std::is_class_v<A>)
            return _core_True{};
        else
            return _core_False{};
    }();
};
#endif

template<>
struct core_meta_is_struct_<_core_Nullptr> {
    static constexpr auto value = _core_True{};
};

#endif
