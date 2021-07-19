#include <unistd.h>

void	solve_union(const char *s1, const char *s2)
{
	int	i;
	int	alpha[256];

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
			write(STDOUT_FILENO, &s1[i], 1);
			alpha[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!alpha[(int)s2[i]])
		{
			write(STDOUT_FILENO, &s2[i], 1);
			alpha[(int)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		solve_union(av[1], av[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
