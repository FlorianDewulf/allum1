/*
** bonus2.c for alum1 in /home/lund/Dossier courant/alum1/bonus
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Feb  5 18:11:59 2012 Florian Dewulf
** Last update Wed Apr 25 20:42:02 2012 florian dewulf
*/

#include	"header.h"

int	choice_joueur(t_sdl *sdl)
{
  char	buff[1024];
  int	i;

  if ((i = read(0, buff, 1023)) == -1)
    exit(my_putstr("Fail read\n"));
  buff[i - 1] = '\0';
  i = my_getnbr(buff);
  return (i);
}

void	quit(t_sdl *sdl)
{
  SDL_FreeSurface(sdl->curseur);
  SDL_FreeSurface(sdl->fond);
  SDL_FreeSurface(sdl->alum);
  //Mix_FreeMusic(sdl->musique);
  //Mix_CloseAudio();
  //free(sdl->tab);
}

int	end_graph(t_sdl *sdl, int last_p)
{
  int	i;
  SDL_Event	event;
  SDL_Surface	*img;
  int	j;

  i = 0;
  j = 0;
  while (sdl->tab[i++] == 0);
  if (sdl->tab[i - 1] == -1 && last_p == 2)
    j = choice1(sdl, last_p, img, i);
  else if (sdl->tab[i - 1] == -1 && last_p == 1)
    j = choice2(sdl, last_p, img, i);
  if (j == 0)
    return (0);
  else
    {
      quit(sdl);
      SDL_Quit();
      exit(EXIT_SUCCESS);
    }
}

void	ia_graph(t_sdl *sdl)
{
  int	i;

  i = -1;
  while (sdl->tab[++i] == 0);
  if (sdl->tab[i] > 1)
    sdl->tab[i] = 1;
  else if (sdl->tab[i] == 1)
    sdl->tab[i] = 0;
  end_graph(sdl, 2);
}

int	choice_graph(t_sdl *sdl)
{
  SDL_Event	event;
  int		i;
  char		buff[2];

  i = 1;
  buff[0] = 'n';
  buff[1] = '\0';
  while (i && buff[0] == 'n')
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	i = 0;
      else if (event.type == SDL_KEYDOWN)
	buff[0] = check_touche(&event);
    }
  i = my_getnbr(buff);
  my_putchar(i + '0');
  my_putstr("\n");
  return (i);
}
