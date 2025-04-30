/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** free_struct
*/

#include "wolf.h"

static void free_map(map_t map)
{
    for (int i = 0; i != map.size.y; i++) {
        for (int j = 0; j != map.size.x; j++) {
            sfVertexArray_destroy(map.vertex[i][j]);
        }
        free(map.wall[i]);
    }
}

static void free_player(player_t player)
{
    sfCircleShape_destroy(player.circle);
    for (int i = 0; i != RAY; i++)
        sfVertexArray_destroy(player.rays[i].vertex);
}

static void free_window(window_t win)
{
    sfRenderWindow_destroy(win.win);
}

void free_struct(game_t *game)
{
    free_map(game->map);
    free_player(game->player);
    free_window(game->window);
    free(game);
}
