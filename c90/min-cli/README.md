# C90 Command-Line Minimum

## Purpose

Find the least integer from an arbitrary number of command-line arguments without defining an array or allocating dynamic memory.

This practice implements the direct command-line specialization of the minimum operation required by the tutorial exercise.

## Requirements

The program shall:

* accept an arbitrary number of integer command-line arguments;
* assume each argument is in the range \([-2^{31}, 2^{31}-1]\);
* print the least integer to standard output;
* produce no output when no integer arguments are supplied;
* not define an array;
* not use dynamically allocated memory;
* compile as ANSI C90 without warnings.

## Implementation

The program uses the command-line argument vector `argv` directly.

The final numeric argument is used as the initial minimum. The remaining arguments are examined one at a time. Whenever a smaller value is found, it becomes the new minimum.

Only two integer variables are required:

```text
min = current minimum
i   = current argument value
```

The algorithm therefore uses constant auxiliary storage:

$$
O(1)
$$

and examines each supplied integer once:

$$
O(n)
$$

where \(n\) is the number of integer arguments.

## Example

```text
$ ./min
$ ./min 2 3 5 7 11
2
$ ./min 31 29 23 19 17 13 11 7 5 3 2
2
$ ./min -2147483648 2147483647
-2147483648
```

## Build

From this directory:

```bash
make
```

The program is compiled using ANSI C90 with strict warnings enabled.

## Test

```bash
make test
```

The test suite checks:

* no arguments;
* one argument;
* ascending input;
* descending input;
* mixed positive and negative values;
* extreme signed 32-bit values;
* repeated values.

## Clean

```bash
make clean
```

This removes the generated executable.

## Learning Focus

This practice reinforces:

* command-line argument processing;
* `argc` and `argv`;
* integer conversion with `atoi`;
* maintaining a running minimum;
* constant auxiliary space;
* avoiding unnecessary storage;
* K&R-style C programming.

The production-quality concern surrounding `atoi` is intentionally left outside the exercise requirements. For untrusted input, a checked conversion such as `strtol` is preferable.
