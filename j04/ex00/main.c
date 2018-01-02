#include <stdio.h>
#include "libft/libft.h"
#include "ft_iterative_factorial.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("factorial: %d\n", ft_iterative_factorial(ft_atoi(argv[1])));

  return EXIT_SUCCESS;
}
