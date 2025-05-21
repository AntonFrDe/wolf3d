/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** minimap
*/

#include "../../include/wolf.h"

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

static void draw_wall(game_t *game, int x, int y)
{
    sfColor color;

    if (y < (int)game->map_size.y && x < (int)game->map_size.x) {
        switch (game->map[y][x]) {
        case 0:
            color = sfBlack;
            break;
        case 1:
            color = sfColor_fromRGB(200, 200, 200);
            break;
        default:
            color = sfColor_fromRGB(255, 100, 100);
            break;
        }
        draw_tile(game->window, (sfVector2f){x * TILE_SIZE + 180,
                game->video.height - y * TILE_SIZE - 100}, color);
    }
}

void draw_minimap(game_t *game)
{
    sfColor player_color = sfBlue;
    float px = game->player.loc.x * TILE_SIZE + 180;
    float py = game->video.height - game->player.loc.y * TILE_SIZE - 100;
    sfVertex line[2];

    for (int y = 0; y < (int)game->video.height / TILE_SIZE; y++)
        for (int x = 0; x < (int)game->video.width / TILE_SIZE; x++)
            draw_wall(game, x, y);
    draw_tile(game->window, (sfVector2f){px, py}, player_color);
    line[0].position = (sfVector2f){px + TILE_SIZE / 2, py + TILE_SIZE / 2};
    line[0].color = sfBlue;
    line[1].position = (sfVector2f){
        px + game->player.dir.x * TILE_SIZE * 2 + TILE_SIZE / 2,
        py + game->player.dir.y * TILE_SIZE * 2 + TILE_SIZE / 2};
    line[1].position.y = 2 * line[0].position.y - line[1].position.y;
    line[1].color = sfBlue;
    sfRenderWindow_drawPrimitives(game->window, line, 2, sfLines, NULL);
}
