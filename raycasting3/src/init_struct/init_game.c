/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_game
*/

#include "../../include/wolf.h"
#include <stdlib.h>

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVector2i position = {0, 0};

    game->state = STATE_MENU;
    game->video.bitsPerPixel = 32;
    game->video.height = 1080;
    game->video.width = 1920;
    game->window = sfRenderWindow_create(game->video, "wolf3d", sfClose, NULL);
    game->app = init_app();
    sfRenderWindow_setView(game->window, game->app.view);
    game->player = init_player();
    game->map = make_map(game);
    sfRenderWindow_setPosition(game->window, position);
    game->event = malloc(sizeof(sfEvent));
    game->time = sfClock_create();
    return game;
}
