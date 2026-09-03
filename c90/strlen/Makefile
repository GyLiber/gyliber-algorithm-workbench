CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = strlen
SOURCE = strlen.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
@echo "Test 1: empty string"
@test "\((./$(TARGET) '')" = "\)(printf '%s\n' '0 0 0')"

```
@echo "Test 2: one character"
@test "$$(./$(TARGET) a)" = "$$(printf '%s\n' '1 1 1')"

@echo "Test 3: ordinary string"
@test "$$(./$(TARGET) hello)" = "$$(printf '%s\n' '5 5 5')"

@echo "Test 4: string containing spaces"
@test "$$(./$(TARGET) 'Hello world')" = "$$(printf '%s\n' '11 11 11')"

@echo "Test 5: longer string"
@test "$$(./$(TARGET) 'The quick brown fox')" = "$$(printf '%s\n' '19 19 19')"

@echo "All tests passed."
```

clean:
rm -f $(TARGET)
