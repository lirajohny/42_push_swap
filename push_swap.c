#include "push_swap.h"


void ft_printf(char *str)
{
	int	i;
	i = 0;

	while (str[i] != '\0')
	{
		write(1, str[i], 1);
		i++;
	}
}
int push_swap(char *a[], int len)
{
  char *b[ac];

}

int main(int ac, char **av)
{
  if (ac < 2)
  {
    ft_printf("error");
    return (1);
  }
  char a[ac];
  int i;
  i = 0;
  while (i++ < ac - 1)
  {
	  if (!(av[i] >= '0' && av[i] <= '9'))
	  {
		  ft_printf("error");
		  return (1);
	  }
  }
  i = 0;
  while (i + 1 < ac)
  {
    a[i] = *av[1 + i];
    ft_printf("copying %c\n", *av[1 + i]);
    i++;
  }
  
  push_swap(a[], ac);
  return (0);
}
