#include "push_swap.h"


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
  while (i + 1 < ac)
  {
    a[i] = *av[1 + i];
    ft_printf("copying %c\n", *av[1 + i]);
    i++;
  }
  
  push_swap(a[], ac);
  return (0);
}
