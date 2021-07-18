#include <stdlib.h>
#include <unistd.h>

int	get_next_line(char **line)
{
	int	ret;
	char	buf;
	int	i;

	i = 0;
	buf = 0;
	ret = 0;
	*line = malloc(1000000);
	if (!*line)
		return (-1);
	if (read(STDIN_FILENO, &buf, 0) < 0)
		return (-1);
	while ((ret = read(STDIN_FILENO, &buf, 1)) > 0 && buf != '\n')
		(*line)[i++] = buf;
	(*line)[i] = '\0';
	return (ret);
}
