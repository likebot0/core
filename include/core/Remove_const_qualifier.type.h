#ifndef _core_Remove_const_qualifier
#define _core_Remove_const_qualifier ::core_Remove_const_qualifier

template<typename A>
struct core_Remove_const_qualifier_;

template<typename A>
using core_Remove_const_qualifier = typename core_Remove_const_qualifier_<A>::Value;

template<typename A>
struct core_Remove_const_qualifier_ {
    using Value = A;
};

template<typename A>
struct core_Remove_const_qualifier_<const A> {
    using Value = A;
};

template<typename A>
struct core_Remove_const_qualifier_<const A &> {
    using Value = A &;
};

template<typename A>
struct core_Remove_const_qualifier_<const A &&> {
    using Value = A &&;
};

#endif
