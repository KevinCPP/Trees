CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Wextra -Werror

SRC_DIR = src
TEST_DIR = test

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

PROGRAM = main

.PHONY: all clean test

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

unittest: $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PROGRAM) $(OBJS) $(TEST_OBJS)
