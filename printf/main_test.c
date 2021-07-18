#include <stdio.h>

int	ft_printf(const char *s, ...);

int	main(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = printf("This is my magnificent test !\n");
	j = ft_printf("This is my magnificent test !\n");
	

	ft_printf("\nChar * :\n");

	i = printf("S1 : %s\n", "test");
	j = ft_printf("S1 : %s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S2 : %10s\n", "test");
	j = ft_printf("S2 : %10s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S3 : %10.0s\n", "test");
	j = ft_printf("S3 : %10.0s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S4 : %1.3s\n", "test");
	j = ft_printf("S4 : %1.3s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S5 : %.5s\n", "test");
	j = ft_printf("S5 : %.5s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S7 : %1.2s\n", "test");
	j = ft_printf("S7 : %1.2s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S8 : %5.s\n", "test");
	j = ft_printf("S8 : %5.s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("S9 : %.6s\n", "test");
	j = ft_printf("S9 : %.6s\n", "test");
	printf("printf : %d,  ft_printf : %d\n\n", i, j);

	ft_printf("\nINT (but with %%d) :\n");

	i = printf("D0 : %d\n", 4);
	j = ft_printf("D0 : %d\n", 4);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D1 : %d\n", 42);
	j = ft_printf("D1 : %d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D2 : %d\n", 123456789);
	j = ft_printf("D2 : %d\n", 123456789);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D3 : %10.1d\n", 42);
	j = ft_printf("D3 : %10.1d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D4 : %10.3d\n", 42);
	j = ft_printf("D4 : %10.3d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D5 : %10.3d\n", -42);
	j = ft_printf("D5 : %10.3d\n", -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D6 : %.0d\n", 42);
	j = ft_printf("D6 : %.0d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D7 : %10d\n", -42);
	j = ft_printf("D7 : %10d\n", -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D8 : %010.10d\n", -42);
	j = ft_printf("D8 : %010.10d\n", -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D9 : %10d\n", 42);
	j = ft_printf("D9 : %10d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D10 : %010.0d\n", 42);
	j = ft_printf("D10 : %010.0d\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("D11 : %d %d\n", 2147483647, -2147483646);
	j = ft_printf("D11 : %d %d\n", 2147483647, -2147483646);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	//i = printf("D12 : %d\n", -2147483648);
	//j = ft_printf("D12 : %d\n", -2147483648);
	//printf("printf : %d,  ft_printf : %d\n\n", i, j);

/*	ft_printf("\nINT :\n");

	i = printf("I0 : %i\n", 4);
	j = ft_printf("I0 : %i\n", 4);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I1 : %010i\n", 42);
	j = ft_printf("I1 : %010i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I2 : %i\n", 123456789);
	j = ft_printf("I2 : %i\n", 123456789);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I3 : %10.1i\n", 42);
	j = ft_printf("I3 : %10.1i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I4 : %10.3i\n", 42);
	j = ft_printf("I4 : %10.3i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I5 : %-10.3i\n", -42);
	j = ft_printf("I5 : %-10.3i\n", -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I6 : %.0i\n", 42);
	j = ft_printf("I6 : %.0i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I7 : %02.4i\n", -42);
	j = ft_printf("I7 : %02.4i\n", -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I8 : %10i\n", 42);
	j = ft_printf("I8 : %10i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I9 : %3.2i\n", 42);
	j = ft_printf("I9 : %3.2i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I10 : %i\n", 42);
	j = ft_printf("I10 : %i\n", 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I11 : %i\n", 2147483647);
	j = ft_printf("I11 : %i\n", 2147483647);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	//i = printf("I12 : %i\n", -2147483648);
	//j = ft_printf("I12 : %i\n", -2147483648);
	//printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I13 : %*.*i\n", -12, 4, -42);
	j = ft_printf("I13 : %*.*i\n", -12, 4, -42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I14 : %5.0i\n", 0);
	j = ft_printf("I14 : %5.0i\n", 0);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I15 : %5.2i\n", 0);
	j = ft_printf("I15 : %5.2i\n", 0);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("I16 : %5i\n", 0);
	j = ft_printf("I16 : %5i\n", 0);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
*/
	ft_printf("\nHexadecimal :\n");

	i = printf("xX0 : %x%x\n", 42, 42);
	j = ft_printf("xX0 : %x%x\n", 42, 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX1 : %.3x %.4x\n", 0, 10);
	j = ft_printf("xX1 : %.3x %.4x\n", 0, 10);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX2 : %10.5x %5.2x\n", 42, 42);
	j = ft_printf("xX2 : %10.5x %5.2x\n", 42, 42);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX3 : %16.6x %16.6x\n", 2048, 2048);
	j = ft_printf("xX3 : %16.6x %16.6x\n", 2048, 2048);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX4 : %.1x %.1x\n", 42, 0);
	j = ft_printf("xX4 : %.1x %.1x\n", 42, 0);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX5 : %x %x\n", 2147483647, 147483647);
	j = ft_printf("xX5 : %x %x\n", 2147483647, 147483647);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX6 : %1.1x %1.1x\n", 2147483647, 147483647);
	j = ft_printf("xX6 : %1.1x %1.1x\n", 2147483647, 147483647);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);
//	i = printf("xX7 : %.s %1.1x %.s %1.1x\n", "", -2147483647, -1, "", -2147483647);
//	j = ft_printf("xX7 : %.s %1.1x %.s %1.1x\n", "", -2147483647, -1, "", -2147483647);
//	printf("printf : %d,  ft_printf : %d\n\n", i, j);
	i = printf("xX8 : %13.x %13.x\n", 752086341, 52086341);
	j = ft_printf("xX8 : %13.x %13.x\n", 752086341, 52086341);
	printf("printf : %d,  ft_printf : %d\n\n", i, j);

	return (0);
}
