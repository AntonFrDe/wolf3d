/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** dda
*/

#include "../../include/wolf.h"

raycast_t calc_dda(game_t *game, raycast_t raycast)
{
    sfVector2i map = {.x = (int)game->player.loc.x,
        .y = (int)game->player.loc.y};

    raycast.side = 0;
    while (raycast.hit == 0) {
        if (raycast.side_dist.x < raycast.side_dist.y) {
            raycast.side_dist.x += raycast.delta_dist.x;
            map.x += raycast.steps.x;
            raycast.side = 0;
        } else {
            raycast.side_dist.y += raycast.delta_dist.y;
            map.y += raycast.steps.y;
            raycast.side = 1;
        }
        raycast.hit = game->map[map.y][map.x];
    }
    return raycast;
}
