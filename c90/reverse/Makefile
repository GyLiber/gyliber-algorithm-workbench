CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = reverse
SOURCE = reverse.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
	@echo "Test 1: reverse mixed signed integers"
	@test "$$(printf '%s\n' '-11 0 42 58 10 -14 -89 81 27 -20' | \
		./$(TARGET) 10)" = "$$(printf '%s\n' '-20 27 81 -89 -14 10 58 42 0 -11')"

	@echo "Test 2: one value"
	@test "$$(printf '%s\n' '42' | ./$(TARGET) 1)" = "42"

	@echo "Test 3: already reversed input"
	@test "$$(printf '%s\n' '5 4 3 2 1' | \
		./$(TARGET) 5)" = "$$(printf '%s\n' '1 2 3 4 5')"

	@echo "Test 4: extreme signed values"
	@test "$$(printf '%s\n' '2147483647 -2147483648 0' | \
		./$(TARGET) 3)" = "$$(printf '%s\n' '0 -2147483648 2147483647')"

	@echo "Test 5: repeated values"
	@test "$$(printf '%s\n' '7 7 3 7 3' | \
		./$(TARGET) 5)" = "$$(printf '%s\n' '3 7 3 7 7')"

	@echo "All tests passed."

clean:
	rm -f $(TARGET)
