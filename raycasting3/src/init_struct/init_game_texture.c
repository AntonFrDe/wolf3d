/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** init_game_texture
*/

#include "../../include/wolf.h"

game_txtr_t init_game_texture(game_t *game)
{
    game_txtr_t game_tx;
    sfTexture *tx = sfTexture_createFromFile("Assets/sky_bg.jpg", NULL);

    game_tx.wall = malloc(sizeof(sfTexture *) * 8);
    game_tx.wall = init_wall(game_tx.wall);
    game_tx.skybg = sfSprite_create();
    sfSprite_setTexture(game_tx.skybg, tx, false);
    sfSprite_setPosition(game_tx.skybg, (sfVector2f){.x = 0, .y = 0});
    game_tx.walltx = sfRenderTexture_create(game->video.width, game->video.height, sfFalse);
    game_tx.wallsp = sfSprite_create();
    sfSprite_setTexture(game_tx.wallsp, sfRenderTexture_getTexture(game_tx.walltx), sfTrue);
    return game_tx;
}