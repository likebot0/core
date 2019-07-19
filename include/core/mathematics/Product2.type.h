#ifndef _core_mathematics_Product2
#define _core_mathematics_Product2 ::core_mathematics_Product2

template<typename A, typename ... B>
struct core_mathematics_Product2;

template<typename A>
struct core_mathematics_Product2<A> {
    A a;

    constexpr core_mathematics_Product2(const A & a) : a {a} {
    }

    constexpr operator A() const {
        return a;
    }
};

template<typename A, typename ... B>
struct core_mathematics_Product2 {
    A a;

    _core_mathematics_Product<B ...> x;

    constexpr core_mathematics_Product2(const A & a, const B & ... b) : a {a} {
    }
};

#endif
