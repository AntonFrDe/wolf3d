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

    game->player = init_player();
    game->map = make_map(game);
    game->video.bitsPerPixel = 32;
    game->video.height = 1080;
    game->video.width = 1920;
    game->window = sfRenderWindow_create(game->video, "wolf3d",
        sfClose | sfResize, NULL);
    game->event = malloc(sizeof(sfEvent));
    return game;
}
