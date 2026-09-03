CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = sort
SOURCE = sort.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
	@echo "Test 1: descending order"
	@test "$$(printf '%s\n' '-11 0 42 58 10 -14 -89 91 81 27 -20' | \
		./$(TARGET) 11)" = "$$(printf '%s\n' '91 81 58 42 27 10 0 -11 -14 -20 -89')"

	@echo "Test 2: already descending"
	@test "$$(printf '%s\n' '5 4 3 2 1' | \
		./$(TARGET) 5)" = "$$(printf '%s\n' '5 4 3 2 1')"

	@echo "Test 3: ascending input"
	@test "$$(printf '%s\n' '1 2 3 4 5' | \
		./$(TARGET) 5)" = "$$(printf '%s\n' '5 4 3 2 1')"

	@echo "Test 4: duplicate values"
	@test "$$(printf '%s\n' '7 3 7 1 3' | \
		./$(TARGET) 5)" = "$$(printf '%s\n' '7 7 3 3 1')"

	@echo "Test 5: extreme long values"
	@test "$$(printf '%s\n' '9223372036854775807 -9223372036854775808 0' | \
		./$(TARGET) 3)" = "$$(printf '%s\n' '9223372036854775807 0 -9223372036854775808')"

	@echo "All tests passed."

clean:
	rm -f $(TARGET)
