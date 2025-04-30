##
## EPITECH PROJECT, 2024
## Woke 3d
## File description:
## Makefile
##

NAME = woke3d

SRC = render_display.c	\
	  display_game.c \
	  create_quad.c \
	  init_struct.c \
	  main.c \
	  remove_bsn.c	\
	  print_vector.c	\
	  event_handling.c	\
	  mooving_func.c	\
	  draw_ray.c	\
	  draw_3d.c	\
	  free_struct.c	\
	  init_map.c	\

OBJ = $(SRC:.c=.o)

CFLAGS += -g3
CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CSFML) -lm

clean:
	rm -f $(OBJ)
	rm -f ./*gcno
	rm -f ./*gcda

fclean: clean
	rm -f $(NAME)

re: fclean all
