#ifndef _core_Targets
#define _core_Targets ::core_Targets

#include <core/Product.type.h>

template<typename ... A>
struct core_Targets : _core_Product<A ...> {
    using Base_object = _core_Product<A ...>;

    using Base_object::Base_object;
};

template<typename ... A>
core_Targets(A ...) -> core_Targets<A ...>;

#endif
