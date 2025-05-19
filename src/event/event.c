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

static void rotate_player(game_t *game, float angle)
{
    float cos_a = cos(angle);
    float sin_a = sin(angle);
    float old_dir_x = game->player.dir.x;
    float old_plane_x = game->player.plane.x;

    game->player.dir.x = old_dir_x * cos_a - game->player.dir.y * sin_a;
    game->player.dir.y = old_dir_x * sin_a + game->player.dir.y * cos_a;
    game->player.plane.x = old_plane_x * cos_a - game->player.plane.y * sin_a;
    game->player.plane.y = old_plane_x * sin_a + game->player.plane.y * cos_a;
}

static void turn_event(game_t *game)
{
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_loc.x > (int)game->video.width / 2)
        rotate_player(game, -0.01f);
    if (mouse_loc.x < (int)game->video.width / 2)
        rotate_player(game, 0.01f);
}

void handle_events(game_t *game)
{
    if (game->event->type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event->type == sfEvtMouseButtonPressed
        && game->event->mouseButton.button == sfMouseLeft)
        fire_event(&game->context, game->context.fire);
    if (game->event->type == sfEvtKeyPressed && game->event->key.code == sfKeyR)
        reload_event(&game->context, game->context.reload);
    if (game->event->type == sfEvtKeyPressed && game->event->key.code == sfKeyF)
        game->context.weapon.is_flash = game->context.weapon.is_flash == 0;
    turn_event(game);
}
