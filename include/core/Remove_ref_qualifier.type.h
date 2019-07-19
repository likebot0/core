#ifndef _core_Remove_ref_qualifier
#define _core_Remove_ref_qualifier ::core_Remove_ref_qualifier

template<typename A>
struct core_Remove_ref_qualifier_;

template<typename A>
using core_Remove_ref_qualifier = typename core_Remove_ref_qualifier_<A>::Value;

template<typename A>
struct core_Remove_ref_qualifier_ {
    using Value = A;
};

template<typename A>
struct core_Remove_ref_qualifier_<A &> {
    using Value = A;
};

template<typename A>
struct core_Remove_ref_qualifier_<A &&> {
    using Value = A;
};

#endif
