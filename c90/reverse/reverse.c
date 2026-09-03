#include <stdio.h>
#include <stdlib.h>

static int read_count(const char *text, int *count);

int main(int argc, char *argv[])
{
    int *numbers;
    int count;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number-of-integers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (read_count(argv[1], &count) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    numbers = malloc((size_t)count * sizeof(*numbers));

    if (numbers == NULL) {
        fprintf(stderr, "%s: memory allocation failed\n", argv[0]);
        return EXIT_FAILURE;
    }

    /*
     * Store the input in its original order.
     * scanf needs the address of each array element so that it can
     * write the converted integer into that element.
     */
    for (i = 0; i < count; ++i)
        scanf("%d", &numbers[i]);

    /*
     * The array does not need to be changed to reverse the sequence.
     * Starting at the final index and moving toward index zero produces
     * the values in reverse input order.
     */
    for (i = count - 1; i >= 0; --i)
        printf("%d\n", numbers[i]);

    free(numbers);

    return EXIT_SUCCESS;
}

/*
 * Convert the command-line count to an int.
 *
 * The exercise guarantees a positive 32-bit integer, so this function
 * keeps the validation limited to the condition that matters here:
 * the supplied count must be positive.
 */
static int read_count(const char *text, int *count)
{
    int value;

    value = atoi(text);

    if (value <= 0) {
        fprintf(stderr, "number of integers must be positive\n");
        return EXIT_FAILURE;
    }

    *count = value;

    return EXIT_SUCCESS;
}
