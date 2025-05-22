/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Event handling
*/

#include "../../include/wolf.h"
#include "math.h"

static void fire_event(context_t *ctx, sfSound *fire)
{
    if (!ctx->weapon.is_shooting && !ctx->weapon.is_reloading
        && ctx->ammo.ammo > 0) {
        ctx->weapon.is_shooting = 1;
        ctx->weapon.shoot_offset = 0;
        ctx->ammo.ammo--;
        ctx->weapon.is_fire_shooting = sfTrue;
        ctx->weapon.shoot_index = 0;
        ctx->weapon.shoot_timer = 0;
        sfSprite_setTextureRect(ctx->weapon.shoot_sprite, ctx->weapon.shoot_frames[0]);
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

void handle_events(game_t *game)
{
    if (game->event->type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event->type == sfEvtMouseButtonPressed
        && game->event->mouseButton.button == sfMouseLeft)
        fire_event(&game->context, game->context.fire);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        reload_event(&game->context, game->context.reload);
    if (sfKeyboard_isKeyPressed(sfKeyF))
        game->context.weapon.is_flash = game->context.weapon.is_flash == 0;
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        game->fps = game->fps == sfTrue ? sfFalse : sfTrue;
        printf("fps : %.2f\n", 1 / game->delta);
    }
}
