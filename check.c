#include "push_swap.h"

int	has_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	has_num(char *num)
{
	int		i;
	char	c;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		c = num[i];
		if (!(c >= '0' && c <= '9') || (c == '-' || c == '+'))
			return (1);
		i++;
	}
	return (0);
}

static void	check(long tmp, char **args, int i)
{
	if (has_duplicate(tmp, args, i))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if (has_num(args[i]) == 1)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if (tmp < -2147483648 || tmp > 2147483647)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

void	check_args(char **av, int ac)
{
	long	tmp;
	char	**args;
	int		x;

	args = av;
	if (ac <= 2)
	{
		if (has_num(args[1]) == 1 || !args[1])
			write(1, "Error\n", 6);
		exit(-1);
	}
	x = 1;
	while (args[x])
	{
		tmp = ft_atol(args[x]);
		check(tmp, args, x);
		x++;
	}
	if (ac == 2)
		ft_free((void **)args);
}
