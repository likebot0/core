#ifndef _core_meta_mathematics_set_card
#define _core_meta_mathematics_set_card ::core_meta_mathematics_set_card

template<typename ... A>
struct core_meta_mathematics_set_card_;

template<typename A>
inline constexpr auto core_meta_mathematics_set_card = core_meta_mathematics_set_card_<A>::value;

#include <core/Hextet.type.h>
#include <core/Octet.type.h>
#include <core/Octlet.type.h>
#include <core/Product.type.h>
#include <core/Quadlet.type.h>
#include <core/Signed_hextet.type.h>
#include <core/Signed_octet.type.h>
#include <core/Signed_octlet.type.h>
#include <core/Signed_quadlet.type.h>
#include <core/meta/is_unit_type.h>
#include <core/meta/mathematics/Set.type.h>
#include <core/meta/mathematics/set/contains.h>
#include <core/operator""_literal.h>

template<typename A>
struct core_meta_mathematics_set_card_<
    A
> {
    static constexpr auto value = [] () {
        if constexpr (_core_meta_is_unit_type<A>)
            return 1_literal;
        else
            return nullptr;
    }();
};

template<typename A>
struct core_meta_mathematics_set_card_<
    A *
> : core_meta_mathematics_set_card_<
    decltype(static_cast<A *>(nullptr) - static_cast<A *>(nullptr))
> {
};

template<>
struct core_meta_mathematics_set_card_<
    void
> {
    static constexpr auto value = 0_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    bool
> {
    static constexpr auto value = 2_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Octet
> {
    static constexpr auto value = 256_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Signed_octet
> : core_meta_mathematics_set_card_<
    _core_Octet
> {
};

template<>
struct core_meta_mathematics_set_card_<
    char
> : core_meta_mathematics_set_card_<
    _core_Octet
> {
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Hextet
> {
    static constexpr auto value = 65536_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Signed_hextet
> : core_meta_mathematics_set_card_<
    _core_Hextet
> {
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Quadlet
> {
    static constexpr auto value = 4294967296_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Signed_quadlet
> : core_meta_mathematics_set_card_<
    _core_Quadlet
> {
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Octlet
> {
    static constexpr auto value = 18446744073709551615_literal;
};

template<>
struct core_meta_mathematics_set_card_<
    _core_Signed_octlet
> : core_meta_mathematics_set_card_<
    _core_Octlet
> {
};
/*
template<typename ... A>
struct core_meta_mathematics_set_card_<
    _core_Product<A ...>
> {
    using Value = decltype((_core_meta_mathematics_set_card<A> * ...));
};
*/
template<>
struct core_meta_mathematics_set_card_<_core_meta_Set<>> {
    static constexpr auto value = 0_literal;
};

template<typename A, typename ... Rest>
struct core_meta_mathematics_set_card_<_core_meta_mathematics_Set<A, Rest ...>> {
    static constexpr auto value = [] () {
        if constexpr (_core_meta_mathematics_set_contains<_core_meta_mathematics_Set<Rest ...>, A>)
            return 0_literal + _core_meta_mathematics_set_card<_core_meta_mathematics_Set<Rest ...>>;
        else
            return 1_literal + _core_meta_mathematics_set_card<_core_meta_mathematics_Set<Rest ...>>;
    }();
};

#endif
