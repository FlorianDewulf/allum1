/*
** my_getnbr.c for my_getnbr in /home/dewulf_f//afs/Brouillon
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Oct 11 18:23:56 2011 florian dewulf
** Last update Tue Jan 24 23:19:45 2012 Florian Dewulf
*/

#include	"header.h"

int	my_getnbr(char *str)
{
  int	c;
  int	signe;
  int	resultat;

  (signe = 1) ? (c = 0) : (c = 0);
  resultat = 0;
  while (str[c] != 0 && ((str[c] >= 48 && str[c] <= 57) ||
			 (str[c] == 43 || str[c] == 45)))
    {
      while (str[c] == 45)
	{
	  signe = signe * -1;
	  c++;
	  if (str[c] == 0 || (str[c] <= 48 && str[c] >= 57 &&
			      str[c] != 45 && str[c] != 43))
	    return (0);
	}
      if (str[c] >= 48 && str[c] <= 57)
	{
	  str[c] = str[c] - 48;
	  resultat = (resultat * 10) + str[c];
	}
      c++;
    }
  return (resultat * signe);
}
