/*
** func.c for alum1 in /home/lund/Dossier courant/alum1
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jan 23 09:23:28 2012 Florian Dewulf
** Last update Mon Jan 30 11:21:40 2012 Florian Dewulf
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"header.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(my_putstr("Fail write\n"));
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
  return (0);
}

void	*xmalloc(int size)
{
  void	*str;

  str = malloc(size);
  if (str == NULL)
    exit(my_putstr("Erreur malloc\n"));
  return (str);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	*init_tab(int nb_ligne)
{
  int	*tab;
  int	count;
  int	alumette;

  count = 0;
  alumette = 1;
  tab = xmalloc((nb_ligne + 1) * sizeof(int));
  while (count < nb_ligne)
    {
      tab[count++] = alumette;
      alumette += 2;
    }
  tab[nb_ligne] = -1;
  return (tab);
}
