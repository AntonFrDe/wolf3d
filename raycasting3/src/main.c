/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** main
*/

#include "../include/wolf.h"
#include <stdlib.h>

int main(void)
{
    game_t *game = init_game();

    display_game(game);
    free(game);
}
