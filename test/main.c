#include <stdio.h>
#include <stddef.h>

#include "lib/str.h"
#include "lib/array.h"

int main(int argc, char **argv) {
    char *split_test = "split.on.dots";
    array *splits = ccn_str_split(split_test, '.');
    for (int i = 0; i < array_size(splits); ++i) {
        printf("Split: %s\n", (char*)array_get(splits, i));
    }

    char *catted_n = ccn_str_cat_n(3, "Hello", " World", " Catted");
    printf("%s\n", catted_n);

    array *array_string = create_array();
    for (int i = 0; i < 3; i++) {
        char *res = ccn_str_cpy("Hello ");
        array_append(array_string, res);
    }

    char *array_catted = ccn_str_cat_array(array_string);
    printf("%s\n", array_catted);

    return 0;
}
