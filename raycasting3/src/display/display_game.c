/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_game
*/

#include "../../include/wolf.h"

static switch_window_state_t context_setting(game_t *game)
{
    app_context_t ctx;

    ctx.window = &game->window;
    ctx.view = &game->app.view;
    ctx.music = game->app.music;
    ctx.volume = &game->app.volume;
    ctx.res_index = &game->app.res_index;
    ctx.is_fullscreen = false;
    ctx.fullscreen_status = &game->app.fullscreen_status;
    return display_settings(&ctx, game);
}

static int display_scene(game_t *game)
{
    switch (game->state) {
        case STATE_MENU:
            printf("MENU\n");
            game->state = display_menu(game);
            break;
        case STATE_SETTINGS:
            printf("SETTINGS\n");
            game->state = context_setting(game);
            break;
        case STATE_GAME:
            printf("GAME\n");
            game->state = play_game(game);
            break;
        case STATE_EXIT:
            return 1;
    }
    return 0;
}

void display_game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        if (display_scene(game) == 1)
            break;
    }
}
