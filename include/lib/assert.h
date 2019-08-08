#pragma once
#include <stdbool.h>

#ifndef NDEBUG
#define CCNassert(assertion, ...) (_CCNassertHandler(__FILE__, __func__, __LINE__, #assertion, assertion,  __VA_ARGS__))
#else
#define CCNassert(assertion, ...) (void(0))
#endif

void _CCNassertHandler(const char *file, const char *function, unsigned int line, 
                       const char *assertion_string, bool assertion_result, const char *format, ...);