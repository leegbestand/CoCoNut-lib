#pragma once

#include <stdbool.h>
#include "array.h"

extern char *ccn_str_cpy(const char *source);
extern char *ccn_str_cat(const char *first, const char *second);
extern bool ccn_str_equal(const char *first, const char *second);
extern char *ccn_str_cat_n(const int n, ...);

/* Splits a string on the given delimeter. Returns an allocated array of all
 * the sub-strings that where created. If the delimiter was not found
 * the sub-string will be the same as the target string.
 *
 * NOTE: do not forget to free the array and the strings in the array.
 */
extern array *ccn_str_split(char *target, const char delimeter);

bool ccn_str_startswith(const char *str, const char *pre);
