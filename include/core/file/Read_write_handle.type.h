#ifndef _core_file_Read_write_handle
#define _core_file_Read_write_handle ::core_file_Read_write_handle

struct core_file_Read_write_handle;

#include <core/file/Handle.type.h>

#if __has_include(<unistd.h>)
struct core_file_Read_write_handle : _core_file_Handle {
    using Base_object = _core_file_Handle;

    using Base_object::Base_object;
};
#endif

#endif
