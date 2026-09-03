CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = min
SOURCE = min.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
@echo "Test 1: no arguments"
@test "$$(./$(TARGET))" = ""

```
@echo "Test 2: one argument"
@test "$$(./$(TARGET) 42)" = "42"

@echo "Test 3: ascending input"
@test "$$(./$(TARGET) 1 2 3 4 5)" = "1"

@echo "Test 4: descending input"
@test "$$(./$(TARGET) 5 4 3 2 1)" = "1"

@echo "Test 5: mixed signed integers"
@test "$$(./$(TARGET) 8 -3 17 0 -11 4)" = "-11"

@echo "Test 6: extreme signed 32-bit values"
@test "$$(./$(TARGET) -2147483648 2147483647)" = "-2147483648"

@echo "Test 7: reversed extreme values"
@test "$$(./$(TARGET) 2147483647 -2147483648)" = "-2147483648"

@echo "Test 8: repeated minimum"
@test "$$(./$(TARGET) 7 2 5 2 9)" = "2"

@echo "All tests passed."
```

clean:
rm -f $(TARGET)
