# Median of an Input Collection

## Purpose

Practice processing an arbitrary-size collection of values using dynamic
memory allocation and `qsort`.

The academic problem used for this practice requires the median of a
collection of nonnegative integers read from standard input.

The implementation focuses on the reusable programming ideas involved:
dynamic array growth, generic ordering through a comparison function, and
selection of the middle element(s).

## Requirements

The program shall:

* read an arbitrary number of nonnegative integers from standard input;
* accept values in the range `[0, 2^32 - 1]`;
* allow values to be separated by whitespace;
* not assume the number of input values in advance;
* display no output when no values are supplied;
* display the middle value when the number of values is odd;
* display the arithmetic mean of the two middle values when the number is even;
* display one decimal place when the even-case mean is fractional.

The input is assumed to contain valid integers as specified by the exercise.

## Implementation

Input values are stored in a dynamically allocated array.

The array begins with an initial capacity and is doubled whenever the existing
capacity is reached.

`qsort` is used to order the collection. A comparison function supplies the
ordering required by `qsort`.

After sorting:

* an odd-sized collection has one middle element;
* an even-sized collection has two middle elements.

The program handles the empty collection before attempting to calculate
middle indices.

## Complexity

Let `n` be the number of input values.

Dynamic array construction requires `O(n)` total element storage.

Sorting with `qsort` is treated as `O(n log n)` for this practice.

Median selection after sorting is `O(1)`.

Overall expected time complexity: `O(n log n)`.

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

## Learning Focus

The central practice is not merely calculating a median.

The practice is to build a program that can accept an unknown amount of input,
grow its collection as necessary, order the collection using a supplied
comparison operation, and then reason about the positions required to obtain
the median.

The integer collection is the concrete specialization used to exercise these
ideas.
