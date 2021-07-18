# printf test it yourself (PTYS) from Aurélien Brabant: https://github.com/aurelien-brabant/printf-test-it-yourself/

`printf test it yourself` or `PTYS` is a dead simple framework designed to **help** 42 students
that may want to test their `ft_printf` project easily in C.

**Note**: this is not a tester, it doesn't come with any built-in test suite. This is simply C code that
will help you write your own tests for your `printf`.

## Motivations

I just wanted to write some C code, so I decided to write this cool framework, because I'm a pretty simple guy.
I decided to only provide a convenient interface to test code, instead of directly providing a test suite.

That's because I think every student should at least try to think about the possible pitfalls in its code, instead of
just blindly running tests made by another and fix errors.

The goal of this framework is to let its user concentrate on *writing actual tests* instead of thinking about *how* to make a complete tester using code.
To be clear, both are pretty cool, but a framework is here to help.

## Usage

`PTYS` is just one `.c` file with its corresponding `.h` file.
What you need to make a running program is simply compiling your executable with the `.c` file.

`gcc main.c ptys.c` is all you need. Of course, you need to have your `ft_printf` function compiled or linked with these files, otherwise
it will obivously not work.

For example, you can compile the test main at `examples/example1.c` like that: `gcc -I. examples/example1.c ptys.c`. The `-I.` is required to make `example1.c` know how the `ptys.h` header can be found (that is, at the root of the repo).

### Coding a simple test suite

Let's demonstrate quickly how to write tests using `PTYS`.

The framework basically provides a total of three useful objects: two functions and one macro:

- The `ptys_setup()` function must be called before any other `PTYS` facility is used. It does some setup that is required for the test suite
to execute properly.

- The `ptys_terminate()` function must be called when all the tests have been done. It does some cleanup and prints a clean summary of
the test suite.

- The `ASSERT` macro is what actually allow you to test your `ft_printf`. You simply need to pass it a test name (make it explicit, that's better, it will be displayed in the output)
and as a second "argument", you simply have to make your printf call (without the `ft` prefix). `PTYS` will handle that by itself and will
execute the real printf and your printf, comparing their input and return values to determine if you're correct.

A really simple example, with only one test, would look like that:

```c
#include "ptys.h"

int main(void)
{
	ptys_setup();

	ASSERT("simple_test", printf("Hello world I am %d years old"), 20);

	ptys_terminate();
}
```
