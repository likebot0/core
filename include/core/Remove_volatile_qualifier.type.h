#ifndef _core_Remove_volatile_qualifier
#define _core_Remove_volatile_qualifier ::core_Remove_volatile_qualifier

template<typename A>
struct core_Remove_volatile_qualifier_;

template<typename A>
using core_Remove_volatile_qualifier = typename core_Remove_volatile_qualifier_<A>::Value;

template<typename A>
struct core_Remove_volatile_qualifier_ {
    using Value = A;
};

template<typename A>
struct core_Remove_volatile_qualifier_<volatile A> {
    using Value = A;
};

template<typename A>
struct core_Remove_volatile_qualifier_<volatile A &> {
    using Value = A &;
};

template<typename A>
struct core_Remove_volatile_qualifier_<volatile A &&> {
    using Value = A &&;
};

#endif
