/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** draw_txtr
*/

#include "../../include/wolf.h"
#include <math.h>

static void draw_wall(game_t *game, raycast_t raycast, int i, int texX)
{
    sfIntRect rect;
    sfSprite *sp = sfSprite_create();

    rect.height = TEX_SIZE; 
    rect.left = texX;
    rect.top = 0;
    rect.width = 1;
    sfSprite_setTexture(sp, game->wall[raycast.hit - 1], false);
    sfSprite_setTextureRect(sp, rect);
    sfSprite_setPosition(sp, (sfVector2f){.x = i, game->video.height / 2 - raycast.len / 2});
    sfSprite_setScale(sp, (sfVector2f){.x = 1 , .y = raycast.len / 64});
    sfRenderWindow_drawSprite(game->window, sp, NULL);
    if (raycast.side == 1 && !sfKeyboard_isKeyPressed(sfKeyF))
        draw_ray(game, raycast, i);
    sfSprite_destroy(sp);
}

void draw_txtr(game_t *game, raycast_t raycast, int i)
{
    float distance = raycast.side == 0
        ? raycast.side_dist.x - raycast.delta_dist.x
        : raycast.side_dist.y - raycast.delta_dist.y;
    float wallX = raycast.side == 0
        ? game->player.loc.y + distance * raycast.ray_dir.y
        : game->player.loc.x + distance * raycast.ray_dir.x;
    int texX;
    
    wallX -= floorf(wallX);
    texX = (int)(wallX * TEX_SIZE);
    raycast.len = distance > 0
        ? game->video.height / distance
        : game->video.height / 0.01f;
    if ((raycast.side == 0 && raycast.ray_dir.x > 0) ||
        (raycast.side == 1 && raycast.ray_dir.y > 0))
        texX = TEX_SIZE - texX - 1;
    draw_wall(game, raycast, i, texX);
}
