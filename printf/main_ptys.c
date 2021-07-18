#include <stdio.h>
#include "limits.h"

#include "ptys.h"

int	main(void)
{
	ptys_setup();

	ASSERT("simple_string_literal", printf("Hello world"));
	ASSERT("conv_x", printf("%x %x %x", 42, 84, 21));
	ASSERT("conv_s", printf("hey %s %s hey", "ho", "ha"));
	ASSERT("conv_d", printf("I am %d years old", 20));

	ASSERT("conv_s1", printf("S1 : %s\n", "test"));
	ASSERT("conv_s2", printf("S2 : %10.0s\n", "test"));
	ASSERT("conv_s3", printf("S3 : %.5s\n", "test"));
	ASSERT("conv_s4", printf("S4 : %1.2s\n", "test"));
	ASSERT("conv_s5", printf("S5 : %5.s\n", "test"));
	ASSERT("conv_s6", printf("S6 : %.6s\n", "test"));

	ASSERT("conv_d1", printf("%d\n", 4));
	ASSERT("conv_d2", printf("%d\n", 42));
	ASSERT("conv_d3", printf("%d\n", 123456789));
	ASSERT("conv_d4", printf("%10.1d\n", 42));
	ASSERT("conv_d5", printf("%10.3d\n", 42));
	ASSERT("conv_d6", printf("%10.3d\n", -42));
	ASSERT("conv_d7", printf("%.0d\n", 42));
	ASSERT("conv_d8", printf("%10d\n", -42));
	ASSERT("conv_d9", printf("%010.10d\n", -42));
	ASSERT("conv_d10", printf("%10d\n", 42));
	ASSERT("conv_d11", printf("%010.0d\n", 42));
	ASSERT("conv_d12", printf("%d %d\n", 2147483647, -2147483646));
	ASSERT("conv_d13", printf("%d\n", -214748364));
	ASSERT("conv_d14", printf("%d %d\n", INT_MAX, INT_MIN));

	ASSERT("conv_x1", printf("%x%x\n", 42, 42));
	ASSERT("conv_x2", printf("%.3x %.4x\n", 0, 10));
	ASSERT("conv_x3", printf("%10.5x %5.2x\n", 42, 42));
	ASSERT("conv_x4", printf("%16.6x %16.6x\n", 2048, 2048));
	ASSERT("conv_x5", printf("%.1x %.1x\n", 42, 0));
	ASSERT("conv_x6", printf("%x %x\n", 2147483647, 147483647));
	ASSERT("conv_x7", printf("%1.1x %1.1x\n", 2147483647, 147483647));
	ASSERT("conv_x8", printf("%13.x %13.x\n", 752086341, 52086341));
	//ASSERT("conv_x9: INT_MIN", printf("%x %13.x\n", INT_MIN, INT_MIN));
	//ASSERT("conv_x11: INT_MAX + 1", printf("%x\n", INT_MAX + 1));
	//ASSERT("conv_x11: -8000", printf("%x\n", -8000));
	ASSERT("x_UINT_MAX", printf("%x\n", UINT_MAX));
	ASSERT("x_UINT_MIN", printf("%x\n", 0));

//	ASSERT("double pourcentage", printf("%%"));
	//ASSERT("%", printf("%"));
	//ASSERT("%5", printf("%5"));
	//ASSERT("%05", printf("%05"));

	ptys_terminate();

	return (0);
}
