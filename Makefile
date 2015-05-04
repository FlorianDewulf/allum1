##
## Makefile for allum1 in /home/lund/Dossier Courant/alum1/
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Tue Jan 17 15:15:28 2012 Florian Dewulf
## Last update Thu Feb  2 18:15:36 2012 Florian Dewulf
##

NAME=		allum1

SRC=		main.c \
		func.c \
		my_getnbr.c \
		alum.c \
		my_put_nbr.c \
		ia.c

OBJ=		$(SRC:.c=.o)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(SRC) $(CFLAGS)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

cl:		re clean
		rm -f *~ $(OBJ)
