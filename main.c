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

int main(void) {
    // Assignment output format
    printf("CECS 342 Assignment 3\n");
    printf("Name: Daniel Winn\n");
    printf("Algorithm: merge sort, Language: C\n");

    // First test: Empty
    int arr1[] = {0};
    run_test(arr1, 0);

    // Second test: Single element
    int arr2[] = {1};
    run_test(arr2, 1);

    // Third test: Reverse sort
    int arr3[] = {3, 2, 1};
    run_test(arr3, 3);

    // Fourth test: Mixed array w/ duplicates, negative, large integers
    int arr4[] = {102, -43, 5, 645, 4, 34, -6, 776, 445, 45};
    size_t len4 = sizeof(arr4) / sizeof(arr4[0]);
    run_test(arr4, len4);

    return 0;
}