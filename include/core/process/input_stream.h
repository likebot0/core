#ifndef _core_process_input_stream
#define _core_process_input_stream ::core_process_input_stream

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_process_input_stream, core_process_input_stream_);

#include <core/file/Read_only_handle.type.h>

#if __has_include(<unistd.h>)
extern "C" {

#include <unistd.h>

}
#endif

#if __has_include(<unistd.h>)
template<typename Continuation>
inline constexpr auto core_process_input_stream_<
    Continuation
> = [] (
    auto & k
) {
    k(_core_file_Read_only_handle{STDIN_FILENO});
};
#endif

#endif
