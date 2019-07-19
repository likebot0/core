#ifndef _core_Fmap
#define _core_Fmap ::core_Fmap

template<typename ... F>
struct core_Fmap;

#include <core/Product.type.h>
#include <core/preprocessor/define_opaque_type_alias.h>

template<typename ... F>
_core_preprocessor_define_opaque_type_alias(core_Fmap, _core_Product<F ...>);

template<typename ... F>
core_Fmap(F ...) -> core_Fmap<F ...>;

#include <core/Default_tagged_union.type.h>
#include <core/Pointer.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/Simple_tagged_union.type.h>
#include <core/Sum.type.h>
#include <core/apply.h>
#include <core/base_object.h>
#include <core/mathematics/Product.type.h>
#include <core/mathematics/Product0.type.h>
#include <core/mathematics/Product1.type.h>
#include <core/mathematics/Product2.type.h>
#include <core/mathematics/Product3.type.h>
#include <core/mathematics/map/call_with_indices.h>
#include <core/tagged_union/Hoge.type.h>
#include <core/tagged_union/Unsafe_cast.h>
#include <core/tagged_union/tag.h>

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_Default_tagged_union<A ...>
> = [] (
    auto & f,
    auto & a
) constexpr -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) {
            using B = _core_Sum<
                _core_Remove_all_qualifiers<
                    decltype(
                        _core_projection(i)(_core_base_object(f))(
                            _core_tagged_union_Unsafe_cast{i}(a)
                        )
                    )
                > ...
            >;

            using G = _core_Pointer<B (decltype(_core_base_object(f)), decltype(a))>;

            G g[] = {
                _core_tagged_union_Hoge<
                    decltype(_core_base_object(f)),
                    decltype(a),
                    decltype(i),
                    B
                >() ...
            };

            return g[_core_tagged_union_tag(a)](_core_base_object(f), a);
        }
    );
};

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_Simple_tagged_union<A ...>
> = [] (
    auto & f,
    auto & a
) constexpr -> decltype(auto) {
    return _core_mathematics_map_call_with_indices<A ...>(
        [&] (auto ... i) {
            using B = _core_Sum<
                _core_Remove_all_qualifiers<
                    decltype(
                        _core_projection(i)(_core_base_object(f))(
                            _core_tagged_union_Unsafe_cast{i}(a)
                        )
                    )
                > ...
            >;

            using G = _core_Pointer<B (decltype(_core_base_object(f)), decltype(a))>;

            G g[] = {
                _core_tagged_union_Hoge<
                    decltype(_core_base_object(f)),
                    decltype(a),
                    decltype(i),
                    B
                >() ...
            };

            return g[_core_tagged_union_tag(a)](_core_base_object(f), a);
        }
    );
};

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product0<A ...>
> = [] (
    auto & f,
    auto & a
) constexpr -> decltype(auto) {
    return _core_apply(
        [&] (auto && ... f) {
            return _core_apply(
                [&] (auto && ... a) {
                    return _core_Product<
                        _core_Remove_all_qualifiers<decltype(f(a))> ...
                    >(
                        f(a) ...
                    );
                },
               _core_base_object(a)
            );
        },
        _core_base_object(f)
    );
};

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product1<A ...>
> = core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product0<A ...>
>;

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product2<A ...>
> = core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product0<A ...>
>;

template<typename ... F, typename ... A>
inline constexpr auto core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product3<A ...>
> = core_mathematics_map_apply_<
    _core_Fmap<F ...>,
    _core_mathematics_Product0<A ...>
>;

#endif
