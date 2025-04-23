##
## EPITECH PROJECT, 2024
## Woke 3d
## File description:
## Makefile
##

NAME = woke3d

SRC = angle_coor.c \
      circle_create.c \
	  create_player.c \
	  display_3d.c \
	  draw_floor_and_ceilling.c \
	  create_quad.c \
	  display_map.c \
	  float_modulo.c \
	  init_map.c \
	  init_ray.c \
	  is_loc_in_map.c \
	  line_create.c \
	  main.c \
	  print_vector.c \
	  square_create.c

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
