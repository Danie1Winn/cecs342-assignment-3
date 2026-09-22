// Tools and services used: geeksforgeeks.org, VS Code, Portfolio Courses (YouTube)

#include <stdio.h>
#include <stddef.h>
#include "merge_sort.h"

static void print_array(const int *a, size_t n) {
    printf("{");
    for (size_t i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i + 1 < n) {
            printf(", ");
        }
    }
    printf("}\n");
}

