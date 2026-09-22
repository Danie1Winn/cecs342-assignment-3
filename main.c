// Tools and services used: geeksforgeeks.org, VS Code, Portfolio Courses (YouTube)

#include <stdio.h>
#include <stddef.h>
#include "merge_sort.h"

// Helper function to print array in provided format
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

// Log input, perform merge sort, log output
static void run_test(int *a, size_t n) {
    printf("Input: ");
    print_array(a, n);

    merge_sort(a, n);

    prinf("Sorted: ");
    print_array(a, n);
}