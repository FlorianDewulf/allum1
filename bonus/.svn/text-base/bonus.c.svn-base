/*
** bonus.c for alum1 in /home/lund/Dossier courant/alum1/bonus
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Feb  4 22:21:19 2012 Florian Dewulf
** Last update Fri Feb 10 12:45:06 2012 Florian Dewulf
*/

#include	<stdlib.h>
#include	"header.h"

void	move_cursor(t_sdl *sdl, SDL_Event *event)
{
  if (event->key.keysym.sym == UP && sdl->coord_curseur.y > 96)
    sdl->coord_curseur.y -= 96;
  else if (event->key.keysym.sym == DOWN && sdl->coord_curseur.y + 96 < 550)
    sdl->coord_curseur.y += 96;
}

int	accept(t_sdl *sdl)
{
  SDL_Surface	*message;
  SDL_Rect	coord;
  int		i;

  i = 0;
  if (sdl->tab[(sdl->coord_curseur.y / LONG_ALUM) - 1] > 0)
    {
      message = IMG_Load("./Ressource_graphique/message.png");
      coord.x = WINX / 2 - 640 / 2;
      coord.y = WINY / 2 - 200 / 2;
      SDL_BlitSurface(message, NULL, sdl->screen, &coord);
      SDL_Flip(sdl->screen);
      while (i <= 0 || i > sdl->tab[(sdl->coord_curseur.y / LONG_ALUM) - 1])
	{
	  my_putstr("Combien d'allumettes voulez vous retirer ?\n=> ");
	  i = choice_graph(sdl);
	  if (i <= 0 || i > sdl->tab[(sdl->coord_curseur.y / LONG_ALUM) - 1])
	    my_putstr("Valeur invalide\n");
	}
      sdl->tab[sdl->coord_curseur.y / LONG_ALUM - 1] -= i;
    }
  else
    return (-1);
}

void	menu(t_sdl *sdl)
{
  int		i;
  SDL_Event	event;

  i = 1;
  while (i)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	i = 0;
      else if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == ECHAP)
	    i = 0;
	  else if (event.key.keysym.sym == UP || event.key.keysym.sym == DOWN)
	    move_cursor(sdl, &event);
	  else if (event.key.keysym.sym == ENTER)
	    if (accept(sdl) != -1)
	      {
		end_graph(sdl, 1);
		ia_graph(sdl);
	      }
	}
      blit_img(sdl);
    }
  quit(sdl);
}

int	*init_tab_sdl(t_sdl *sdl)
{
  int	i;
  int	j;
  int	curs;
  int	*tab;

  curs = 0;
  i = 1;
  j = 5;
  tab = xmalloc(7 * sizeof(int));
  while (j > 0)
    {
      tab[curs++] = i;
      i += 2;
      j--;
    }
  tab[curs] = -1;
  sdl->coord_curseur.x = DECAL + 11 * LARG_ALUM + 20;
  sdl->coord_curseur.y = 96;
  return (tab);
}

int	bonus()
{
  t_sdl	sdl;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_DOUBLEBUF) < 0)
    exit(my_putstr("Fail init\n"));
  if ((sdl.screen = SDL_SetVideoMode(WINX, WINY, 32, SDL_HWSURFACE |
				     SDL_DOUBLEBUF)) == NULL)
    exit(my_putstr("Fail set video\n"));
  SDL_WM_SetCaption("A L U M  1", NULL);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, \
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    exit(my_putstr("Fail Audio\n"));
  sdl.musique = Mix_LoadMUS("./Ressource_audio/1 - Tantarus Theme.mid");
  Mix_PlayMusic(sdl.musique, -1);
  SDL_FillRect(sdl.screen, NULL, SDL_MapRGB(sdl.screen->format, 0, 0, 0));
  reduc_init(&sdl);
  sdl.tab = init_tab_sdl(&sdl);
  menu(&sdl);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
