/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_player
*/

#include "../../include/wolf.h"

player_t init_player(void)
{
    player_t player;

    player.loc.x = 12;
    player.loc.y = 12;
    player.dir.x = -1;
    player.dir.y = 0;
    player.plane.x = 0;
    player.plane.y = 0.66;
    return player;
}
