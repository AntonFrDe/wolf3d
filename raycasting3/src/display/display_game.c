/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_game
*/

#include "../../include/wolf.h"

void display_game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        cast_ray(game);
        draw_minimap(game);
        sfRenderWindow_display(game->window);
        if (sfRenderWindow_pollEvent(game->window, game->event))
            event_handling(game);
    }
}
