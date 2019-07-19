#ifndef _core_preprocessor_define_map
#define _core_preprocessor_define_map(f, f_) \
    template<typename ... _>\
    inline constexpr auto f_ = nullptr;\
    \
    inline constexpr struct {\
        template<typename ... _>\
        [[gnu::always_inline]]\
        inline auto operator()(\
            _ && ... a\
        ) const noexcept -> decltype(auto) {\
            return f_<_core_Remove_all_qualifiers<_> ...>(a ...);\
        }\
    } f;

#define _core_preprocessor_define_map2(f, f_)\
    template<typename ... _>\
    inline constexpr auto f_ = nullptr;\
    \
    inline constexpr struct {\
        template<typename ... _>\
        [[\
            noreturn,\
            gnu::always_inline\
        ]]\
        inline void operator()(\
            _ && ... a\
        ) const noexcept {\
            f_<_core_Remove_all_qualifiers<_> ...>(a ...);\
        }\
    } f;

#define _core_preprocessor_define_map3(f, f_)\
    template<typename ... A>\
    struct f_;\
    \
    inline constexpr struct {\
        template<typename ... _>\
        [[\
            noreturn,\
            gnu::always_inline\
        ]]\
        inline void operator()(\
            _ && ... a\
        ) const noexcept {\
            f_<_core_Remove_all_qualifiers<_> ...>{}(a ...);\
        }\
    } f;

#include <core/Remove_all_qualifiers.type.h>

#endif
