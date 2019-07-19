#ifndef _core_Remove_all_qualifiers
#define _core_Remove_all_qualifiers ::core_Remove_all_qualifiers

#include <core/Remove_cv_qualifiers.type.h>
#include <core/Remove_ref_qualifier.type.h>

template<typename A>
using core_Remove_all_qualifiers = _core_Remove_cv_qualifiers<_core_Remove_ref_qualifier<A>>;

#endif
