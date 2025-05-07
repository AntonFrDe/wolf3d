##
## EPITECH PROJECT, 2024
## Wolf3D
## File description:
## makefile
##

NAME	=	wolf3d

SRC	=	main.c	\

STRUCT =	init_player.c	\
			init_game.c	\
			init_map.c	\

DISPLAY =	display_game.c	\
			event_handling.c	\
			minimap.c	\

RAYCAST =	cast_ray.c	\
			dda.c	\
			draw_ray.c	\

TOOLS =	remove_bsn.c	\
		print_vector.c	\

MENU =	main_menu.c	\
		menu_settings.c	\
		settings_mouse_events.c	\

SRC :=  $(addprefix src/, $(SRC))

STRUCT := $(addprefix src/init_struct/, $(STRUCT))

DISPLAY := $(addprefix src/display/, $(DISPLAY))

RAYCAST := $(addprefix src/raycasting/, $(RAYCAST))

TOOLS := $(addprefix tools/, $(TOOLS))

MENU := $(addprefix ../Game/Menu/, $(MENU))

CFLAGS += -g3 -Wall -Wextra -Iinclude

OBJ_SRC	=	$(SRC:.c=.o)
OBJ_STRUCT	=	$(STRUCT:.c=.o)
OBJ_DISPLAY = $(DISPLAY:.c=.o)
OBJ_RAYCAST = $(RAYCAST:.c=.o)
OBJ_TOOLS	=	$(TOOLS:.c=.o)
OBJ_MENU	=	$(MENU:.c=.o)

OBJ = $(OBJ_SRC) $(OBJ_STRUCT) $(OBJ_DISPLAY) $(OBJ_RAYCAST) $(OBJ_TOOLS) $(OBJ_MENU)
CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window


$(NAME):	$(OBJ)
	   gcc -o $(NAME) $(OBJ) $(CSFML) -g3 -lm

all:	$(NAME)

debug:	$(OBJ)
	   gcc -o $(NAME) $(OBJ) -fsanitize=address

clean:
		rm -f $(OBJ_SRC) $(OBJ_STRUCT) $(OBJ_DISPLAY)
		rm -f $(OBJ_RAYCAST) $(OBJ_TOOLS)
		rm -f coding-style-reports.log
		rm -f output
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all debug clean fclean re
