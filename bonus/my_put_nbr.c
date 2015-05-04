/*
** my_put_nbr.c for my_put_nbr in /home/dewulf_f//afs/Brouillon
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Oct  6 19:21:02 2011 florian dewulf
** Last update Tue Jan 24 16:53:29 2012 Florian Dewulf
*/

void	my_put_nbr(int nb)
{
  int	compteur;
  int	diviseur;

  compteur = 0;
  diviseur = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / diviseur) >= 10)
    {
      diviseur = diviseur * 10;
    }
  while (diviseur > 0)
    {
      my_putchar((nb / diviseur) % 10 + '0');
      diviseur = diviseur / 10;
    }
}
