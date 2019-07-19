#include <core/preprocessor/define_opaque_type_alias.h>

#ifndef _core_preprocessor_define_generic_opaque_type_alias
#define _core_preprocessor_define_generic_opaque_type_alias(A) \
    template<typename B>\
    _core_preprocessor_define_opaque_type_alias(A, B);\
    \
    template<typename B>\
    A(B) -> A<B>;

#endif
