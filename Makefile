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
			init_app.c	\
			init_overlay.c	\
			init_game_texture.c	\
			init_mob.c	\

DISPLAY =	display_game.c	\
			minimap.c	\
			display_menu.c	\
			display_settings.c	\
			play_game.c	\
			display_hud.c	\
			escape_menu_in_game.c \
			escape_menu_events.c \

RAYCAST =	cast_ray.c	\
			dda.c	\
			draw_ray.c	\
			draw_txtr.c	\
			floor_cast.c	\
			draw_obj.c	\

TOOLS =	remove_bsn.c	\
		print_vector.c	\
		key_event.c	\
		draw_text.c	\
		my_superstrcat.c	\
		my_arrlen.c	\
		my_str_to_warr_custom.c	\

EVENT =	event_handling.c	\
		settings_mouse_events.c	\
		event.c	\
		mob_events.c	\

OVERLAY =	ammo.c	\
			hud.c	\
			update.c	\
			weapon.c	\

SRC :=  $(addprefix src/, $(SRC))

STRUCT := $(addprefix src/init_struct/, $(STRUCT))

DISPLAY := $(addprefix src/display/, $(DISPLAY))

RAYCAST := $(addprefix src/raycasting/, $(RAYCAST))

TOOLS := $(addprefix tools/, $(TOOLS))

EVENT := $(addprefix src/event/, $(EVENT))

OVERLAY := $(addprefix src/overlay/, $(OVERLAY))

CFLAGS += -g3 -Wall -Wextra -Iinclude

OBJ_ONE	=	$(SRC:.c=.o) $(STRUCT:.c=.o) $(DISPLAY:.c=.o) $(RAYCAST:.c=.o)
OBJ_TWO	=	$(TOOLS:.c=.o) $(SAVE:.c=.o) $(EVENT:.c=.o) $(OVERLAY:.c=.o)

OBJ = $(OBJ_ONE) $(OBJ_TWO)
CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window


$(NAME):	$(OBJ)
	   gcc -o $(NAME) $(OBJ) $(CSFML) -g3 -lm

all:	$(NAME)

debug:	$(OBJ)
	   gcc -o $(NAME) $(OBJ) -fsanitize=address

clean:
		rm -f $(OBJ_SRC) $(OBJ_STRUCT) $(OBJ_DISPLAY)
		rm -f $(OBJ_RAYCAST) $(OBJ_TOOLS) $(OBJ_OVERLAY)
		rm -f coding-style-reports.log
		rm -f output
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all debug clean fclean re
