#include "libft/libft.h"
#include "ft_iterative_power.h"

int ft_iterative_power(int nb, int power)
{
  if(power < 0)
    return 0;
  else
  {
    int iter;
    int i;

    i = 0;
    iter = 1;

    while(i < power)
    {
      iter *= nb;
      i++;
    }

    return iter;
  }
}
