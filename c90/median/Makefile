CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra -Wconversion
TARGET = median
SOURCE = median.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

test: $(TARGET)
	@echo "Test 1: empty input"
	@test -z "$$(printf '' | ./$(TARGET))"

	@echo "Test 2: odd number of values"
	@test "$$(printf '11 0\n42\n15889\n12 10\n14\n33013\n65535\n91 81\n' | ./$(TARGET))" = "42"

	@echo "Test 3: even number of values with fractional median"
	@test "$$(printf '11 0\n42\n15889\n12 10\n43 14\n33013\n65535\n91 81\n' | ./$(TARGET))" = "42.5"

	@echo "Test 4: even number of values with integral median"
	@test "$$(printf '11 0\n42\n15889\n12 10\n44 14\n33013\n65535\n91 81\n' | ./$(TARGET))" = "43"

	@echo "Test 5: extreme values"
	@test "$$(printf '4294967295 0\n' | ./$(TARGET))" = "2147483647.5"

	@echo "Test 6: repeated values"
	@test "$$(printf '7 7 7 7 7\n' | ./$(TARGET))" = "7"

	@echo "Test 7: reverse order"
	@test "$$(printf '9 8 7 6 5 4 3 2 1\n' | ./$(TARGET))" = "5"

	@echo "All tests passed."

clean:
	rm -f $(TARGET)
