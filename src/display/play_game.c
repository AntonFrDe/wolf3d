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
}

static void render_game(game_t *game)
{
    char *nb = malloc(MAX_FPS_SIZE);

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->gmtx.wallsp, NULL);
    display_hud(game);
    draw_minimap(game);
    if (game->fps) {
        sprintf(nb, "%.0f", 1 / game->delta);
        draw_text_at(game, nb, (sfVector2f){0, 0});
    }
    sfRenderWindow_display(game->window);
}

switch_window_state_t play_game(game_t *game)
{
    game->context = init_overlay(game);
    game->gmtx = init_game_texture(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->clock = sfClock_create();
    while (game->state == STATE_GAME) {
        handle_events_loop(game);
        update_game(game);
        render_game(game);
        game->delta = sfTime_asSeconds(sfClock_restart(game->clock));
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    return game->state;
}
