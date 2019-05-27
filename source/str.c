
#include <string.h>
#include <assert.h>

#include <stdio.h>

#include "lib/str.h"
#include "lib/memory.h"
#include "lib/array.h"

char *ccn_str_cpy(const char *source) {
    assert(source != NULL);

    size_t len = strlen(source);
    char *destination = (char *)mem_alloc(len + 1);
    strcpy(destination, source);
    return destination;
}

char *ccn_str_cat(const char *first, const char *second) {
    assert(first != NULL && second != NULL);
    size_t len_first = strlen(first);
    size_t len_second = strlen(second);
    char *result = (char *)mem_alloc(len_first + len_second + 1);
    strcpy(result, first);
    strcat(result, second);
    return result;
}

bool ccn_str_equal(const char *first, const char *second) {
    return strcmp(first, second) == 0;
}


array *ccn_str_split(char *target, const char delimeter) {
    array *matches = create_array();
    char *start = target;
    char *current = target;
    size_t size = 0;
    while (*current) {
        if (*current == delimeter) {
            char *match = mem_copy(start, size + 1);
            match[size] = '\0';
            array_append(matches, match);
            size = 0;
            start = current + 1;
        } else {
            size++;
        }
        current++;
    }
    char *last_match = mem_copy(start, size + 1);
    last_match[size] = '\0';
    array_append(matches, last_match);
    return matches;
}

bool ccn_str_startswith(const char *str, const char *pre) {
    return strncmp(pre, str, strlen(pre)) == 0;
}
