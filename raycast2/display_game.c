/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** display_game
*/

#include "wolf.h"

int display_game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window.win)) {
        sfRenderWindow_clear(game->window.win, sfBlack);
        render_display(game);
        sfRenderWindow_display(game->window.win);
        if (sfRenderWindow_pollEvent(game->window.win, &game->window.event))
            event_handling(game);
    }
    free_struct(game);
    return 0;
}
