/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** floor_cast
*/

#include "../../include/wolf.h"

static floor_cast_t init_floor_cast(game_t *game, int y)
{
    floor_cast_t fc;

    fc.ray_dir0 = (sfVector2f){game->player.dir.x - game->player.plane.x,
        game->player.dir.y - game->player.plane.y};
    fc.ray_dir1 = (sfVector2f){ game->player.dir.x + game->player.plane.x,
        game->player.dir.y + game->player.plane.y};
    fc.row_distance = (float)game->video.height / (2.0f * y - game->video.height);
    fc.step.x = fc.row_distance * (fc.ray_dir1.x - fc.ray_dir0.x) / game->video.width;
    fc.step.y = fc.row_distance * (fc.ray_dir1.y - fc.ray_dir0.y) / game->video.width;
    fc.floor.x = game->player.loc.x + fc.row_distance * fc.ray_dir0.x;
    fc.floor.y = game->player.loc.y + fc.row_distance * fc.ray_dir0.y;
    return fc;
}

void floor_cast(game_t *game)
{
    floor_cast_t fc;
    sfVertex px;
    sfVertexArray *array = sfVertexArray_create();
    int tex_size = 1024;

    for (int y = game->video.height / 2; y != (int)game->video.height; y++) {
        fc = init_floor_cast(game, y);
        for (int x = 0; x < (int)game->video.width; x++) {
            fc.tex_coords.x = (int)(tex_size * (fc.floor.x - (int)fc.floor.x)) & (tex_size - 1);
            fc.tex_coords.y = (int)(tex_size * (fc.floor.y - (int)fc.floor.y)) & (tex_size - 1);
            fc.color = sfImage_getPixel(game->gmtx.floor, fc.tex_coords.x, fc.tex_coords.y);
            px = (sfVertex){.position = (sfVector2f){x, y}, .color = fc.color};
            sfVertexArray_append(array, px);
            fc.floor.x += fc.step.x;
            fc.floor.y += fc.step.y;
        }
    }
    sfRenderTexture_drawVertexArray(game->gmtx.walltx, array, NULL);
    sfVertexArray_destroy(array);
}