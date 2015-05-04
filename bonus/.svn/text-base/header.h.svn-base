/*
** header.h for header in /home/lund/106suite
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jan 17 20:56:48 2012 Florian Dewulf
** Last update Sun Feb 12 16:10:57 2012 Florian Dewulf
*/

#ifndef	__HEADER_H__
#define	__HEADER_H__

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<SDL/SDL_mixer.h>

#define		WINX		800
#define		WINY		600
#define		LARG_ALUM	35
#define		LONG_ALUM	96
#define		SIZE_LINE	385
#define		DECAL		107
#define		UP		SDLK_UP
#define		DOWN		SDLK_DOWN
#define		ECHAP		SDLK_ESCAPE
#define		ENTER		SDLK_RETURN


typedef struct	s_sdl
{
  SDL_Surface	*screen;
  SDL_Surface	*curseur;
  SDL_Surface	*fond;
  SDL_Surface	*alum;
  SDL_Rect	coord_curseur;
  SDL_Rect	coord_alum;
  Mix_Music	*musique;
  int		*tab;
}t_sdl;

void	my_putchar(char);
int	my_putstr(char *);
void	*xmalloc(int);
int	my_strlen(char *);

int	my_getnbr(char *);

int	*init_tab(int);

#endif
