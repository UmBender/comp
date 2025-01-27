CC = g++
CFLAGS = -std=c++20 -lm  -I. -O3
CFLAGS_DEBUG = -std=c++20 -Og -g -pedantic -Wall -Werror -I.

# Target executable
TARGET = m
TARGET_DEBUG = m-debug

# Source files
SRCS = main.cpp 
#SRCS = combined.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
OBJS_DEBUG = $(SRCS:.cpp=-debug.o)

# Default target
all: dev debug 

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%-debug.o: %.cpp
	$(CC) $(CFLAGS_DEBUG) -c $< -o $@


# Rule to link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(TARGET_DEBUG): $(OBJS_DEBUG)
	$(CC) $(OBJS_DEBUG) -o $(TARGET_DEBUG)

dev: $(TARGET)

debug: $(TARGET_DEBUG)

# Rule to clean up intermediate object files and executable
clean:
	rm -f $(OBJS) $(TARGET) $(OBJS_DEBUG) $(TARGET_DEBUG)
