#include "merge_sort.h"                             // include template header file
#include <stdlib.h>                                 // include standard library for malloc and free


// Helper function, merges adjacent sort subarrays and used pre-allocated heap buffer 'temp' to store merged results
static void merge(int *a, size_t mid, size_t n, int *temp) {
    size_t i = 0;                                   // read left subarray
    size_t j = mid;                                 // read right subarray
    size_t k = 0;                                   // write cursor for temp buffer

    // Merge small elements from left and right into temp
    while (i < mid && j < n) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    // Remove remaining elements from left
    while (i < mid) {
        temp[k++] = a[i++];
    }

    // Remove remaining elements from right
    while (j < n) {
        temp[k++] = a[j++];
    }

    // Copy sorted elements from temp back to original array
    for (size_t idx = 0; idx < n; idx++) {
        a[idx] = temp[idx];
    }
}

// 'Divide and conquer' merge sort strategy
static void merge_sort_recursive(int *a, size_t n, int *temp) {
    if (n <= 1) {                                   // trivially sort arrays with 0 to 1 elements
        return;
    }

    size_t mid = n / 2;                             // split array into two halves

    merge_sort_recursive(a, mid, temp);             // recursively sort left

    merge_sort_recursive(a + mid, n - mid, temp);   // recursively sort right

    merge(a, mid, n, temp);                         // merge sorted halves using temp buffer
}

// Allocate auxiliary memory, intiate sort
void merge_sort(int *a, size_t n) {
    if (a == NULL || n <= 1) {                      // empty, single element, or null pointer
        return;
    }

    // Dynamically allocate aux memory when on heap, avoid stack overflow
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        return;                                     // safety check for memory allocation
    }

    merge_sort_recursive(a, n, temp);               // run sort algorithm using temp buffer

    free(temp);                                     // deallocate allocated heap memory
}
