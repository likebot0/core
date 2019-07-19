#ifndef _core_file_Write_only_handle
#define _core_file_Write_only_handle ::core_file_Write_only_handle

struct core_file_Write_only_handle;

#include <core/file/Handle.type.h>

#if __has_include(<unistd.h>)
struct core_file_Write_only_handle : _core_file_Handle {
    using Base_object = _core_file_Handle;

    using Base_object::Base_object;
};
#endif

#endif
