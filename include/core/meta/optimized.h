#ifndef _core_meta_optimized
#define _core_meta_optimized ::core_meta_optimized

#include <core/Hextet.type.h>
#include <core/Octet.type.h>
#include <core/Octlet.type.h>
#include <core/Quadlet.type.h>
#include <core/Signed_octet.type.h>
#include <core/Signed_octlet.type.h>
#include <core/Signed_hextet.type.h>
#include <core/Signed_quadlet.type.h>

template<auto a>
inline constexpr auto optimized = [] () constexpr {
    if constexpr (a >= 0 && _core_Octet {a} == a)
        return _core_Octet {a};
    else if constexpr (a > 0 && _core_Hextet {a} == a)
        return _core_Hextet {a};
    else if constexpr (a > 0 && _core_Quadlet {a} == a)
        return _core_Quadlet {a};
    else if constexpr (a > 0 && _core_Octlet {a} == a)
        return _core_Octlet {a};
    else if constexpr (_core_Signed_octet {a} == a)
        return _core_Signed_octet {a};
    else if constexpr (_core_Signed_hextet {a} == a)
        return _core_Signed_hextet {a};
    else if constexpr (_core_Signed_quadlet {a} == a)
        return _core_Signed_quadlet {a};
    else if constexpr (_core_Signed_octlet {a} == a)
        return _core_Signed_octlet {a};
    else
        return a;
}();

#endif
