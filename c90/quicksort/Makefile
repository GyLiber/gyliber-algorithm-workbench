CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = quicksort
SOURCE = quicksort.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE) qsort.h
$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
@echo "Test 1: no arguments"
@test "$$(./$(TARGET))" = ""

```
@echo "Test 2: one argument"
@test "$$(./$(TARGET) apple)" = "$$(printf '%s\n' 'ascending:\napple\ndescending:\napple')"

@echo "Test 3: ascending and descending strings"
@test "$$(./$(TARGET) banana apple cherry)" = "$$(printf '%s\n' 'ascending:\napple\nbanana\ncherry\ndescending:\ncherry\nbanana\napple')"

@echo "Test 4: repeated values"
@test "$$(./$(TARGET) beta alpha beta gamma)" = "$$(printf '%s\n' 'ascending:\nalpha\nbeta\nbeta\ngamma\ndescending:\ngamma\nbeta\nbeta\nalpha')"

@echo "Test 5: reverse ordered input"
@test "$$(./$(TARGET) delta charlie bravo alpha)" = "$$(printf '%s\n' 'ascending:\nalpha\nbravo\ncharlie\ndelta\ndescending:\ndelta\ncharlie\nbravo\nalpha')"

@echo "Test 6: already ordered input"
@test "$$(./$(TARGET) alpha bravo charlie delta)" = "$$(printf '%s\n' 'ascending:\nalpha\nbravo\ncharlie\ndelta\ndescending:\ndelta\ncharlie\nbravo\nalpha')"

@echo "All tests passed."
```

clean:
rm -f $(TARGET)
