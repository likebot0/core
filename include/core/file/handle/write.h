#ifndef _core_file_handle_write
#define _core_file_handle_write ::core_file_handle_write

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map3(core_file_handle_write, core_file_handle_write_);

#include <core/Nil.type.h>
#include <core/Pointer.type.h>
#include <core/Remove_all_qualifiers.type.h>
#include <core/Size.type.h>
#include <core/apply.h>
#include <core/array/base_address.h>
#include <core/array/from.h>
#include <core/array/size.h>
#include <core/base_object.h>
#include <core/file/Read_write_handle.type.h>
#include <core/file/Write_only_handle.type.h>
#include <core/id.h>
#include <core/ieee/std/1003dot1/Iovec.type.h>
#include <core/ieee/std/1003dot1/iovec/from.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<sys/uio.h>)
extern "C" {

#include <sys/uio.h>

}
#endif

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<sys/uio.h>)
template<typename ... A, typename Continuation>
struct core_file_handle_write_<
    _core_file_Write_only_handle,
    _core_Targets<A ...>,
    Continuation
> {

template<typename _1, typename _2, typename _3>
[[gnu::always_inline]] inline void operator ()(
    _1 && handle,
    _2 && x,
    _3 && k
) const {
    _core_apply(
        [&] (auto && ... x) {
            _core_ieee_std_1003dot1_iovec_from(
                [&] (auto && ... x) {
                    _core_array_from(
                        [&] (auto && f) {
                            auto i = _core_Size{0};

                            auto loop = [&] (auto && restart) {
                                auto x = ::writev(handle, _core_array_base_address(f) + i, _core_array_size(f) - i);

                                if (x == -1)
                                    return _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
                                        k(_core_Nil{}, x);
                                    });

                                auto & n = (_core_Size &) x;

                                while (true) {
                                    if (i == _core_array_size(f))
                                        return k(_core_Nil{}, _core_Nil{});

                                    auto m = _core_array_size(_core_array_base_address(f)[i]);

                                    if (n < m)
                                        break;

                                    n -= m;
                                    ++i;
                                }

                                ((_core_Pointer<_core_Octet> &) _core_array_base_address(f)[i].iov_base) += n;
                                _core_array_base_address(f)[i].iov_len -= n;

                                return restart(restart);
                            };

                            loop(loop);
                        },
                        x ...
                    );
                },
                x ...
            );
        },
        _core_base_object(x)
    );
}

};
#elif __has_include(<unistd.h>)
template<typename ... A, typename Continuation>
inline auto core_file_handle_write_(
    _core_Targets<A ...> & targets,
    _core_file_Write_only_handle & handle,
    Continuation & k
) {
    _core_apply(
        [&] (auto & ... a) {
            _core_ieee_std_1003dot1_Iovec f[] = {
                _core_ieee_std_1003dot1_iovec_from(a, _core_id) ...
            };

            for (auto i = _core_Size{0}; i != _core_array_size(f); ++i) {
                auto n = ::write(handle, _core_array_base_address(f[i]), _core_array_size(f[i]));

                if (n == -1)
                    _core_ieee_std_1003dot1_last_error([&] (auto && e, auto && x) {
                        k(x, _core_Nil{});
                    });
                else if (n == _core_array_size(f[i]))
                    k(_core_Nil{}, _core_Nil{});
                else {
                    _core_array_base_address(f[i]) += n;
                    _core_array_size(f[i]) -= n;

                    continue;
                }
            }
        },
        _core_base_object(targets)
    );
};
#endif

#endif
