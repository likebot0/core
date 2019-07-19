#ifndef _core_base_object
#define _core_base_object ::core_base_object

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_base_object, core_base_object_);

#include <core/Base_object.type.h>

template<typename A>
inline constexpr auto core_base_object_<
    A
> = [] (
    auto & a
) -> decltype(auto) {
    return (_core_Base_object<decltype(a)>) a;
};

#endif
