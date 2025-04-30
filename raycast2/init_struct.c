/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** ini_struct
*/

#include "wolf.h"

static window_t init_window(void)
{
    window_t window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window.win = sfRenderWindow_create(mode, "MyWoke", sfClose | sfResize, NULL);
    window.color = sfBlack;
    return window;
}

static player_t init_player(void)
{
    player_t player;

    player.loc = (sfVector2f ){.x = WIDTH / (2 * 13), .y = HEIGHT / (2 * 13)};
    player.circle = sfCircleShape_create();
    player.angle = 360 - 90;
    sfCircleShape_setFillColor(player.circle, sfBlue);
    sfCircleShape_setRadius(player.circle, 5);
    player.rays = malloc(sizeof(ray_t) * RAY);
    for (int i = 0; i != RAY; i++)
        player.rays[i].angle = player.angle + i;
    return player;
}

int init_struct(char *map_file, game_t *game)
{
    if (init_map(map_file, game) == 84)
        return 84;
    game->player = init_player();
    game->window = init_window();
    game->show_map = true;
}
