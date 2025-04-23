# Get all .c files in the current directory
SRCS = $(wildcard *.c)

# Create .o files from .c files
OBJS = $(SRCS:.c=.o)

# Output program name
TARGET = program

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	gcc -o $(TARGET) $(OBJS)

# Rule to compile each .c to .o
%.o: %.c
	gcc -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
