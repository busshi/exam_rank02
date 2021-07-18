/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:21:33 by aldubar           #+#    #+#             */
/*   Updated: 2021/07/16 19:02:55 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	while (get_next_line(&line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}
