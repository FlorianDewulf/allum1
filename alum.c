/*
** alum.c for alum1 in /home/lund/Dossier courant/alum1
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jan 23 12:51:05 2012 Florian Dewulf
** Last update Tue Feb  7 11:43:35 2012 Florian Dewulf
*/

#include	<stdlib.h>
#include	"header.h"

int	victoire(int *tab)
{
  int	count;
  int	curs;

  count = 0;
  curs = 0;
  while (tab[curs] != -1)
    {
      if (tab[curs] != 0)
	count++;
      curs++;
    }
  if (count > 1)
    return (0);
  else
    return (1);
}

int	check_carac(int nb_ligne)
{
  if (nb_ligne < 10)
    return (1);
  else if (nb_ligne < 100)
    return (2);
  else if (nb_ligne < 1000)
    return (3);
  else if (nb_ligne < 10000)
    return (4);
  else if (nb_ligne < 100000)
    return (5);
  else if (nb_ligne < 1000000)
    return (6);
  else if (nb_ligne < 10000000)
    return (7);
  else if (nb_ligne < 100000000)
    return (8);
  else
    return (9);
}

void	aff_pyram(int *tab, int nb_ligne, int taille)
{
  int		carac;
  int		i;
  int		size;

  i = -1;
  carac = check_carac(nb_ligne);
  while (++i < nb_ligne)
    {
      if ((size = check_carac(i + 1)) <= carac)
	{
	  my_put_nbr(i + 1);
	  while (size++ <= carac)
	    my_putchar(' ');
	  size = taille - (tab[i] / 2);
	  while (size-- > 0)
	    my_putchar(' ');
	  while (size++ < tab[i] - 1)
	    my_putstr("\033[33m|\033[00m");
	  size = 0;
	  while (size++ <= taille - (tab[i] / 2))
	    my_putchar(' ');
	  my_put_nbr(tab[i]);
	}
      my_putchar('\n');
    }
}

int	choix_joueur(int **tab, int nb_ligne, int taille)
{
  char	buff[1024];
  int	ret;
  int	line;
  int	nb;

  my_putstr("\033[36m_______C'EST_A_VOTRE_TOUR________\n\033[00m");
  aff_pyram(*tab, nb_ligne, taille);
  my_putstr("\nA quelle ligne voulez vous retirer une alumette : ");
  if ((ret = read(0, buff, 1023)) <= 0)
    exit(my_putstr("Fail read\n"));
  buff[ret - 1] = '\0';
  line = my_getnbr(buff);
  if (line > nb_ligne || line <= 0)
    return (my_putstr("Valeur invalide\n"));
  my_putstr("\nCombien d'alumette voulez vous retirer ? (nb > 0) : ");
  if ((ret = read(0, buff, 1023)) <= 0)
    exit(my_putstr("Fail read\n"));
  buff[ret - 1] = '\0';
  nb = my_getnbr(buff);
  if (nb <= 0 || nb > (*tab)[line - 1])
    return (my_putstr("Valeur invalide\n"));
  (*tab)[line - 1] -= nb;
  return (1);
}

void	main_func(int choix, int nb_ligne)
{
  int	*tab;
  int	taille;

  tab = init_tab(nb_ligne);
  taille = (tab[nb_ligne - 1] / 2);
  while (!victoire(tab))
    {
      if (choix == 1)
	while (!choix_joueur(&tab, nb_ligne, taille));
      else
	ia(&tab, nb_ligne, taille);
      if (choix == 1)
	ia(&tab, nb_ligne, taille);
      else
	while (!choix_joueur(&tab, nb_ligne, taille));
    }
  end(&tab, nb_ligne, taille, choix);
}
