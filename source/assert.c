#include "lib/assert.h"
#include "lib/color.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static void printAssertHeader()
{
    PRINT_COLOR(BRIGHT_RED);
    fprintf(stderr, "[ASSERT] ");
    PRINT_COLOR(RESET_COLOR);

}

void _CCNassertHandler(const char *file, const char *function, unsigned int line, 
                       const char *assertion_string, bool assertion_result, const char *format, ...)
{
    if (assertion_result) return;

    printAssertHeader();
    fprintf(stderr, "Assertion failed: ");

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    fputc('\n', stderr);
    va_end(args);

    printAssertHeader(); 
    fprintf(stderr, "Expected: %s\n", assertion_string);

    printAssertHeader();
    fprintf(stderr, "Location: %s:%d in function: %s\n", file, line, function);
    abort();
}