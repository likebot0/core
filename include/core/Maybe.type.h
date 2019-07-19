#ifndef _core_Maybe
#define _core_Maybe ::core_Maybe

#include <core/Product.type.h>
#include <core/Sum.type.h>

struct _core_None {};

template<typename A>
using core_Maybe = _core_Sum<_core_None, A>;

#endif
