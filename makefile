CC = g++
CFLAGS = -Wall -Wextra  -pedantic -std=c++14 -Iinclude
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(SOURCES))
EXECUTABLE = bin/main

TEST_SOURCES = $(filter-out src/main.cpp, $(SOURCES)) $(wildcard test/*.cpp)
TEST_OBJECTS = $(patsubst src/%.cpp, build/%.o, $(TEST_SOURCES))
TEST_EXECUTABLE = bin/test

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

test: $(TEST_EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run-test
run-test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -f $(TEST_OBJECTS) $(TEST_EXECUTABLE)

.PHONY: clean-doc
clean-doc:
	rm -rf ./doc/*

.PHONY: doc
doc:
	doxygen Doxyfile

