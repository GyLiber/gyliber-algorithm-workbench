#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int min;

    if (argc > 1) {
        min = atoi(argv[--argc]);

        while (--argc) {
            i = atoi(argv[argc]);

            if (i < min)
                min = i;
        }

        printf("%d\n", min);
    }

    return EXIT_SUCCESS;
}
