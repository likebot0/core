#ifndef _core_Remove_cv_qualifiers
#define _core_Remove_cv_qualifiers ::core_Remove_cv_qualifiers

#include <core/Remove_const_qualifier.type.h>
#include <core/Remove_volatile_qualifier.type.h>

template<typename A>
using core_Remove_cv_qualifiers = _core_Remove_const_qualifier<_core_Remove_volatile_qualifier<A>>;

#endif
