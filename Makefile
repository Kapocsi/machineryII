# CC=m68k-atari-mint-gcc # Switch to these for compiling with a X-compiler
# CFLAGS=-O3 -g -mshort
CC=cc68x
CFLAGS=-O -g
FONT_OBJS=lib\unifont.o lib\depixel.o font.o
OBJS=raster.o bitmaps.o model.o events.o $(FONT_OBJS) adler32.o
MAIN=main.o

.PHONY: test clean run format


run: main	# RM Local
	main 	# RM Local

main: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $^ -o $@

test: $(OBJS) raster.t btmaps.t font.t model.t
	model.t			# RM Local
	font.t			# RM Local
	raster.t		# RM Local
	btmaps.t		# RM Local

clean:
	$(RM) *.o *.t main **/*.o lib\*.o

format:
	clang-format **/*.h **/*.c *.c *.h -i

# Test Template:
# <mod>.t: <mod test>.o lib\unit.o
#	$(CC) $(CFLAGS) $^ -o $@
#	$@							# Run the test

raster.t: $(OBJS) raster_t.o lib\unit.o
	$(CC) $(CFLAGS) $^ -o $@

btmaps.t: $(OBJS) btmaps_t.o lib\unit.o
	$(CC) $(CFLAGS) $^ -o $@

font.t: $(OBJS) font_t.o lib\unit.o
	$(CC) $(CFLAGS) $^ -o $@

model.t: $(OBJS) model_t.o lib\unit.o
	$(CC) $(CFLAGS) $^ -o $@

