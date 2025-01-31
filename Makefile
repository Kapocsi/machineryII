CC=cc
main=main
CFLAGS=

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

.PHONY: all clean

all: $(main)

clean:
	rm $(OBJS) $(main)

$(main): $(OBJS)
	$(CC) $(OBJS) -o $(main)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


