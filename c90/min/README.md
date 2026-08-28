# Minimum of an Array

## Purpose

Practice finding the minimum element of an array while separating the
minimum-selection algorithm from the representation of the elements.

The immediate academic requirement is to accept an arbitrary number of
integers as command-line arguments and print the least integer.

The implementation is deliberately more general: the minimum operation
receives an array, element count, element size, and comparison function.

## Requirement

Given zero or more integer command-line arguments:

* if no arguments are supplied, produce no output;
* otherwise print the least integer;
* accepted integers are in the interval `[-2^31, 2^31 - 1]`.

## Implementation

The reusable operation is:

```c
array_min(array, count, element_size, compare)
```

`array_min` does not assume that the elements are integers. It moves through
the array using the supplied element size and uses the supplied comparison
function to determine which element is smaller.

For this practice, `compare_long` supplies the comparison required for the
integer specialization.

The command-line arguments are converted into an array of `long` values and
that array is passed to `array_min`.

## Algorithm

1. Treat the first array element as the current minimum.
2. Move through the remaining elements.
3. Compare each element with the current minimum.
4. Replace the minimum when a smaller element is found.
5. Return the address of the minimum element.

The algorithm examines each element once.

Time complexity: `O(n)`

Auxiliary space used by the minimum-selection algorithm: `O(1)`.

The program itself uses `O(n)` storage for the command-line values.

## Build

```bash
make
```

## Test

```bash
make test
```

## Clean

```bash
make clean
```

## Examples

```text
$ ./min
$ ./min 2 3 5 7 11
2
$ ./min 31 29 23 19 17 13 11 7 5 3 2
2
$ ./min -2147483648 2147483647
-2147483648
$ ./min 2147483647 -2147483648
-2147483648
```

## Learning Focus

The main practice is not finding the smallest integer.

The main practice is learning how an array algorithm can operate on elements
without embedding a particular element type into the algorithm.

The integer problem is the first concrete specialization and test of that
interface.
