# C90 Generic Quicksort

## Purpose

Implement Quicksort as a reusable sorting algorithm whose ordering is supplied through a function pointer.

The practice is based on Tutorial 2 and demonstrates the separation between:

$$
\text{sorting algorithm}
$$

and

$$
\text{ordering policy}.
$$

The algorithm itself does not determine whether elements should be ordered alphabetically, numerically, ascending, descending, or according to some other rule.

## Interface

The public interface is:

```c
void quicksort(void *array[],
              int left,
              int right,
              int (*compare)(void *, void *));
```

The comparison function determines the relative ordering of two elements.

It returns:

```text
negative    first element precedes second
zero        elements are equivalent for ordering
positive    first element follows second
```

## Implementation

The implementation uses the middle element of the current subarray as the partition element.

The partitioning process places elements less than the partition element before it and the remaining elements after it. Quicksort is then recursively applied to the two resulting subarrays.

The algorithm stops when a subarray contains fewer than two elements.

## Function Pointers

The important abstraction is:

```c
int (*compare)(void *, void *)
```

This allows the same `quicksort` implementation to operate with different comparison functions.

The demonstration supplies:

```text
string_compare
string_compare_descending
```

The sorting algorithm therefore remains unchanged while the ordering policy changes.

## Data Representation

This implementation follows the tutorial's representation:

```c
void *array[]
```

It therefore sorts an array of pointers.

For this practice, the pointers refer to command-line strings stored in `argv`.

This is different from the standard-library `qsort` interface, which accepts a pointer to a contiguous sequence of arbitrary objects together with an element size.

The important common abstraction is the comparison function.

## Complexity

For \(n\) elements, the average-case running time is:

$$
O(n\log n)
$$

The worst-case running time is:

$$
O(n^2).
$$

The implementation uses recursion, so additional stack space depends on the recursion depth.

## Build

```bash
make
```

## Test

```bash
make test
```

The test suite verifies:

* no arguments;
* one argument;
* ascending string ordering;
* descending string ordering;
* repeated values;
* already ordered input;
* reverse ordered input.

## Clean

```bash
make clean
```

## Learning Focus

This practice reinforces:

* function pointers;
* `void *`;
* generic interfaces;
* pointer arrays;
* recursive algorithms;
* partitioning;
* swapping;
* comparison functions;
* separation of algorithm and policy.

The primary goal is to be able to reconstruct the Quicksort algorithm and explain why changing the comparison function changes the ordering without changing the sorting algorithm.
