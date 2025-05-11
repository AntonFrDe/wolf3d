/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** main
*/

#include "../include/wolf.h"

static void free_struct(game_t *game)
{
    sfFont_destroy(game->app.font);
    sfRenderWindow_destroy(game->window);
    free(game);
}

int main(void)
{
    game_t *game = init_game();

    display_game(game);
    free_struct(game);
    return 0;
}