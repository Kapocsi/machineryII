# Man Over Board {#mainpage}

[Docs](https://docs.kapocsi.ca)

## Cloneing

This project uses submodules for some external dependencies, while they are not
required for the the main game, it is recomened that you clone the aswell.

```sh
git clone --recurse-submodules git@github.com:Kapocsi/machineryII.git
# or
git clone --recurse-submodules https://github.com/Kapocsi/machineryII.git
```

## Compiling

To compile and run the main game:

```sh
make run
```

## Testing

All tests can be built and run using the provided Makefile:

```sh
make test
```

To build an individual test suite:

```sh
make test/<suite>
```

To run the compiled test suite:

```sh
test/<suite>
```

### Adding a Test Suite

1. Add a file with the same name as the module in `test` ie tests for `raster.c`
   will live in `test/raster.c`
2. Use the following template to add a entry to the Makefile

```make
test\mod.prg: test\mod.o src\unit.o
    $(CC) $(CFLAGS) $^ -o $@
    $@							# Run the test
```

3. Register the test in Makefile, by adding the test both as a dep and as build
   step for `test`

```make
test: $(objs) test\mod.prg # other tests ...
    test\mod.prg
    # other tests...
```

### Adding Test Cases

In `test\<module>.c` add function to test the given function:

```c
void test_<function_name>() {
    // Assertions verifying expected behavior of <function_name>
}
```

Then register this test in the suite’s main function:

```c
int main() {
    UNITY_BEGIN();

    // Run individual tests
    RUN_TEST(test_<function_name>);

    UNITY_END();
}
```
