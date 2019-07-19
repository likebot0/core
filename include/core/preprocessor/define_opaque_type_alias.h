#ifndef _core_preprocessor_define_opaque_type_alias
#define _core_preprocessor_define_opaque_type_alias(A, B) \
    struct A : _core_Product<B> {\
        using C = _core_Product<B>;\
        \
        using C::C;\
        \
        using Base_object = B;\
    };

#include <core/Product.type.h>

#endif
