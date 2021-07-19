#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	char	*join;

	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!join)
		return (NULL);
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
	int	ret;
	char	buf[2];

	buf[1] = '\0';
	ret = 0;
	*line = malloc(sizeof(char));
	if (!(*line))
		return (-1);
	*line[0] = '\0';
	while ((ret = read(STDIN_FILENO, buf, 1)) == 1)
	{
		if (buf[0] == '\n')
			break ;
		else
		{
			*line = ft_strjoin(*line, buf);
			if (!(*line))
				return (-1);
		}
	}
	if (ret == -1 && *line)
	{
		free(*line);
		*line = NULL;
	}
	return (ret);
}

/*
int	get_next_line(char **line)
{
	int	i;
	int	ret;
	char	buf;

	i = 0;
	ret = 0;
	buf = 0;
	*line = malloc(400000);
	if (!(*line))
		return (-1);
	if (read(STDIN_FILENO, &buf, 0) < 0)
		return (-1);
	while ((ret = read(STDIN_FILENO, &buf, 1)) == 1 && buf != '\n')
		(*line)[i++] = buf;
	(*line)[i] = '\0';
	return (ret);
}*/
