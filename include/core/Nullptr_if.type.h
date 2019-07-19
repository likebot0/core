#ifndef _core_Nullptr_if
#define _core_Nullptr_if ::core_Nullptr_if

template<bool p>
struct core_Nullptr_if_;

template<bool p>
using core_Nullptr_if = typename core_Nullptr_if_<p>::Value;

#include <core/Nullptr.type.h>

template<>
struct core_Nullptr_if_<false> {
};

template<>
struct core_Nullptr_if_<true> {
    using Value = _core_Nullptr;
};

#endif
