/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Event handling
*/

#include "../../include/wolf.h"

static void fire_event(context_t *ctx, sfSound *fire)
{
    if (!ctx->weapon.is_shooting && !ctx->weapon.is_reloading && ctx->ammo.ammo > 0) {
        ctx->weapon.is_shooting = 1;
        ctx->weapon.shoot_offset = 0;
        ctx->ammo.ammo--;
        update_ammo_text(&ctx->ammo);
        sfSound_play(fire);
    }
}

static void reload_event(context_t *ctx, sfSound *reload)
{
    if (!ctx->weapon.is_reloading && ctx->ammo.ammo < 32) {
        ctx->weapon.is_reloading = 1;
        ctx->weapon.reload_offset = 0;
        sfSound_play(reload);
    }
}

void handle_events(context_t *ctx, sfEvent event,
    sfSound *fire, sfSound *reload)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(ctx->window);
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft)
        fire_event(ctx, fire);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
        reload_event(ctx, reload);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
        ctx->weapon.is_flash = ctx->weapon.is_flash == 0;
}
