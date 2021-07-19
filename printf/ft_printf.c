#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_flag
{
	int	width;
	int	precision;
}		t_flag;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	in_charset(char c, const char *s)
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
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
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
	return (len);
}

int	ft_nblen(int nb)
{
	int	len;
	unsigned int	n;

	len = 1;
	if (nb == 0)
		return (len);
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (len);
	while (n >= 16)
	{
		len++;
		n /= 16;
	}
	return (len);
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

void	ft_putnbrbase(const char *base, unsigned int n)
{
	if (n > 16)
	{
		ft_putnbrbase(base, n / 16);
		ft_putnbrbase(base, n % 16);
	}
	else
		write(STDOUT_FILENO, &base[n], 1);
}

int	get_width(const char *s, t_flag *flags)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(s);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int	get_precision(const char *s, t_flag *flags)
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
	flags->width = 0;
	flags->precision = -1;
	while (in_charset(s[i], "0123456789."))
	{
		if (ft_isdigit(s[i]))
			i += get_width(s + i, flags);
		else if (s[i] == '.')
		{
			i++;
			i += get_precision(s + i, flags);
		}
	}
	return (i);
}

int	print_x(va_list param, t_flag *flags)
{
	int	len_x;
	int	len;
	unsigned int	x;
	int	i;

	i = 0;
	x = (unsigned int)va_arg(param, unsigned int);
	len_x = ft_hexlen(x);
	len = len_x;
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
	ft_putnbrbase("0123456789abcdef", x);
	return (i + len_x);
}

int	print_d(va_list param, t_flag *flags)
{
	int	len_d;
	int	len;
	int	n;
	int	i;

	i = 0;
	n = (int)va_arg(param, int);
	if (n < 0)
		flags->width--;
	len_d = ft_nblen(n);
	len = len_d;
	if (flags->precision > len)
		len = flags->precision;
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

int	print_s(va_list param, t_flag *flags)
{
	int	i;
	int	j;
	int	len;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)va_arg(param, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->width > len)
		i += ft_putnchar(' ', flags->width - len);
	while (j < len)
	{
		write(STDOUT_FILENO, &s[j], 1);
		j++;
	}
	return (i + j);
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
		ret += ft_putnchar('%', 1);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int	ret;
	int	i;
	va_list	param;
	t_flag	*flags;

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
