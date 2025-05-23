/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** play_game
*/

#include "../../include/wolf.h"

static void handle_events_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, game->event)) {
        if (game->event->type == sfEvtClosed)
            game->state = STATE_EXIT;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->state = STATE_MENU_IN_GAME;
        handle_events(game);
    }
    event_handling(game);
}

static void update_game(game_t *game)
{
    cast_ray(game);
    sfMouse_setPositionRenderWindow(
        (sfVector2i){game->video.width / 2, game->video.height / 2},
        game->window
    );
    mooving_mob(game);
}

static void render_game(game_t *game, sfSprite *crosshair_sprite)
{
    char *nb = malloc(MAX_FPS_SIZE);

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->gmtx.wallsp, NULL);
    if (game->context.weapon.is_fire_shooting) {
        sfSprite_setPosition(game->context.weapon.shoot_sprite,
            game->context.shoot_fire_pos);
        game->context.shoot_fire_pos.y -= 3;
        sfRenderWindow_drawSprite(game->window,
            game->context.weapon.shoot_sprite, NULL);
    }
    display_hud(game);
    draw_minimap(game);
    if (game->fps) {
        sprintf(nb, "%.0f", 1 / game->delta);
        draw_text_at(game, nb, (sfVector2f){0, 0}, 50);
    }
    sfRenderWindow_drawSprite(game->window, crosshair_sprite, NULL);
    sfRenderWindow_display(game->window);
    free(nb);
}

static void update_flash(context_t *ctx)
{
    ctx->weapon.shoot_timer += 1;
    if (ctx->weapon.shoot_timer > 1) {
        ctx->weapon.shoot_timer = 0;
        ctx->weapon.shoot_index += 1;
        if (ctx->weapon.shoot_index >= 3) {
            ctx->shoot_fire_pos.x = 1110;
            ctx->shoot_fire_pos.y = 350;
            ctx->weapon.is_fire_shooting = sfFalse;
        } else {
            sfSprite_setTextureRect(ctx->weapon.shoot_sprite,
                ctx->weapon.shoot_frames[ctx->weapon.shoot_index]
            );
        }
    }
}

sfSprite *init_crosshair_game(game_t *game)
{
    float scale = 0.2f;
    sfTexture *crosshair_texture = sfTexture_createFromFile("Assets/crossair.png", NULL);
    sfSprite *crosshair_sprite = sfSprite_create();

    sfSprite_setTexture(crosshair_sprite, crosshair_texture, sfTrue);
    sfSprite_setPosition(crosshair_sprite, (sfVector2f){game->video.width / 2 - 50, (game->video.height / 2) - 50});
    sfSprite_setScale(crosshair_sprite, (sfVector2f){scale, scale});\
    return crosshair_sprite;
}

switch_window_state_t play_game(game_t *game)
{
    sfSprite *crosshair_sprite;

    game->context = init_overlay(game);
    game->gmtx = init_game_texture(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->clock = sfClock_create();
    game->context.shoot_fire_pos = (sfVector2f){1110, 350};
    game->mob.anim = sfClock_create();
    crosshair_sprite = init_crosshair_game(game);
    while (game->state == STATE_GAME) {
        handle_events_loop(game);
        update_flash(&game->context);
        update_game(game);
        render_game(game, crosshair_sprite);
        game->delta = sfTime_asSeconds(sfClock_restart(game->clock));
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    return game->state;
}
