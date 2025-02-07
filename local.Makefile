TEST=$(wildcard *_test.c)


%_test: %.o %_test.o unity.o
	 $(CC) $(CFLAGS) $^ -o $@
