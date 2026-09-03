# Reverse an Input Collection

## Purpose

Practice storing a dynamically sized collection and traversing it in reverse
order.

The academic problem requires a specified number of signed 32-bit integers to
be read from standard input and printed in the opposite order.

## Requirements

The program shall:

* accept one positive integer as its command-line argument;
* use that value as the number of input integers;
* read exactly that many integers from standard input;
* print the integers in reverse input order;
* print one integer per line.

The input integers are separated by whitespace.

## Implementation

The program dynamically allocates an array containing the requested number
of integers.

The input values are stored in their original order.

The array is then traversed from its final index toward index zero. This
produces the reverse sequence without modifying the array and without
requiring a second array.

## Learning Focus

The important idea is that reversing a sequence does not necessarily mean
physically rearranging its elements.

If an array contains:

```text
A B C D E
```

then traversing its indices as:

```text
4 3 2 1 0
```

produces:

```text
E D C B A
```

The practice therefore reinforces the relationship between an array, its
indices, and pointer-based memory storage.

## Complexity

Reading the `n` values requires `O(n)` time.

Printing the values requires `O(n)` time.

The array requires `O(n)` storage.

The reverse traversal itself requires `O(1)` additional space.

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
$ ./reverse 10 < nums.txt
-20
27
81
-89
-14
10
58
42
0
-11
```
