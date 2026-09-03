CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = string
SOURCE = string.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
@echo "Test 1: equal strings"
@test "\((./$(TARGET) hello hello)" = "\)(printf '%s\n' 'compare: 0\ncopy: hello\nends-with: 1')"

```
@echo "Test 2: first string is less"
@test "$$(./$(TARGET) apple banana)" = "$$(printf '%s\n' 'compare: -1\ncopy: apple\nends-with: 0')"

@echo "Test 3: first string is greater"
@test "$$(./$(TARGET) banana apple)" = "$$(printf '%s\n' 'compare: 1\ncopy: banana\nends-with: 0')"

@echo "Test 4: ordinary suffix"
@test "$$(./$(TARGET) button ton)" = "$$(printf '%s\n' 'compare: 1\ncopy: button\nends-with: 1')"

@echo "Test 5: identical strings are suffixes"
@test "$$(./$(TARGET) buffer buffer)" = "$$(printf '%s\n' 'compare: 0\ncopy: buffer\nends-with: 1')"

@echo "Test 6: empty suffix"
@test "$$(./$(TARGET) hello '')" = "$$(printf '%s\n' 'compare: 1\ncopy: hello\nends-with: 1')"

@echo "Test 7: suffix longer than source"
@test "$$(./$(TARGET) cat caterpillar)" = "$$(printf '%s\n' 'compare: -1\ncopy: cat\nends-with: 0')"

@echo "Test 8: spaces in strings"
@test "$$(./$(TARGET) 'hello world' world)" = "$$(printf '%s\n' 'compare: -1\ncopy: hello world\nends-with: 1')"

@echo "All tests passed."
```

clean:
rm -f $(TARGET)
