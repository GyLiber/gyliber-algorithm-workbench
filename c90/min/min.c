#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * Compare two long values.
 *
 * The minimum algorithm does not call this function directly by name.
 * Instead, it receives a comparison function so that the same algorithm
 * can work with different element types and ordering rules.
 */
static int compare_long(const void *left, const void *right)
{
    const long *a;
    const long *b;

    a = (const long *)left;
    b = (const long *)right;

    if (*a < *b)
        return -1;

    if (*a > *b)
        return 1;

    return 0;
}

/*
 * Find the minimum element in an array.
 *
 * array       points to the first element.
 * count       is the number of elements.
 * element_size is the number of bytes occupied by one element.
 * compare     determines the ordering of two elements.
 *
 * The function returns a pointer to the minimum element.
 *
 * The algorithm does not know what type of element is stored in the array.
 * It moves through the array one element at a time using the supplied
 * element size and asks the comparison function which element is smaller.
 */
static const void *array_min(const void *array,
                             size_t count,
                             size_t element_size,
                             int (*compare)(const void *, const void *))
{
    const unsigned char *current;
    const unsigned char *minimum;
    size_t i;

    if (count == 0)
        return NULL;

    current = (const unsigned char *)array;
    minimum = current;

    for (i = 1; i < count; ++i) {
        current += element_size;

        if (compare(current, minimum) < 0)
            minimum = current;
    }

    return minimum;
}

int main(int argc, char *argv[])
{
    long *values;
    const long *minimum;
    int i;

    /*
     * With no command-line arguments there is no collection to process,
     * so the required behavior is simply to produce no output.
     */
    if (argc == 1)
        return 0;

    /*
     * argc - 1 is the number of integer arguments.
     * malloc is used because the number of elements is known only when
     * the program starts.
     */
    values = (long *)malloc((size_t)(argc - 1) * sizeof(long));

    if (values == NULL)
        return 1;

    /*
     * The exercise guarantees that every argument represents an integer
     * in the required range, so conversion can be performed directly.
     */
    for (i = 1; i < argc; ++i)
        values[i - 1] = strtol(argv[i], NULL, 10);

    /*
     * Specialize the generic array-minimum operation for long integers.
     */
    minimum = (const long *)array_min(
        values,
        (size_t)(argc - 1),
        sizeof(long),
        compare_long
    );

    printf("%ld\n", *minimum);

    free(values);

    return 0;
}
