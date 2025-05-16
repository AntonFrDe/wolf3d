/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** settings_mouse_events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../raycasting3/include/wolf.h"
#include "../../raycasting3/include/struct.h"
#include <stdbool.h>

static void handle_volume_click(input_context_t *input,
    app_context_t *ctx, text_elemets_t *texts)
{
    char buf[13];

    if (input->event->mouseButton.button == sfMouseLeft && *ctx->volume < 100)
        *ctx->volume += 10;
    if (input->event->mouseButton.button == sfMouseRight && *ctx->volume > 0)
        *ctx->volume -= 10;
    snprintf(buf, sizeof(buf), "Volume: %d%%", *ctx->volume);
    sfText_setString(texts->volume, buf);
    if (ctx->music)
        sfMusic_setVolume(ctx->music, *ctx->volume);
}

void update_resolution_fullscreen_status_activated(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    sfRenderWindow_setSize(*ctx->window,
        (sfVector2u){mode.width, mode.height});
    sfView_setSize(*ctx->view, (sfVector2f){mode.width, mode.height});
    sfView_setCenter(*ctx->view,
        (sfVector2f){mode.width / 2.0f, mode.height / 2.0f});
    sfRenderWindow_setView(*ctx->window, *ctx->view);
    sfText_setString(texts->resolution, "Fullscreen Mode Activated");
    resize_settings_background(menu);
    resize_background(menu);
}

void update_resolution(app_context_t *ctx, text_elemets_t *texts,
    menu_t *menu, int fullscreen_status)
{
    sfVector2u resolutions[2] = {{1920, 1080}, {1280, 720}};
    char *labels[2] = {"1920x1080", "1280x720"};
    int index = *ctx->res_index;
    sfVector2f size = {(float)resolutions[index].x,
        (float)resolutions[index].y};

    if (fullscreen_status == 1) {
        update_resolution_fullscreen_status_activated(ctx,
            texts, menu);
        return;
    }
    sfView_setSize(*ctx->view, size);
    resize_background(menu);
    sfView_setCenter(*ctx->view, (sfVector2f){size.x / 2, size.y / 2});
    sfRenderWindow_setView(*ctx->window, *ctx->view);
    sfRenderWindow_setSize(*ctx->window, resolutions[index]);
    sfText_setString(texts->resolution, labels[index]);
    resize_settings_background(menu);
}

static void handle_mouse_click_fullscreen_mode(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfColor fullscreen_color;

    update_resolution(ctx, texts, menu, 1);
    *ctx->fullscreen_status = 1;
    fullscreen_color = sfText_getFillColor(texts->fullscreen);
    if (fullscreen_color.r == sfWhite.r &&
        fullscreen_color.g == sfWhite.g &&
        fullscreen_color.b == sfWhite.b &&
        fullscreen_color.a == sfWhite.a) {
        sfText_setFillColor(texts->fullscreen, sfColor_fromRGB(116, 201, 238));
        texts->fullscreen_status = 1;
    }
}

switch_window_state_t handle_mouse_events_old(app_context_t *ctx,
    text_elemets_t *texts, input_context_t *input, menu_t *menu)
{
    sfFloatRect vol = sfText_getGlobalBounds(texts->volume);
    sfFloatRect res = sfText_getGlobalBounds(texts->resolution);
    sfFloatRect back = sfText_getGlobalBounds(texts->back);
    sfFloatRect fullscreen_bounds = sfText_getGlobalBounds(texts->fullscreen);

    if (sfFloatRect_contains(&back, input->mouse_pos.x, input->mouse_pos.y))
        return STATE_MENU;
    if (sfFloatRect_contains(&vol, input->mouse_pos.x, input->mouse_pos.y))
        handle_volume_click(input, ctx, texts);
    if (sfFloatRect_contains(&res, input->mouse_pos.x, input->mouse_pos.y)) {
        *ctx->res_index = (*ctx->res_index + 1) % 2;
        update_resolution(ctx, texts, menu, 0);
        *ctx->fullscreen_status = 0;
        sfText_setFillColor(texts->fullscreen, sfWhite);
    }
    if (sfFloatRect_contains(&fullscreen_bounds, input->mouse_pos.x,
        input->mouse_pos.y)) {
        handle_mouse_click_fullscreen_mode(ctx, texts, menu);
    }
    return STATE_SETTINGS;
}
