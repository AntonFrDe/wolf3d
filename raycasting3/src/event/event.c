/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Event handling
*/

#include "../../include/wolf.h"

void handle_events(context_t *ctx, sfEvent event,
    sfSound *fire, sfSound *reload)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(ctx->window);
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
        if (!ctx->weapon.is_shooting && !ctx->weapon.is_reloading && ctx->ammo.ammo > 0) {
            ctx->weapon.is_shooting = 1;
            ctx->weapon.shoot_offset = 0;
            ctx->ammo.ammo--;
            update_ammo_text(&ctx->ammo);
            sfSound_play(fire);
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
        if (!ctx->weapon.is_reloading && ctx->ammo.ammo < 32) {
            ctx->weapon.is_reloading = 1;
            ctx->weapon.reload_offset = 0;
            sfSound_play(reload);
        }
    }
}
