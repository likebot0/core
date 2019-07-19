#ifndef _core_Base_object
#define _core_Base_object ::core_Base_object

template<typename A>
struct core_Base_object_;

template<typename A>
using core_Base_object = typename core_Base_object_<A>::Value;

template<typename A>
struct core_Base_object_ {
    using Value = typename A::Base_object;
};

template<typename A>
struct core_Base_object_<A &> {
    using Value = _core_Base_object<A> &;
};

template<typename A>
struct core_Base_object_<A &&> {
    using Value = _core_Base_object<A> &&;
};

template<typename A>
struct core_Base_object_<const A> {
    using Value = const _core_Base_object<A>;
};

template<typename A>
struct core_Base_object_<const volatile A> {
    using Value = const volatile _core_Base_object<A>;
};

template<typename A>
struct core_Base_object_<volatile A> {
    using Value = volatile _core_Base_object<A>;
};

#endif
