# Man Over Board {#mainpage}

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
make <test suite>.t
```

To run the compiled test suite:

```sh
<test suite>.t
```

### Adding a Test Suite

Since the [Unity](https://github.com/ThrowTheSwitch/Unity) testing framework relies heavily on macros, compiling unit tests can be time-consuming. Therefore, tests are maintained separately from the implementation code.

We follow this naming convention:

```
<name>.c     # Implementation
<name>.h     # Header file for module (optional)
<name>_t.c   # Test file for module
<name>.t     # Compiled tests for module
```

If `<name>_t` exceeds 8 characters, truncate `<name>` accordingly.

### Adding Test Cases

To add a new test case, define a function within `<name>_t.c`:

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
