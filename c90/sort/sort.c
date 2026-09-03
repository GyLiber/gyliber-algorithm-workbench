#include <stdio.h>
#include <stdlib.h>

static int long_compare_descending(const void *left, const void *right);

int main(int argc, char *argv[])
{
    long *numbers;
    long count;
    long i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number-of-integers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    count = atol(argv[1]);

    numbers = malloc((size_t)count * sizeof(*numbers));

    if (numbers == NULL) {
        fprintf(stderr, "%s: memory allocation failed\n", argv[0]);
        return EXIT_FAILURE;
    }

    /*
     * scanf writes each converted value directly into the array element.
     * The address is required because scanf must modify that element.
     */
    for (i = 0; i < count; ++i)
        scanf("%ld", &numbers[i]);

    /*
     * qsort does not know how long values should be ordered.
     * The comparison function supplies that ordering.
     */
    qsort(numbers,
          (size_t)count,
          sizeof(*numbers),
          long_compare_descending);

    for (i = 0; i < count; ++i)
        printf("%ld\n", numbers[i]);

    free(numbers);

    return EXIT_SUCCESS;
}

/*
 * qsort expects a comparison function receiving pointers to two elements.
 *
 * Returning a negative value places left before right.
 * Returning a positive value places left after right.
 *
 * Reversing the normal comparison gives descending order.
 */
static int long_compare_descending(const void *left, const void *right)
{
    const long *a;
    const long *b;

    a = (const long *)left;
    b = (const long *)right;

    if (*a > *b)
        return -1;

    if (*a < *b)
        return 1;

    return 0;
}
