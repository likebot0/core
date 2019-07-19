#define _core_preprocessor_lambda_arg5(type, a, ...) type a
#define _core_preprocessor_lambda_arg4(type, a, ...) type a __VA_OPT__(, _core_preprocessor_lambda_arg5(type, __VA_ARGS__))
#define _core_preprocessor_lambda_arg3(type, a, ...) type a __VA_OPT__(, _core_preprocessor_lambda_arg4(type, __VA_ARGS__))
#define _core_preprocessor_lambda_arg2(type, a, ...) type a __VA_OPT__(, _core_preprocessor_lambda_arg3(type, __VA_ARGS__))
#define _core_preprocessor_lambda_arg1(type, a, ...) type a __VA_OPT__(, _core_preprocessor_lambda_arg2(type, __VA_ARGS__))

#ifndef _core_preprocessor_lambda
#define _core_preprocessor_lambda(...) [] (__VA_OPT__(_core_preprocessor_lambda_arg1(auto &, __VA_ARGS__)))

#endif
