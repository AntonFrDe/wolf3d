/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** minimap
*/


#include "../../include/wolf.h"

#define TILE_SIZE 10
#define MINIMAP_SCALE 0.2f


static void draw_tile(sfRenderWindow *window, sfVector2f pos, sfColor color)
{
    sfRectangleShape *tile = sfRectangleShape_create();
    sfVector2f size = {TILE_SIZE, TILE_SIZE};

    sfRectangleShape_setSize(tile, size);
    sfRectangleShape_setFillColor(tile, color);
    sfRectangleShape_setPosition(tile, pos);
    sfRenderWindow_drawRectangleShape(window, tile, NULL);
    sfRectangleShape_destroy(tile);
}

void draw_minimap(game_t *game)
{
    for (int y = 0; y < (int)game->video.height / TILE_SIZE; y++) {
        for (int x = 0; x < (int)game->video.width / TILE_SIZE; x++) {
            if (y < (int)game->map_size.y && x < (int)game->map_size.x) {
                int tile = game->map[y][x];
                sfColor color = sfColor_fromRGB(30, 30, 30);
                if (tile == 1)
                    color = sfColor_fromRGB(200, 200, 200);
                else if (tile == 2)
                    color = sfColor_fromRGB(255, 100, 100);
                else if (tile == 3)
                    color = sfColor_fromRGB(200, 0, 200);
                else if (tile == 4)
                    color = sfColor_fromRGB(50, 100, 200);
                draw_tile(game->window,
                    (sfVector2f){x * TILE_SIZE, y * TILE_SIZE}, color);
            }
        }
    }
    sfColor player_color = sfGreen;
    float px = game->player.loc.x * TILE_SIZE;
    float py = game->player.loc.y * TILE_SIZE;
    draw_tile(game->window, (sfVector2f){px, py}, player_color);
    sfVertex line[2];
    line[0].position = (sfVector2f){px + TILE_SIZE / 2, py + TILE_SIZE / 2};
    line[0].color = sfRed;
    line[1].position = (sfVector2f){
        px + game->player.dir.x * TILE_SIZE * 2 + TILE_SIZE / 2,
        py + game->player.dir.y * TILE_SIZE * 2 + TILE_SIZE / 2};
    line[1].color = sfRed;
    sfRenderWindow_drawPrimitives(game->window, line, 2, sfLines, NULL);
}
