#ifndef _core_Literal
#define _core_Literal ::core_Literal

template<char32_t ... a>
struct core_Literal;

#include <core/Hextet.type.h>
#include <core/Octet.type.h>
#include <core/Octlet.type.h>
#include <core/Quadlet.type.h>
#include <core/Signed_hextet.type.h>
#include <core/Signed_octet.type.h>
#include <core/Signed_octlet.type.h>
#include <core/Signed_quadlet.type.h>

template<>
struct core_Literal<U'0'> {
    constexpr operator _core_Octet() const noexcept {
        return 0;
    }
};

template<>
struct core_Literal<U'1'> {
    constexpr operator _core_Octet() const noexcept {
        return 1;
    }
};

template<>
struct core_Literal<U'2'> {
    constexpr operator _core_Octet() const noexcept {
        return 2;
    }
};

template<>
struct core_Literal<U'3'> {
    constexpr operator _core_Octet() const noexcept {
        return 3;
    }
};

template<>
struct core_Literal<U'4'> {
    constexpr operator _core_Octet() const noexcept {
        return 4;
    }
};

template<>
struct core_Literal<U'5'> {
    constexpr operator _core_Octet() const noexcept {
        return 5;
    }
};

template<>
struct core_Literal<U'6'> {
    constexpr operator _core_Octet() const noexcept {
        return 6;
    }
};

template<>
struct core_Literal<U'7'> {
    constexpr operator _core_Octet() const noexcept {
        return 7;
    }
};

template<>
struct core_Literal<U'8'> {
    constexpr operator _core_Octet() const noexcept {
        return 8;
    }
};

template<>
struct core_Literal<U'9'> {
    constexpr operator _core_Octet() const noexcept {
        return 9;
    }
};

template<char32_t a, char32_t ... b>
struct core_Literal<a, b ...> {
    static constexpr auto first = core_Literal<a>{};

    static constexpr auto rest = core_Literal<b ...>{};

    using X = decltype([] {
        if constexpr (first <= 2u && rest <= 55u)
            return _core_Octet{0};
        else if constexpr (first <= 6u && rest <= 5535u)
            return _core_Hextet{0};
        else if constexpr (first <= 4u && rest <= 294967295ul)
            return _core_Quadlet{0};
        else if constexpr (first <= 1u && rest <= 8446744073709551615ull)
            return _core_Octlet{0};
        else
            return _core_Octlet{0};
    }());

    static constexpr auto x = X{first} * 10u + rest;

    constexpr operator X() const noexcept {
        return x;
    }
};

template<char32_t a>
struct core_Literal<U'-', a> {
    constexpr operator _core_Signed_octet() const noexcept {
        return - _core_Literal<a>{};
    }
};

template<char32_t a, char32_t ... b>
struct core_Literal<U'-', a, b ...> {
    using X = decltype([] {
        constexpr auto first = core_Literal<a>{};

        constexpr auto rest = core_Literal<b ...>{};

        if constexpr (first <= 1u && rest <= 28u)
            return _core_Signed_octet{- first};
        else if constexpr (first <= 3u && rest <= 2768u)
            return _core_Signed_hextet{first};
        else if constexpr (first <= 2u && rest <= 147483648ul)
            return _core_Signed_quadlet{first};
        else if constexpr (first <= 9u && rest <= 223372036854775808ull)
            return _core_Signed_octlet{first};
        else
            return _core_Signed_octlet{0};
    }());

    static constexpr auto x = X{} * 10 + X{};

    constexpr operator X() const noexcept {
        return - x;
    }
};

template<>
struct core_Literal<U'0', U'B', U'0'> : core_Literal<U'0'> {
};

template<>
struct core_Literal<U'0', U'B', U'1'> : core_Literal<U'1'> {
};

template<char32_t a, char32_t ... b>
struct core_Literal<U'0', U'B', a, b ...> {
};

template<char32_t a, char32_t ... b>
struct core_Literal<U'0', U'b', a, b ...> : core_Literal<U'0', U'B', a, b ...> {
};
template<char32_t ... a>
struct core_Literal<U'0', U'X', a ...> {
};

template<char32_t ... a>
struct core_Literal<U'0', U'x', a ...> : core_Literal<U'0', U'X', a ...> {
};

template<char32_t ... a>
inline constexpr auto operator +(
    _core_Literal<a ...>
) {
    return _core_Literal<a ...>{};
}

template<char32_t ... a>
inline constexpr auto operator -(
    _core_Literal<a ...>
) {
    return _core_Literal<'-', a ...>{};
}

template<char32_t ... a>
inline constexpr auto operator -(
    _core_Literal<U'-', a ...>
) {
    return _core_Literal<a ...>{};
}

template<char32_t a, char32_t b>
inline constexpr auto operator +(
    _core_Literal<a>,
    _core_Literal<b>
) {
    constexpr auto n = static_cast<_core_Octet>(_core_Literal<a>{}) + static_cast<_core_Octet>(_core_Literal<b>{});

    if constexpr (n == 0)
        return _core_Literal<U'0'>{};
    else if constexpr (n == 1)
        return _core_Literal<U'1'>{};
    else if constexpr (n == 2)
        return _core_Literal<U'2'>{};
    else if constexpr (n == 3)
        return _core_Literal<U'3'>{};
    else if constexpr (n == 4)
        return _core_Literal<U'4'>{};
    else if constexpr (n == 5)
        return _core_Literal<U'5'>{};
    else if constexpr (n == 6)
        return _core_Literal<U'6'>{};
    else if constexpr (n == 7)
        return _core_Literal<U'7'>{};
    else if constexpr (n == 8)
        return _core_Literal<U'8'>{};
    else if constexpr (n == 9)
        return _core_Literal<U'9'>{};
    else if constexpr (n == 10)
        return _core_Literal<U'1', U'0'>{};
    else if constexpr (n == 11)
        return _core_Literal<U'1', U'1'>{};
    else if constexpr (n == 12)
        return _core_Literal<U'1', U'2'>{};
    else if constexpr (n == 13)
        return _core_Literal<U'1', U'3'>{};
    else if constexpr (n == 14)
        return _core_Literal<U'1', U'4'>{};
    else if constexpr (n == 15)
        return _core_Literal<U'1', U'5'>{};
    else if constexpr (n == 16)
        return _core_Literal<U'1', U'6'>{};
    else if constexpr (n == 17)
        return _core_Literal<U'1', U'7'>{};
    else
        return _core_Literal<U'1', U'8'>{};
}

template<char32_t a, char32_t b>
inline constexpr auto operator +(
    _core_Literal<a>,
    _core_Literal<U'-', b>
) {
    if constexpr (_core_Literal<a>{} < _core_Literal<b>{})
        return - (_core_Literal<b>{} + (- _core_Literal<a>{}));
    else {
        constexpr auto n = static_cast<_core_Octet>(_core_Literal<a>{}) - core_Literal<b>{};

        if constexpr (n == 0)
            return _core_Literal<U'0'>{};
        else if constexpr (n == 1)
            return _core_Literal<U'1'>{};
        else if constexpr (n == 2)
            return _core_Literal<U'2'>{};
        else if constexpr (n == 3)
            return _core_Literal<U'3'>{};
        else if constexpr (n == 4)
            return _core_Literal<U'4'>{};
        else if constexpr (n == 5)
            return _core_Literal<U'5'>{};
        else if constexpr (n == 6)
            return _core_Literal<U'6'>{};
        else if constexpr (n == 7)
            return _core_Literal<U'7'>{};
        else if constexpr (n == 8)
            return _core_Literal<U'8'>{};
        else
            return _core_Literal<U'9'>{};
    }
}

template<char32_t ... a, char32_t ... b>
inline constexpr auto operator +(
    _core_Literal<a ...>,
    _core_Literal<b ...>
) {
    if constexpr (sizeof ...(a) < sizeof ...(b))
        return _core_Literal<U'0', a ...>{} + core_Literal<b ...>{};
    else if constexpr (sizeof ...(a) > sizeof ...(b))
        return _core_Literal<a ...>{} + core_Literal<U'0', b ...>{};
    else {
        constexpr auto f = [] (auto x, auto y) {
            auto n = (x + y) % 10;

            if (n == 0)
                return U'0';
            else if (n == 1)
                return U'1';
            else if (n == 2)
                return U'2';
            else if (n == 3)
                return U'3';
            else if (n == 4)
                return U'4';
            else if (n == 5)
                return U'5';
            else if (n == 6)
                return U'6';
            else if (n == 7)
                return U'7';
            else if (n == 8)
                return U'8';
            else
                return U'9';
        };

        constexpr auto x = _core_Literal<f(_core_Literal<a>{}, _core_Literal<b>{}) ...>{};

        constexpr auto y = _core_Literal<(_core_Literal<a>{} + _core_Literal<b>{} > 9 ? U'1' : U'0') ..., U'0'>{};

        if constexpr (y == 0)
            return x;
        else
            return x + y;
    }
}

template<char32_t ... a, char32_t ... b>
inline constexpr auto operator +(
    _core_Literal<U'-', a ...>,
    _core_Literal<U'-', b ...>
) {
    return - (_core_Literal<a ...>{} + core_Literal<b ...>{});
}

template<char32_t ... a, char32_t ... b>
inline constexpr auto operator +(
    _core_Literal<a ...>,
    _core_Literal<U'-', b ...>
) {
    if constexpr (_core_Literal<a ...>{} < core_Literal<b ...>{})
        return - (_core_Literal<b ...>{} + (- core_Literal<a ...>{}));
    else if constexpr (sizeof ...(a) < sizeof ...(b))
        return _core_Literal<U'0', a ...>{} + (- core_Literal<b ...>{});
    else if constexpr (sizeof ...(a) > sizeof ...(b))
        return _core_Literal<a ...>{} + (- core_Literal<U'0', b ...>{});
    else {
        constexpr auto f = [] (auto x, auto y) {
            auto n = (x < y ? x + 10 : x) - y;

            if (n == 0)
                return U'0';
            else if (n == 1)
                return U'1';
            else if (n == 2)
                return U'2';
            else if (n == 3)
                return U'3';
            else if (n == 4)
                return U'4';
            else if (n == 5)
                return U'5';
            else if (n == 6)
                return U'6';
            else if (n == 7)
                return U'7';
            else if (n == 8)
                return U'8';
            else
                return U'9';
        };

        constexpr auto x = _core_Literal<f(_core_Literal<a>{}, _core_Literal<b>{}) ...>{};

        constexpr auto y = _core_Literal<(_core_Literal<a>{} < _core_Literal<b>{} ? U'1' : U'0') ..., U'0'>{};

        if constexpr (y == 0)
            return x;
        else
            return x - y;
    }
}

template<char32_t ... a, char32_t ... b>
inline constexpr auto operator +(
    _core_Literal<U'-', a ...>,
    _core_Literal<b ...>
) {
    return _core_Literal<b ...>{} + (- core_Literal<a ...>{});
}

template<char32_t ... a, char32_t ... b>
inline constexpr auto operator -(
    _core_Literal<a ...>,
    _core_Literal<b ...>
) {
    return _core_Literal<a ...>{} + (- core_Literal<b ...>{});
}

#endif
