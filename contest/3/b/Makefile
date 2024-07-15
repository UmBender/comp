CC = g++
CFLAGS = -std=c++17 -lm -g -Og

# Target executable
TARGET = main 

# Source files
SRCS = main.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to clean up intermediate object files and executable
clean:
	rm -f $(OBJS) $(TARGET) 
