/*
** ia.c for ia in /home/lund/Dossier courant/alum1
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jan 25 13:49:46 2012 Florian Dewulf
** Last update Fri Feb 10 12:45:53 2012 Florian Dewulf
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"header.h"

void	ia(int **tab, int nb_ligne, int taille)
{
  int	i;
  int	nb;

  i = 0;
  my_putstr("\033[31m_____C'EST_AU_TOUR_DE_L'IA______\n\033[00m");
  aff_pyram(*tab, nb_ligne, taille);
  while (((*tab)[i] == 0 || (*tab)[i] == 1) && (*tab)[i] != -1)
    i++;
  if ((*tab)[i] != -1)
    (*tab)[i] = 1;
  else
    {
      i = 0;
      while ((*tab)[i] == 0 && (*tab)[i] != -1)
	i++;
      if ((*tab)[i] == 1)
	(*tab)[i] = 0;
    }
}

int	check_last_line(int *tab)
{
  int	curs;

  curs = -1;
  while (tab[++curs] == 0);
  if (tab[curs] == 1)
    return (2);
  else if (tab[curs] > 1)
    return (1);
  else
    return (0);
}

int	finish(int nb, int *tab, int nb_ligne, int taille)
{
  if (nb == 1)
    {
      my_putstr("\n_________________\nTableau de fin\n\n");
      aff_pyram(tab, nb_ligne, taille);
      my_putstr("\nVous avez perdu. Vous pouvez réessayer ou me mettre 42.\n");
    }
  else
    {
      my_putstr("\n_________________\nTableau de fin\n\n");
      aff_pyram(tab, nb_ligne, taille);
      my_putstr("\nVous avez gagné. ");
      my_putstr("Chance du débutant ou l'IA qui était fatiguée ?\n");
    }
  return (0);
}

int	end(int **tab, int nb_ligne, int taille, int choix)
{
  while (check_last_line(*tab) != 0)
    {
      if (choix == 1)
	while (!choix_joueur(tab, nb_ligne, taille));
      else
	ia(tab, nb_ligne, taille);
      if (check_last_line(*tab) == 1)
	{
	  if (choix == 1)
	    ia(tab, nb_ligne, taille);
	  else
	    while (!choix_joueur(&tab, nb_ligne, taille));
	}
      else if (check_last_line(*tab) == 0 && choix == 1)
	return (finish(1, *tab, nb_ligne, taille));
      else if (check_last_line(*tab) == 2 && choix == 1)
	return (finish(2, *tab, nb_ligne, taille));
      else if (check_last_line(*tab) == 0 && choix == 2)
	return (finish(2, *tab, nb_ligne, taille));
      else if (check_last_line(*tab) == 2 && choix == 2)
	return (finish(1, *tab, nb_ligne, taille));
    }
  if (check_last_line(*tab) == 0 && choix == 1)
    return (finish(2, *tab, nb_ligne, taille));
  return (finish(1, *tab, nb_ligne, taille));
}
