# Compiler
CC = gcc

# Compilation options
CFLAGS = -Wall -g

# Name of the target executable file
TARGET = a.out

# List of source files
SRCS = c_math_question.c ../utils.c

# Automatically derive the list of object files (replace.c suffix of source files with.o suffix)
OBJS = $(SRCS:.c=.o)

# Default target, usually to generate the executable file
all: $(TARGET)

# Rule to generate the executable file
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to generate object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target, used to delete generated object files and executable file
clean:
	rm -f $(OBJS) $(TARGET)
