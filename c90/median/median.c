#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define INITIAL_CAPACITY 16

static int uint_compare(const void *left, const void *right);
static int read_numbers(unsigned int **numbers, size_t *count);
static int grow_array(unsigned int **numbers, size_t *capacity);

int main(void)
{
    unsigned int *numbers;
    size_t count;
    size_t middle;
    double median;

    numbers = NULL;
    count = 0;

    if (read_numbers(&numbers, &count) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    /*
     * There is no median when the input collection is empty.
     * The exercise requires no output in this case.
     */
    if (count == 0) {
        free(numbers);
        return EXIT_SUCCESS;
    }

    qsort(numbers, count, sizeof(*numbers), uint_compare);

    middle = count >> 1;

    if (count & 1) {
        /*
         * An odd-sized sorted collection has one element exactly
         * in the middle.
         */
        printf("%u\n", numbers[middle]);
    } else {
        /*
         * An even-sized collection has two middle elements.
         * Convert before adding so the addition cannot overflow
         * as an unsigned int.
         */
        median = ((double)numbers[middle - 1] +
                  (double)numbers[middle]) / 2.0;

        /*
         * The two middle values have an integral mean when their
         * difference is even; otherwise the mean ends in .5.
         */
        if ((numbers[middle] - numbers[middle - 1]) & 1)
            printf("%.1f\n", median);
        else
            printf("%.0f\n", median);
    }

    free(numbers);

    return EXIT_SUCCESS;
}

static int read_numbers(unsigned int **numbers, size_t *count)
{
    unsigned int number;
    size_t capacity;

    capacity = INITIAL_CAPACITY;

    *numbers = malloc(capacity * sizeof(**numbers));

    if (*numbers == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        return EXIT_FAILURE;
    }

    while (scanf("%u", &number) == 1) {
        if (*count == capacity) {
            if (grow_array(numbers, &capacity) != EXIT_SUCCESS) {
                free(*numbers);
                *numbers = NULL;
                return EXIT_FAILURE;
            }
        }

        (*numbers)[*count] = number;
        ++(*count);
    }

    return EXIT_SUCCESS;
}

static int grow_array(unsigned int **numbers, size_t *capacity)
{
    unsigned int *new_numbers;
    size_t new_capacity;

    new_capacity = *capacity << 1;

    new_numbers = realloc(*numbers,
                          new_capacity * sizeof(**numbers));

    if (new_numbers == NULL) {
        fprintf(stderr, "memory reallocation failed\n");
        return EXIT_FAILURE;
    }

    *numbers = new_numbers;
    *capacity = new_capacity;

    return EXIT_SUCCESS;
}

static int uint_compare(const void *left, const void *right)
{
    const unsigned int *a;
    const unsigned int *b;

    a = (const unsigned int *)left;
    b = (const unsigned int *)right;

    if (*a < *b)
        return -1;

    if (*a > *b)
        return 1;

    return 0;
}
