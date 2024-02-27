#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c == '-' || c == '+'))
	{
		return (1);
	}
	return (0);
}

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
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check(long tmp, char **args, int i)
{
	if (has_duplicate(tmp, args, i))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if (!has_num(args[i]))
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

	if (ac == 2)
		exit(-1);
	x = 1;
	args = av;
	while (args[x])
	{
		tmp = ft_atol(args[x]);
		check(tmp, args, x);
		x++;
	}
	if (ac == 2)
		ft_free((void **)args);
}
