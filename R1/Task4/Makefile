CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = add_program

# Object files
OBJS = Task4main.o Task4other.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

Task4main.o: Task4main.c Task4Header.h
	$(CC) $(CFLAGS) -c Task4main.c

Task4other.o: Task4other.c Task4Header.h
	$(CC) $(CFLAGS) -c Task4other.c

clean:
	rm -f *.o $(TARGET)
