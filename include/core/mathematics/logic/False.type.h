#ifndef _core_mathematics_logic_False
#define _core_mathematics_logic_False ::core_mathematics_logic_False

struct core_mathematics_logic_False {
    constexpr operator bool() const {
        return false;
    }
};

#endif
