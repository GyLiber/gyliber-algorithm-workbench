# Minimum of an Array

## Purpose

Practice finding the minimum element of an array while separating the
minimum-selection algorithm from the representation of the elements.

The immediate academic requirement is to accept an arbitrary number of
integers as command-line arguments and print the least integer.

The implementation is deliberately more general: the minimum operation
receives an array, element size, element count, and comparison function.

## Requirement

Given zero or more integer command-line arguments:

- if no arguments are supplied, produce no output;
- otherwise print the least integer;
- accepted integers are in the interval

  `[-2^31, 2^31 - 1]`.

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

```bash
./min 2 3 5 7 11
2

./min 31 29 23 19 17 13 11 7 5 3 2
2

./min -2147483648 2147483647
-2147483648
```

## Learning Focus

The important practice is not the integer comparison itself.

The important practice is learning how an array algorithm can operate on
elements without embedding a particular element type into the algorithm.

The integer problem is the first concrete specialization of that interface.