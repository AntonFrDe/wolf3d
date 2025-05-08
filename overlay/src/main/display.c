/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Drawing to screen
*/

#include "../../include/context.h"
#include <SFML/Graphics.h>

void display_all(context_t *ctx)
{
    // sfRenderWindow_clear(ctx->window, sfBlack);
    sfRenderWindow_drawSprite(ctx->window, ctx->weapon.sprite, NULL);
    draw_hud(ctx->window, &ctx->hud);
    sfRenderWindow_drawText(ctx->window, ctx->ammo.text, NULL);
    sfRenderWindow_display(ctx->window);
}
