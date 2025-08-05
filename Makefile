TARGET = gshell
SRC = main.c 
CFLAGS = -Wall -Wextra 
CC = gcc
LINKERS = -lX11

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LINKERS)

clean:
	rm -f $(TARGET)
