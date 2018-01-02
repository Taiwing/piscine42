#include "ft_print_combn.h"

void ft_print_combn(int n)
{
  int **bank; /*is gonna store legal combinaisons*/
  int *comb; /*is gonne store the current decision*/
  int w;

  //w = ft_get_width_value(n);
  w = 1000;

  bank = ft_alloc_2D_array(w, n);
  comb = malloc(n * sizeof(int));

  while(comb[0] < 10)
  {
    ft_comb_values(comb, n);
    if(ft_are_comb_numbers_different(comb, n))
      ft_printing_comb(ft_is_valid(comb, bank, n), comb, n);
  }
  printf("\n");

  free(bank);
  free(comb);
}

void ft_comb_values(int comb[], int n)
{
  int i = n - 1;
  while(i > -1)
  {
    if(comb[i] < 10) /*is executed only once every time the function is called*/
    {
      comb[i]++;

      if(i != 0)
      {
        if(comb[i] == 10)
        {
          comb[i] = 0;
        }
        else
          break;
      }
    }

    i--;
  }
}

int ft_are_comb_numbers_different(int comb[], int n)
{
  int i;
  int i2;

  i = 0;
  i2 = 0;

  while(i < n)
  {
    while(i2 < n - 1)
    {
      if(i2 == i)
        i2++;
      if(comb[i] == comb[i2])
        return 0;
      i2++;
    }
    i2 = 0;
    i++;
  }

  return 1;
}

int ft_is_valid(int comb[], int **bank, int n)
{
  int c[3]; /*counters*/

  c[0] = 0;
  while(1) /*infinite loop*/
  {
    if(ft_is_comb_null(bank, c[0], n)) /*if we're on a NULL comb*/
    {
      ft_save_comb(bank, comb, c[0], n);
      return 1; /*then we quit the loop*/
    }
    c[1] = 0;
    c[2] = 0;
    while(c[2] < n)
    {
      if(ft_is_matching(bank, comb, n, c))
        c[1]++;
      c[2]++;
    }
    if(c[1] == n)
      return 0; /*we stop the loop if the comb is already in the comBank*/
    c[0]++;
  }
}

int ft_is_comb_null(int **bank, int i, int n)
{
  int c;
  int zCount;

  c = 0;
  zCount = 0;

  while(c < n)
  {
    if(bank[i][c] == 0)
      zCount++;
    c++;
  }

  if(zCount == n)
    return 1;
  else
    return 0;
}

void ft_save_comb(int **bank, int comb[], int i, int n)
{
  int j;

  j = 0;

  while(j < n)
  {
    bank[i][j] = comb[j]; /*we save the legal unrecuring comb in the bank*/
    j++;
  }
}

void ft_printing_comb(int valid, int comb[], int n)
{
  int i;

  i = 0;

  if(valid)
  {
    while(i < n) /*we print the comb*/
    {
      printf("%c", 48 + comb[i]);
      i++;
    }
    printf(", ");
  }
}

int ft_get_width_value(int n)
{
  int i;
  int x;
  int f;

  i = 0;
  x = 1;
  f = 0;
  while(i < n)
  {
    x *= 10 - (i + 1);
    f+= x;
    i++;
  }

  printf("f = %d\n", f);
  return f;
}

int ft_is_matching(int **bank, int comb[], int n, int c[3])
{
  int i;

  i = 0;

  while(i < n)
  {
    if(bank[c[0]][c[2]] == comb[i])
      return 1;
    i++;
  }

  return 0;
}
