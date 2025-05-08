/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** main
*/

#include "../include/wolf.h"
#include <stdlib.h>
#include "../include/struct.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>

void destroy_app(app_t *app)
{
    sfFont_destroy(app->font);
    sfRenderWindow_destroy(app->window);
}

void init_window(app_t *app, game_t *game)
{
    app->window = game->window;
    app->font = sfFont_createFromFile("../Game/Menu/Assets/Halo.ttf");
    app->view = sfView_create();
}

void init_view(app_t *app)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);

    sfView_setSize(app->view, (sfVector2f){size.x, size.y});
    sfView_setCenter(app->view, (sfVector2f){size.x / 2.f, size.y / 2.f});
    sfRenderWindow_setView(app->window, app->view);
}

void init_music(app_t *app)
{
    app->music = sfMusic_createFromFile("../Game/Menu/Assets/halo_music.ogg");
    sfMusic_setLoop(app->music, sfTrue);
    sfMusic_setVolume(app->music, app->volume);
    sfMusic_play(app->music);
}

int process_game_state(switch_window_state_t *state, app_t *app, game_t *game)
{
    if (*state != STATE_GAME)
        return 0;
    display_game(game);
    free(game);
    sfMusic_destroy(app->music);
    return 0;
}

int process_state(switch_window_state_t *state, app_t *app, game_t *game)
{
    app_context_t ctx;

    if (*state == STATE_MENU)
        *state = display_menu(app->window, app->font, app->view);
    else if (*state == STATE_SETTINGS) {
        ctx.window = &app->window;
        ctx.view = &app->view;
        ctx.music = app->music;
        ctx.volume = &app->volume;
        ctx.res_index = &app->res_index;
        ctx.is_fullscreen = false;
        ctx.fullscreen_status = &app->fullscreen_status;
        *state = display_settings(&ctx, app->font, app->view, app->window);
    }
    else
        return process_game_state(state, app, game);
    return 0;
}

int main(void)
{
    switch_window_state_t state = STATE_MENU;
    app_t app = {0};
    game_t *game = init_game();

    app.volume = 50;
    init_window(&app, game);
    init_view(&app);
    init_music(&app);
    app.fullscreen_status = 0;
    while (sfRenderWindow_isOpen(app.window) && state != STATE_EXIT) {
        if (process_state(&state, &app, game) == 84)
            return 84;
    }
    destroy_app(&app);
    return 0;
}