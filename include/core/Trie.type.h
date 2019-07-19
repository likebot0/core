#ifndef _core_Trie
#define _core_Trie ::core_Trie

#include <core/Pointer.type.h>
#include <core/Product.type.h>
#include <core/Size.type.h>

template<typename A, typename B>
struct core_Trie : _core_Product<A, B, _core_Pointer<_core_Trie<A, B>>> {
};

#endif
