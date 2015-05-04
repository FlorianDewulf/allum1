/*
** bonus3.c for allum1 in /home/lund/Dossier courant/alum1/bonus
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Feb 10 12:36:52 2012 Florian Dewulf
** Last update Fri Feb 10 12:39:02 2012 Florian Dewulf
*/

#include	<stdlib.h>
#include	"header.h"

void	reduc_init(t_sdl *sdl)
{
  sdl->curseur = IMG_Load("./Ressource_graphique/curseur.png");
  sdl->fond = IMG_Load("./Ressource_graphique/fond.jpg");
  sdl->alum = IMG_Load("./Ressource_graphique/allum.png");
  sdl->coord_alum.x = DECAL;
  sdl->coord_alum.y = 500;
}

void	blit_img(t_sdl *sdl)
{
  int	i;
  int	j;
  int	x;
  int	y;

  (y = sdl->coord_alum.y) ? (i = 5) : (i = 5);
  x = sdl->coord_alum.x;
  SDL_BlitSurface(sdl->fond, NULL, sdl->screen, NULL);
  SDL_BlitSurface(sdl->curseur, NULL, sdl->screen, &(sdl->coord_curseur));
  while (i > 0)
    {
      j = sdl->tab[i - 1];
      sdl->coord_alum.x = x;
      sdl->coord_alum.y = y - (5 - i) * 96;
      while (j > 0)
	{
	  SDL_BlitSurface(sdl->alum, NULL, sdl->screen, &sdl->coord_alum);
	  sdl->coord_alum.x += 35;
	  j--;
	}
      i--;
    }
  SDL_Flip(sdl->screen);
  sdl->coord_alum.y = y;
  sdl->coord_alum.x = x;
}
