# Descending Array Sort

## Purpose

Practice sorting a dynamically allocated array using the standard C `qsort`
function and a comparison function.

The academic problem requires a specified number of integers to be read from
standard input and displayed in numerically descending order.

## Requirements

The program:

* accepts one positive integer as its command-line argument;
* uses that value as the number of input integers;
* reads the integers from standard input;
* sorts them numerically in descending order;
* prints one integer per line.

The input integers are specified to lie in the range
`[-2^63, 2^63 - 1]`.

## Implementation

The program allocates an array large enough for the requested number of
values.

Each input value is read directly into its corresponding array element.

`qsort` performs the sorting. The comparison function receives pointers to
two array elements and defines descending numerical order.

After sorting, the array is traversed from its first element to its last
element and each value is printed.

The allocated array is released with `free` before the program exits.

## Important Practice

`qsort` is not restricted to integers. Its interface receives:

```c
void *base
size_t number_of_elements
size_t element_size
int (*comparison_function)(const void *, const void *)
```

The array type and comparison function therefore determine how the generic
library sorting operation is specialized for this exercise.

## Complexity

For this practice, `qsort` is used for ordering the collection.

The sorting operation is expected to require `O(n log n)` time.

The array requires `O(n)` storage.

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

## Example

```text
$ ./sort 5 < nums.txt
91
81
58
42
27
```
