/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:47:59 by aldubar           #+#    #+#             */
/*   Updated: 2021/07/17 11:24:43 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_flag
{
	int	precision;
	int	padding;
}		t_flag;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strchr(const char *s, char c)
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

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char	c;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbrbase(unsigned int nb, const char *base)
{
	if (nb > 16)
	{
		ft_putnbrbase(nb / 16, base);
		ft_putnbrbase(nb % 16, base);
	}
	else
		write(1, &base[nb], 1);
}

int	ft_nblen(int nb)
{
	int	i;
	unsigned int	n;

	if (nb == 0)
		return (1);
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_hexlen(unsigned int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_putnchar(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	get_width(t_flag *flags, const char *s)
{
	int	i;

	i = 0;
	flags->padding = ft_atoi(s);
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
	flags->padding = 0;
	while (ft_strchr("0123456789.", s[i]))
	{
		if (ft_isdigit(s[i]))
			i += get_width(flags, s + i);
		else if (s[i] == '.')
		{
			i++;
			i += get_precision(flags, s + i);
		}
	}
	return (i);
}

int	print_s(t_flag *flags, va_list param)
{
	char *s;
	int	len;
	int	i;
	int	j;

	i = 0;
	s = (char *)va_arg(param, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->padding > len)
		i += ft_putnchar(' ', flags->padding - len);
	j = 0;
	while (j < len)
	{
		write(1, &s[j], 1);
		j++;
	}
	return (i + j);
}

int	print_d(t_flag *flags, va_list param)
{
	int	i;
	int	nb;
	int	len;
	int	nb_len;

	i = 0;
	nb = (int)va_arg(param, int);
	nb_len = ft_nblen(nb);
	len = nb_len;
	if (flags->precision > nb_len)
		len = flags->precision;
	if (nb < 0)
		flags->padding--;
	if (flags->precision == 0 && nb == 0)
	{
		i += ft_putnchar(' ', flags->padding);
		return (i);
	}
	if (flags->padding > len)
		i += ft_putnchar(' ', flags->padding - len);
	if (nb < 0)
	{
		i++;
		write(1, "-", 1);
	}
	if (flags->precision > nb_len)
		i += ft_putnchar('0', flags->precision - nb_len);
	ft_putnbr(nb);
	return (i + nb_len);
}

int	print_x(t_flag *flags, va_list param)
{
	int	i;
	unsigned int	nb;
	int	len;
	int	nb_len;

	i = 0;
	nb = (unsigned int)va_arg(param, unsigned int);
	nb_len = ft_hexlen(nb);
	len = nb_len;
	if (flags->precision > nb_len)
		len = flags->precision;
	if (flags->precision == 0 && nb == 0)
	{
		i += ft_putnchar(' ', flags->padding);
		return (i);
	}
	if (flags->padding > len)
		i += ft_putnchar(' ', flags->padding - len);
	if (flags->precision > nb_len)
		i += ft_putnchar('0', flags->precision - nb_len);
	ft_putnbrbase(nb, "0123456789abcdef");
	return (i + nb_len);
}

int	check_conv(va_list param, t_flag *flags, const char *s)
{
	int	i;

	i = 0;
	if (*s == 's')
		i += print_s(flags, param);
	else if (*s == 'd')
		i += print_d(flags, param);
	else if (*s == 'x')
		i += print_x(flags, param);
	return (i);
}

int	ft_printf(const char *s, ... )
{
	int	res;
	int	i;
	t_flag	*flags;
	va_list	param;

	i = 0;
	res = 0;
	flags = malloc(sizeof(t_flag));
	if (!flags)
		return (-1);
	va_start(param, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += check_flags(flags, s + i);
			res += check_conv(param, flags, s + i);
		}
		else
		{
			res++;
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(param);
	free(flags);
	return (res);
}
/*
int	main(void)
{
	ft_printf("%10.2s\n", "toto");
	printf("---\n");
	printf("%10.2s\n", "toto");
	printf("---\n");
	ft_printf("%s\n", "");
	printf("---\n");
	printf("%s\n", "");
	printf("---\n");
	ft_printf("Magic %s is %5d", "number", 42);
	printf("\n---\n");
	printf("Magic %s is %5d", "number", 42);
	printf("\n---\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("---\n");
	printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}*/
