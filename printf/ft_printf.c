#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flag
{
	int	precision;
	int	width;
}		t_flag;

int	in_charset(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (ft_isdigit(s[i]))
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	return (ret);
}

int	get_width(t_flag *flags, const char *s)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(s);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int	get_precision(t_flag *flags, const char *s)
{
	int	i;

	i = 0;
	flags->precision = ft_atoi(s);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int	check_flags(t_flag *flags, const char *s)
{
	int	i;

	i = 1;
	flags->precision = -1;
	flags->width = 0;
	while (in_charset("0123456789.", s[i]))
	{
		if (ft_isdigit(s[i]))
		{
			i += get_width(flags, s + i);
		}
		else if (s[i] == '.')
		{
			i++;
			i += get_precision(flags, s + i);
		}
	}
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnchar(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(STDOUT_FILENO, &c, 1);
		i++;
	}
	return (i);
}

int	print_s(va_list param, t_flag *flags)
{
	int	len;
	int	i;
	int	j;
	char	*s;

	s = (char *)va_arg(param, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	i = 0;
	if (flags->width > len)
		i += ft_putnchar(' ', flags->width - len);
	j = 0;
	while (j < len)
	{
		write(STDOUT_FILENO, &s[j], 1);
		j++;
	}
	return (i + j);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char	c;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(STDOUT_FILENO, &c, 1);
	}
}

int	ft_nblen(int nb)
{
	int	len;
	unsigned int	n;

	len = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_d(va_list param, t_flag *flags)
{
	int	len_d;
	int	i;
	int	len;
	int	n;

	n = (int)va_arg(param, int);
	if (n < 0)
		flags->width--;
	len_d = ft_nblen(n);
	len = len_d;
	if (flags->precision > len)
		len = flags->precision;
	i = 0;
	if (flags->precision == 0 && n == 0)
	{
		i += ft_putnchar(' ', flags->width);
		return (i);
	}
	if (flags->width > len)
		i += ft_putnchar(' ', flags->width - len);
	if (n < 0)
	{
		i++;
		write(STDOUT_FILENO, "-", 1);
	}
	if (flags->precision > len_d)
		i += ft_putnchar('0', flags->precision - len_d);
	ft_putnbr(n);
	return (i + len_d);

}

int	ft_hexlen(unsigned int x)
{
	int	len;

	len = 1;
	if (x == 0)
		return (1);
	while (x >= 16)
	{
		x /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbrbase(unsigned int x, const char *base)
{
	if (x > 16)
	{
		ft_putnbrbase(x / 16, base);
		ft_putnbrbase(x % 16, base);
	}
	else
		write(STDOUT_FILENO, &base[x], 1);
}

int	print_x(va_list param, t_flag *flags)
{
	int	len_x;
	int	len;
	int	i;
	unsigned int	x;

	x = (unsigned int)va_arg(param, unsigned int);
	len_x = ft_hexlen(x);
	len = len_x;
	i = 0;
	if (flags->precision > len)
		len = flags->precision;
	if (flags->precision == 0 && x == 0)
	{
		i += ft_putnchar(' ', flags->width);
		return (i);
	}
	if (flags->width > len)
		i += ft_putnchar(' ', flags->width - len);
	if (flags->precision > len_x)
		i += ft_putnchar('0', flags->precision - len_x);
	ft_putnbrbase(x, "0123456789abcdef");
	return (i + len_x);
}

int	check_conv(va_list param, t_flag *flags, const char *s)
{
	int	ret;

	ret = 0;
	if (*s == 's')
		ret += print_s(param, flags);
	else if (*s == 'd')
		ret += print_d(param, flags);
	else if (*s == 'x')
		ret += print_x(param, flags);
	else if (*s == '%')
	{
		write(STDOUT_FILENO, s, 1);
		ret++;
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int	ret;
	int	i;
	t_flag	*flags;
	va_list	param;

	i = 0;
	ret = 0;
	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (-1);
	va_start(param, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += check_flags(flags, s + i);
			ret += check_conv(param, flags, s + i);
		}
		else
		{
			ret++;
			write(STDOUT_FILENO, &s[i], 1);
		}
		i++;
	}
	va_end(param);
	free(flags);
	return (ret);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%%%s%%", "e");
	ft_printf("%%%s%%", "e");
	return (0);
}*/
