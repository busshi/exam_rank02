#include <stdarg.h> /* for the ft_printf wrapper */

#include "ptys.h"

/*
** bad ft_printf implementation just to demonstrate the framework
** you'll need to compile your tester with YOUR ft_printf do not include
** that code :)
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	int ret = vprintf(fmt, ap);
	va_end(ap);
	/* an easy way to simulate failure is to add or subtract to the return value. */
	return (ret); 
}

int	main(void)
{
	ptys_setup();

	ASSERT("simple_string_literal", printf("Hello world"));
	ASSERT("conv_x", printf("%x %x %x", 42, 84, 21));
	ASSERT("conv_s", printf("hey %s %s hey", "ho", "ha"));
	ASSERT("conv_d", printf("I am %d years old", 20));

	ptys_terminate();

	return (0);
}