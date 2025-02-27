# CC=m68k-atari-mint-gcc # Switch to these for compiling with a X-compiler
# CFLAGS=-O3 -g -mshort
CC=cc68x
CFLAGS=-O -g
FONT_OBJS=lib\unifont.o lib\depixel.o
OBJS=raster.o bitmaps.o $(FONT_OBJS) adler32.o
MAIN=main.o

.PHONY: test clean run

run: main	# RM Local
	main 	# RM Local

main: $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o $@

test: $(OBJS) raster.t btmaps.t
	raster.t		# RM Local
	btmaps.t		# RM Local

clean:
	$(RM) *.o *.t main **/*.o lib\*.o

# Test Template:
# <mod>.t: <mod test>.o lib/unity.o
#	$(CC) $(CFLAGS) $^ -o $@
#	$@							# Run the test

raster.t: $(OBJS) raster_t.o lib\unity.o
	$(CC) $(CFLAGS) $^ -o $@


btmaps.t: $(OBJS) btmaps_t.o lib\unity.o
	$(CC) $(CFLAGS) $^ -o $@



