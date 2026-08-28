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
	@output=$$(./$(TARGET)); test -z "$$output"

	@echo "Test 2: increasing integers"
	@test "$$(./$(TARGET) 2 3 5 7 11 13 17 19 23 29 31)" = "2"

	@echo "Test 3: decreasing integers"
	@test "$$(./$(TARGET) 31 29 23 19 17 13 11 7 5 3 2)" = "2"

	@echo "Test 4: INT_MIN and INT_MAX"
	@test "$$(./$(TARGET) -2147483648 2147483647)" = "-2147483648"

	@echo "Test 5: INT_MAX and INT_MIN"
	@test "$$(./$(TARGET) 2147483647 -2147483648)" = "-2147483648"

	@echo "All tests passed."

clean:
	rm -f $(TARGET)
