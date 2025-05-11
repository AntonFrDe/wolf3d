/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_hud
*/

#include "../../include/wolf.h"

void display_hud(game_t *game)
{
    update_weapon(&game->context.weapon, &game->context.ammo,
    sfRenderWindow_getSize(game->window));
    sfRenderWindow_drawSprite(game->window, game->context.weapon.sprite, NULL);
    draw_hud(game->window, &game->context.hud);
    sfRenderWindow_drawText(game->window, game->context.ammo.text, NULL);
}
