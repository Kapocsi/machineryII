CC=cc68x
main=main
CFLAGS=-O -fc++-comments

SRCS=*.c
OBJS=$(main).o

.PHONY: all clean

$(main): $(OBJS)
	$(CC) $(OBJS) -o $(main)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	delete $(OBJS) $(main)
