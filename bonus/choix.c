/*
** choix.c for alum1 in /home/lund/Dossier courant/alum1/bonus
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Feb  6 18:04:17 2012 Florian Dewulf
** Last update Wed Feb  8 19:25:10 2012 Florian Dewulf
*/

#include	"header.h"

int	choice1(t_sdl *sdl, int last_p, SDL_Surface *img, int i)
{
  SDL_Event	event;

  if (sdl->tab[i - 1] == -1 && last_p == 2)
    {
      img = IMG_Load("./Ressource_graphique/win.png");
      SDL_BlitSurface(img, NULL, sdl->screen, NULL);
      SDL_Flip(sdl->screen);
      SDL_FreeSurface(img);
      free(sdl->musique);
      sdl->musique = Mix_LoadMUS("./Ressource_audio/ff9victory.mid");
      Mix_PlayMusic(sdl->musique, -1);
      while (last_p == 2)
	{
	  SDL_WaitEvent(&event);
	  if (event.type == SDL_QUIT)
	    return (-1);
	}
    }
  else
    return (0);
}

int	choice2(t_sdl *sdl, int last_p, SDL_Surface *img, int i)
{
  SDL_Event	event;

  if (sdl->tab[i - 1] == -1 && last_p == 1)
    {
      img = IMG_Load("./Ressource_graphique/defeat.png");
      SDL_BlitSurface(img, NULL, sdl->screen, NULL);
      SDL_Flip(sdl->screen);
      SDL_FreeSurface(img);
      free(sdl->musique);
      sdl->musique = Mix_LoadMUS("./Ressource_audio/ff9defeat.mid");
      Mix_PlayMusic(sdl->musique, -1);
      while (last_p == 1)
	{
	  SDL_WaitEvent(&event);
	  if (event.type == SDL_QUIT)
	    return (-1);
	}
    }
  else
    return (0);
}
