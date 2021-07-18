/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:03:12 by aldubar           #+#    #+#             */
/*   Updated: 2021/07/15 22:46:32 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	join[i] = s2[0];
	join[i + 1] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}

int	get_next_line(char **line)
{
	int		ret;
	char	buf[2];

	ret = 0;
	buf[1] = '\0';
	*line = (char *)malloc(sizeof(char));
	if (!*line)
		return (-1);
	*line[0] = '\0';
	while ((ret = read(0, buf, 1)) == 1)
	{
		if (buf[0] == '\n')
			break ;
		else
			*line = ft_strjoin(*line, buf);
		if (*line == NULL)
		{
			free(*line);
			return (-1);
		}
	}
	if (ret == -1 && *line)
		free(*line);
	return (ret);
}
*/
int	get_next_line(char **line)
{
	int	ret;
	char	buf;
	int	i;

	i = 0;
	*line = malloc(100000);
	while ((ret = read(0, &buf, 1)) > 0 && buf != '\n')
		(*line)[i++] = buf;
	(*line)[i] = '\0';
	return (ret);
}
