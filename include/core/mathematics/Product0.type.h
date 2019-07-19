#ifndef _core_mathematics_Product0
#define _core_mathematics_Product0 ::core_mathematics_Product0

template<typename ... A>
struct core_mathematics_Product0;

template<>
struct core_mathematics_Product0<> {
    constexpr core_mathematics_Product0() = default;
};

template<typename A>
struct core_mathematics_Product0<A> {
    constexpr core_mathematics_Product0() = default;

    constexpr core_mathematics_Product0(const A & a) {
    }

    constexpr operator A() const {
        return A {};
    }
};

template<typename A, typename ... B>
struct core_mathematics_Product0<A, B ...> {
    constexpr core_mathematics_Product0() = default;

    constexpr core_mathematics_Product0(const A & a, const B & ... b) {
    }
};

#endif
