# CC=m68k-atari-mint-gcc # Switch to these for compiling with a X-compiler
# CFLAGS=-O3 -g -mshort
CC=cc68x
CFLAGS=-O -g
FONT_OBJS=lib/unifont.o lib/depixel.o
OBJS=main.o raster.o bitmaps.o $(FONT_OBJS) adler32.o


main: $(OBJS)
	$(CC) $(OBJS) -o $@

test: raster.t btmaps.t
	raster.t		# RM Local
	btmaps.t		# RM Local

clean:
	$(RM) *.o *.t main **\*.o


# Test Template:
# <mod>.t: <mod test>.o lib/unity.o
#	$(CC) $(CFLAGS) $^ -o $@
#	$@							# Run the test

raster.t: raster.o raster_t.o lib/unity.o
	$(CC) $(CFLAGS) $^ -o $@


btmaps.t: bitmaps.o btmaps_t.o lib/unity.o
	$(CC) $(CFLAGS) $^ -o $@



