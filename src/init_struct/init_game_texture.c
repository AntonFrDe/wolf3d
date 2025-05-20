/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** init_game_texture
*/

#include "../../include/wolf.h"

wall_tx_t *init_walltx(game_txtr_t game_tx)
{
    game_tx.wtx = malloc(sizeof(wall_tx_t) * 5);

    game_tx.wtx[0].size = 1024;
    game_tx.wtx[0].tx = sfTexture_createFromFile("Assets/pics/Bwall.png", NULL);
    game_tx.wtx[1].size = 1024;
    game_tx.wtx[1].tx = sfTexture_createFromFile("Assets/pics/RRwall.png", NULL);
    return game_tx.wtx;
}

game_txtr_t init_game_texture(game_t *game)
{
    game_txtr_t game_tx;
    sfTexture *tx = sfTexture_createFromFile("Assets/sky.jpg", NULL);

    game_tx.wall = malloc(sizeof(sfTexture *) * 8);
    game_tx.wall = init_wall(game_tx.wall);
    game_tx.wtx = malloc(sizeof(wall_tx_t) * 2);
    game_tx.wtx = init_walltx(game_tx);
    game_tx.skybg = sfSprite_create();
    sfSprite_setTexture(game_tx.skybg, tx, false);
    sfSprite_setPosition(game_tx.skybg, (sfVector2f){.x = 0, .y = 0});
    game_tx.walltx = sfRenderTexture_create(game->video.width, game->video.height, sfFalse);
    game_tx.wallsp = sfSprite_create();
    game_tx.floor = sfImage_createFromFile("Assets/pics/purplestone.png");
    sfSprite_setTexture(game_tx.wallsp, sfRenderTexture_getTexture(game_tx.walltx), sfTrue);
    return game_tx;
}