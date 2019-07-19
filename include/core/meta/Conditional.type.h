#ifndef _core_meta_Conditional
#define _core_meta_Conditional ::core_meta_Conditional

template<bool p, typename A, typename B>
struct core_meta_Conditional_;

template<bool p, typename A, typename B>
using core_meta_Conditional = typename core_meta_Conditional_<p, A, B>::Value;

#include <core/False.type.h>
#include <core/True.type.h>

template<typename A, typename B>
struct core_meta_Conditional_<false, A, B> {
    using Value = B;
};

template<typename A, typename B>
struct core_meta_Conditional_<true, A, B> {
    using Value = A;
};

#endif
