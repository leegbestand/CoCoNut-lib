#include "lib/str.h"
#include <stdio.h>
int main(int argc, char **argv) {
    char *split_test = "split.on.dots";
    array *splits = ccn_str_split(split_test, '.');
    for (int i = 0; i < array_size(splits); ++i) {
        printf("Split: %s\n", (char*)array_get(splits, i));
    }
    return 0;
}
