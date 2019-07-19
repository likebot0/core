
#ifndef _core_Boxed_array
#define _core_Boxed_array ::core_Boxed_array

template<typename A, _core_Size n>
struct core_Boxed_array {
    A array[n];
};

#endif
