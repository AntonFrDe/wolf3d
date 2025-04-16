##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	main.c \
		Game/map.c \
		

CFLAGS	+=	-W -Wall -Wextra -g3

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	Woke3D

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all
