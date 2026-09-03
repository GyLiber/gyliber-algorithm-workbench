# C90 String Length

## Purpose

Implement string-length computation in three equivalent forms:

1. array indexing;
2. pointer traversal;
3. pointer arithmetic.

The practice demonstrates that C arrays and pointers provide different ways of expressing traversal over the same character sequence.

## Requirements

The program shall:

* accept one command-line string;
* compute its length without using the standard-library `strlen`;
* implement the operation using array indexing;
* implement the operation using pointer traversal;
* implement the operation using pointer arithmetic;
* print the result from each implementation;
* compile as ANSI C90 without warnings.

## Implementations

### Array indexing

```c
s[i]
```

The index starts at zero and increases until the null character is reached.

### Pointer traversal

```c
*s
```

The pointer is incremented after each character is examined.

Incrementing the local pointer does not modify the caller's pointer because C passes function arguments by value. The function receives its own copy of the pointer.

### Pointer arithmetic

A second pointer is advanced to the terminating null character:

```text
p = s
    ↓
advance p
    ↓
p points to '\0'
```

The difference

```c
p - s
```

is the number of characters between the two positions.

## Complexity

For a string containing \(n\) characters:

$$
T(n)=O(n)
$$

and each implementation uses:

$$
S(n)=O(1)
$$

auxiliary space.

## Build

```bash
make
```

## Test

```bash
make test
```

The test suite verifies empty strings, single-character strings, ordinary strings, strings containing spaces, and longer strings.

## Clean

```bash
make clean
```

## Learning Focus

This practice reinforces:

* character arrays;
* pointers;
* dereferencing;
* pointer increment;
* pointer subtraction;
* the null character `'\0'`;
* `for` and `while` loop equivalence;
* function parameters being local variables;
* the relationship between arrays and pointers in C.

The three implementations should be reconstructible independently from the same underlying algorithm.
