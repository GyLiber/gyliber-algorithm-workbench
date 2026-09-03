# C90 String Operations

## Purpose

Implement a small collection of fundamental C string operations using character pointers and explicit traversal.

This practice covers the string operations introduced in Tutorial 2:

* comparison;
* copying;
* suffix testing;
* duplication.

The implementations are intentionally independent of the standard-library `strcmp`, `strcpy`, `strlen`, and `strdup` functions.

## Components

### `string_length`

Computes the number of characters before the terminating null character.

The implementation uses pointer subtraction:

```c
p - s
```

### `string_compare`

Compares two strings lexicographically.

Traversal continues while corresponding characters are equal. If both strings terminate together, they are equal. Otherwise, the first differing characters determine the ordering.

The function returns:

```text
-1    first string is less
 0    strings are equal
 1    first string is greater
```

The exact numerical difference between characters is deliberately not exposed as part of this component's interface.

### `string_copy`

Copies the string, including its terminating null character, into caller-provided storage.

The destination must provide enough space for the complete string.

### `string_ends_with`

Tests whether the second string is a suffix of the first.

For strings \(s\) and \(t\), when

$$
|t| \le |s|,
$$

the comparison begins at:

$$
s + |s| - |t|.
$$

An empty suffix is therefore correctly treated as a suffix of every string.

### `string_duplicate`

Allocates enough memory for a copy of the supplied string, including the terminating null character, and copies the string into the new storage.

The caller is responsible for releasing the returned memory with `free`.

## Pointer Concepts

This practice reinforces several important C rules.

A pointer parameter is passed by value:

```c
void function(char *p)
```

The function receives its own copy of `p`. Incrementing that local pointer does not change the caller's pointer.

Pointer arithmetic operates in units of the pointed-to type:

```c
p++
```

moves to the next `char`.

Two pointers into the same character array may be subtracted:

```c
p - s
```

producing the number of elements between them.

## Memory Management

`string_duplicate` allocates memory dynamically.

Every successful allocation is paired with:

```c
free(copy);
```

in the driver program.

The allocation also reserves one additional character:

$$
|s|+1
$$

because the terminating `'\0'` must be stored.

## Complexity

For strings of lengths \(m\) and \(n\):

* `string_length`: \(O(n)\)
* `string_compare`: \(O(\min(m,n))\)
* `string_copy`: \(O(n)\)
* `string_ends_with`: \(O(m+n)\)
* `string_duplicate`: \(O(n)\)

The ordinary operations use \(O(1)\) auxiliary space, excluding the memory deliberately allocated for a duplicate string.

## Build

```bash
make
```

## Test

```bash
make test
```

The tests cover:

* equal strings;
* strings with different characters;
* prefix relationships;
* copying;
* ordinary suffixes;
* empty suffixes;
* suffixes longer than the source;
* string duplication.

## Clean

```bash
make clean
```

## Learning Focus

The primary objective is to be able to reconstruct these operations from the underlying ideas rather than memorising their source code.

The key progression is:

```text
character sequence
      ↓
pointer traversal
      ↓
pointer arithmetic
      ↓
comparison / copying
      ↓
composition of operations
      ↓
dynamic allocation
```
