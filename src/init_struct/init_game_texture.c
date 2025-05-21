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
    game_tx.wtx[0].tx = sfTexture_createFromFile("Assets/pics/reach.png"
        , NULL);
    game_tx.wtx[1].size = 1024;
    game_tx.wtx[1].tx = sfTexture_createFromFile("Assets/pics/r_wal.png"
        , NULL);
    game_tx.wtx[2].size = 1024;
    game_tx.wtx[2].tx = sfTexture_createFromFile("Assets/pics/door.png"
        , NULL);
    game_tx.wtx[3].size = 1024;
    game_tx.wtx[3].tx = sfTexture_createFromFile("Assets/pics/blood.png"
        , NULL);
    return game_tx.wtx;
}

game_txtr_t init_game_texture(game_t *game)
{
    game_txtr_t game_tx;
    sfTexture *tx = sfTexture_createFromFile("Assets/sky_bg.jpg", NULL);
    sfIntRect rect = {0, 0, 0, 0};
    sfVector2f loc = {0, 0};

    rect.height = game->video.height / 2;
    rect.width = game->video.width;
    game_tx.wtx = init_walltx(game_tx);
    game_tx.skybg = sfSprite_create();
    sfTexture_setRepeated(tx, sfTrue);
    sfSprite_setTexture(game_tx.skybg, tx, false);
    sfSprite_setTextureRect(game_tx.skybg, rect);
    sfSprite_setPosition(game_tx.skybg, loc);
    game_tx.walltx = sfRenderTexture_create(game->video.width,
        game->video.height, sfFalse);
    game_tx.wallsp = sfSprite_create();
    game_tx.floor = sfImage_createFromFile("Assets/ground_futur.png");
    sfSprite_setTexture(game_tx.wallsp,
        sfRenderTexture_getTexture(game_tx.walltx), sfTrue);
    return game_tx;
}
