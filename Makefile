# CC=m68k-atari-mint-gcc # Switch to these for compiling with a X-compiler
# CFLAGS=-O3 -g -mshort
CC=cc68x
CFLAGS=-g -I include
FONT_OBJS=src\unifont.o src\depixel.o src\font.o
OBJS=src\raster.o src\bitmaps.o src\model.o src\events.o \
	$(FONT_OBJS) src\adler32.o src\screen.o src\isr.s src\input.o
MAIN=src\main.o

.PHONY: test clean run format


# run: main	# RM Local
# 	main 	# RM Local

main: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $^ -o $@

test: $(objs) test\raster.prg test\bitmaps.prg test\font.prg test\model.prg
	test\raster.prg # RM Local
	test\bitmaps.prg # RM Local
	test\font.prg # RM Local
	test\model.prg # RM Local

clean:
	$(RM) *.o src\*.o test\*.o test\*.prg *.prg main

format:
	clang-format **/*.h **/*.c *.c *.h -i

# Test Template:
# test\<mod>: test\<mod test>.o src\unit.o
#	$(CC) $(CFLAGS) $^ -o $@
#	$@							# Run the test

test\raster.prg: $(OBJS) test\raster.o src\unit.o
	$(CC) $(CFLAGS) $^ -o $@

test\bitmaps.prg: $(OBJS) test\bitmaps.o src\unit.o
	$(CC) $(CFLAGS) $^ -o $@

test\font.prg: $(OBJS) test\font.o src\unit.o
	$(CC) $(CFLAGS) $^ -o $@

test\model.prg: $(OBJS) test\model.o src\unit.o
	$(CC) $(CFLAGS) $^ -o $@

