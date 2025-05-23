/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_overlay
*/

#include "../../include/wolf.h"

sfSprite *init_crosshair(game_t *game)
{
    sfTexture *tx = sfTexture_createFromFile("Assets/crosshair.png", NULL);
    sfSprite *sp = sfSprite_create();
    float scale = 30;

    sfSprite_setTexture(sp, tx, sfFalse);
    sfSprite_setColor(sp, sfRed);
    sfSprite_setPosition(sp, (sfVector2f){
        .x = game->video.width / 2,
        .y = game->video.height / 2});
    sfSprite_setScale(sp, (sfVector2f){scale, scale});
    return sp;
}

context_t init_overlay(game_t *game)
{
    context_t ctx;
    sfSoundBuffer *fire_buf =
        sfSoundBuffer_createFromFile("Assets/fire_b.wav");
    sfSoundBuffer *reload_buf =
        sfSoundBuffer_createFromFile("Assets/load.wav");
    sfVector2f scale = {1.3f, 1.3f};
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    sfVector2f offset = {60.f, 70.f};

    ctx.reload = sfSound_create();
    ctx.fire = sfSound_create();
    sfSound_setBuffer(ctx.fire, fire_buf);
    sfSound_setBuffer(ctx.reload, reload_buf);
    ctx.weapon = create_weapon("Assets/weapon.png", win_size, scale, offset);
    ctx.hud = create_hud("Assets/hud2.png");
    ctx.ammo = create_ammo_display();
    ctx.crosshair = init_crosshair(game);
    return ctx;
}
