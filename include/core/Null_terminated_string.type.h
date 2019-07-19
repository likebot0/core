#ifndef _core_Null_terminated_string
#define _core_Null_terminated_string ::core_Null_terminated_string

#include <core/Pointer.type.h>
#include <core/preprocessor/define_opaque_type_alias.h>

template<typename A>
_core_preprocessor_define_opaque_type_alias(core_Null_terminated_string, _core_Pointer<const A>);

template<typename A>
core_Null_terminated_string(A const*) -> _core_Null_terminated_string<A>;

#endif
