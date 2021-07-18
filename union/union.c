/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:44:31 by aldubar           #+#    #+#             */
/*   Updated: 2021/07/15 16:49:23 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve_union(char *s1, char *s2)
{
	int	alpha[256];
	int	i;

	i = 0;
	while (i < 256)
	{
		alpha[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (!alpha[(int)s1[i]])
		{
			write(1, &s1[i], 1);
			alpha[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!alpha[(int)s2[i]])
		{
			write(1, &s2[i], 1);
			alpha[(int)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		solve_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
