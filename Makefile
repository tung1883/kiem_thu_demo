CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lm
SRC_DIR = ./src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = ./src/calculator

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
