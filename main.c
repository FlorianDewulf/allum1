/*
** main.c for alum1 in /home/lund/Dossier courant/alum1
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jan 23 09:06:16 2012 Florian Dewulf
** Last update Mon Feb  6 00:18:41 2012 Florian Dewulf
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"header.h"

int	recup_donnee()
{
  char	buff[1024];
  int	ret;

  if ((ret = read(0, buff, 1023)) == -1)
    exit(my_putstr("Fail read\n"));
  buff[ret] = '\0';
  ret = my_getnbr(buff);
  if (ret <= 1)
    {
      my_putstr("Valeur incorrecte");
      return (-1);
    }
  return (ret);
}

int	choice()
{
  char	buff[1024];
  int	ret;

  my_putstr("Voulez vous commencer ? (Oui (O)/Non (N))\n");
  if ((ret = read(0, buff, 1023)) == -1)
    exit(my_putstr("Fail read\n"));
  buff[ret - 1] = '\0';
  if (my_strlen(buff) != 1)
    return (my_putstr("Vous tapez n'importe quoi !\n"));
  else if (buff[0] == 'o' || buff[0] == 'O' || buff[0] == 'n' || buff[0] == 'N')
    {
      if (buff[0] == 'o' || buff[0] == 'O')
	return (1);
      else
	return (2);
    }
  else
    return (my_putstr("Vous tapez n'importe quoi !\n"));
}

int	choix_menu()
{
  char	buff[1024];
  int	ret;

  my_putstr("Choix de jeu :\n\n");
  my_putstr("Jouer avec les parametres par defaut (1)\n");
  my_putstr("Jouer avec les parametres perso (2)\n");
  if ((ret = read(0, buff, 1023)) == -1)
    exit(my_putstr("Fail read\n"));
  buff[ret - 1] = '\0';
  ret = my_getnbr(buff);
  if (ret != 1 && ret != 2)
    return (my_putstr("Vous tapez n'importe quoi !\n"));
  else
    {
      if (ret == 2)
	return (1);
      else
	return (2);
    }
}

int	main(int ac, char **av)
{
  int		nb_ligne;
  int		choix;

  while ((choix = choix_menu()) == 0);
  if (choix == 1)
    {
      my_putstr("Entrez le nombre de ligne que vous voulez (Nb > 1): \n");
      while ((nb_ligne = recup_donnee()) == -1);
      if (nb_ligne >= 2)
	{
	  while ((choix = choice()) == 0);
	  main_func(choix, nb_ligne);
	}
      else
	exit(my_putstr("Trop peu de lignes :(\n"));
    }
  else
    main_func(1, 5);
  return (0);
}
