##
## Makefile for allum1 in /home/lund/Dossier Courant/alum1/bonus
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Tue Jan 17 15:15:28 2012 Florian Dewulf
## Last update Sun Feb  5 14:47:15 2012 Florian Dewulf
##

NAME=		allum1

SRC=		main.c \
		func.c \
		my_getnbr.c \
		alum.c \
		my_put_nbr.c \
		ia.c \
		bonus.c \
		bonus2.c \
		bonus3.c \
		choix.c \
		read_touch.c

OBJ=		$(SRC:.c=.o)

SDLFLAG=	-lSDL -lpthread -lSDL_image -lSDL_mixer

$(NAME):	$(OBJ)
		cc -o $(NAME) $(SRC) $(SDLFLAG)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

cl:		re clean
		rm -f *~ $(OBJ)
