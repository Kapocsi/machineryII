CC=cc68x
CFLAGS=-O
OBJS=main.o raster.o


.PHONY: test clean
test: raster.t
	@$(ECHO) Finished Running Tests.

main: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	$(RM) *.o *.t

unity.o:
	@$(ECHO) "unity.o often fails to compile without increasing the memory limit."
	@$(ECHO) "be advised, this might fail."

	cc68x -c lib\unity.c -o unity.o

# Test Template:
# <mod>.t: <mod test>.o unity.o
#	$(CC) $< unity.o -o $@
#	$@							# Run the test

raster.t: raster.o raster_test.o unity.o
	$(CC) $^ -o $@

