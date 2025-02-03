CC=cc68x
CFLAGS=-O

OBJS=main.o raster.o

main: $(OBJS)
	$(CC) $(OBJS) -o main



