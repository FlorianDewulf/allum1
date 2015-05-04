/*
** read_touch.c for allum1 in /home/lund/Dossier courant/alum1/bonus
** 
** Made by Florian Dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Feb  8 18:38:43 2012 Florian Dewulf
** Last update Wed Feb  8 19:20:57 2012 Florian Dewulf
*/

#include	"header.h"

char	check_touche(SDL_Event *event)
{
  if (event->key.keysym.sym == 257)
    return ('1');
  else if (event->key.keysym.sym == 258)
    return ('2');
  else if (event->key.keysym.sym == 259)
    return ('3');
  else if (event->key.keysym.sym == 260)
    return ('4');
  else if (event->key.keysym.sym == 261)
    return ('5');
  else if (event->key.keysym.sym == 262)
    return ('6');
  else if (event->key.keysym.sym == 263)
    return ('7');
  else if (event->key.keysym.sym == 264)
    return ('8');
  else if (event->key.keysym.sym == 265)
    return ('9');
}
