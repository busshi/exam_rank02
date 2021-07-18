#include <stdio.h>
#include "limits.h"

int ft_printf(const char *, ... );

int		main(void)
{
	int ret;
	int	ret2;

	ft_printf("padding : 10, precision : 2, str : toto\n");
	ret = printf("-%10.2s-\n", "toto");
	ret2 = ft_printf("-%10.2s-\n", "toto");
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : 5, str : toto\n");
	ret = printf("-%10.5s-\n", "toto");
	ret2 = ft_printf("-%10.5s-\n", "toto");
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("precision : 0, str : toto\n");
	ret = printf("-%.0s-\n", "toto");
	ret2 = ft_printf("-%.0s-\n", "toto");
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 0, precision : 4, str : NULL\n");
	ret = printf("-%.4s-\n", NULL);
	ret2 = ft_printf("-%.4s-\n", NULL);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	printf("NBR\n");
	ft_printf("padding : 10, precision : 1, nb : 42\n");
	ret = printf("-%10.1d-\n", 42);
	ret2 = ft_printf("-%10.1d-\n", 42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : 12, nb : -42\n");
	ret = printf("-%10.12d-\n", -42);
	ret2 = ft_printf("-%10.12d-\n", -42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : 0, nb : 0\n");
	ret = printf("-%10.0d-\n", 0);
	ret2 = ft_printf("-%10.0d-\n", 0);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : 5, nb : 42\n");
	ret = printf("-%10.5d-\n", 42);
	ret2 = ft_printf("-%10.5d-\n", 42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : 10, nb : -42\n");
	ret = printf("-%10.10d-\n", -42);
	ret2 = ft_printf("-%10.10d-\n", -42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 1, precision : none, nb : -42\n");
	ret = printf("-%1d-\n", -42);
	ret2 = ft_printf("-%1d-\n", -42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 1, precision : none, nb : -42\n");
	ret = printf("-%1d-\n", -42);
	ret2 = ft_printf("-%1d-\n", -42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("nb : int min\n");
	ret = printf("-%d-\n", INT_MIN);
	ret2 = ft_printf("-%d-\n", INT_MIN);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("nb : int max\n");
	ret = printf("-%d-\n", 2147483647);
	ret2 = ft_printf("-%d-\n", 2147483647);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	printf("HEX\n");
	ft_printf("padding : 10, precision : 0, nb : 0\n");
	ret = printf("-%10.0x-\n", 0);
	ret2 = ft_printf("-%10.0x-\n", 0);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : none, nb : 42\n");
	ret = printf("-%10x-\n", 42);
	ret2 = ft_printf("-%10x-\n", 42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("padding : 10, precision : none, nb : -42\n");
	ret = printf("-%10x-\n", -42);
	ret2 = ft_printf("-%10x-\n", -42);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("nb : int min\n");
	ret = printf("-%x-\n", INT_MIN);
	ret2 = ft_printf("-%x-\n", INT_MIN);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	ft_printf("nb : int max\n");
	ret = printf("-%x-\n", 2147483647);
	ret2 = ft_printf("-%x-\n", 2147483647);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);
	
	ft_printf("x: UINT_MAX\n");
	ret = printf("%x\n", UINT_MAX);
	ret2 = ft_printf("%x\n", UINT_MAX);
	printf("printf, ft_printf : %d, %d\n", ret, ret2);

	return (0);
}
