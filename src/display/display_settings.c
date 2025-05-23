/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** display_settings
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../include/wolf.h"
#include "../../include/struct.h"
#include <stdbool.h>

void resize_settings_background(menu_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(menu->window);
    sfVector2u texture_size;
    float scale_x;
    float scale_y;

    if (menu->settings_background_texture != NULL) {
        texture_size = sfTexture_getSize(menu->settings_background_texture);
        scale_x = (float)window_size.x / (float)texture_size.x;
        scale_y = (float)window_size.y / (float)texture_size.y;
    } else {
        return;
    }
    if (menu->settings_background_sprite != NULL) {
        sfSprite_setScale(menu->settings_background_sprite,
            (sfVector2f){scale_x, scale_y});
    }
}

void init_settings_background(menu_t *menu)
{
    menu->settings_background_texture =
    sfTexture_createFromFile("Assets/halo_settings.jpg", NULL);
    menu->settings_background_sprite = sfSprite_create();
    sfSprite_setTexture(menu->settings_background_sprite,
        menu->settings_background_texture, sfTrue);
    resize_settings_background(menu);
}

void update_text_positions(text_elemets_t *texts, sfView **view)
{
    sfVector2f center = sfView_getCenter(*view);
    sfVector2f size = sfView_getSize(*view);
    sfFloatRect t = sfText_getGlobalBounds(texts->title);
    sfFloatRect v = sfText_getGlobalBounds(texts->volume);
    sfFloatRect r = sfText_getGlobalBounds(texts->resolution);
    sfFloatRect b = sfText_getGlobalBounds(texts->back);
    sfFloatRect f = sfText_getGlobalBounds(texts->fullscreen);

    sfText_setPosition(texts->title,
        (sfVector2f){center.x - t.width / 2, center.y - size.y / 2 + 80});
    sfText_setPosition(texts->volume,
        (sfVector2f){center.x - v.width / 2, center.y - 100});
    sfText_setPosition(texts->resolution,
        (sfVector2f){center.x - r.width / 2, center.y});
    sfText_setPosition(texts->back,
        (sfVector2f){center.x - b.width / 2, center.y + 200});
    sfText_setPosition(texts->fullscreen,
        (sfVector2f){center.x - f.width / 2, center.y + 100});
}

static void draw_render_settings(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfRenderWindow_clear(*ctx->window, sfBlack);
    sfRenderWindow_drawSprite(*ctx->window,
        menu->settings_background_sprite, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->title, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->volume, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->resolution, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->fullscreen, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->back, NULL);
    sfRenderWindow_display(*ctx->window);
}

static void render_settings_fillcolor(text_elemets_t *texts)
{
    sfText_setFillColor(texts->back, sfWhite);
    sfText_setFillColor(texts->volume, sfWhite);
    sfText_setFillColor(texts->resolution, sfWhite);
    sfText_setFillColor(texts->fullscreen, sfWhite);
}

static void render_settings(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfVector2i mouse_px = sfMouse_getPositionRenderWindow(menu->window);
    sfVector2f ms =
    sfRenderWindow_mapPixelToCoords(menu->window, mouse_px, menu->view);
    sfFloatRect back_bounds = sfText_getGlobalBounds(texts->back);
    sfFloatRect volume_bounds = sfText_getGlobalBounds(texts->volume);
    sfFloatRect resolution_bounds = sfText_getGlobalBounds(texts->resolution);
    sfFloatRect fullscreen_bounds = sfText_getGlobalBounds(texts->fullscreen);

    render_settings_fillcolor(texts);
    if (sfFloatRect_contains(&volume_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->volume, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&resolution_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->resolution, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&back_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->back, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&fullscreen_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->fullscreen, sfColor_fromRGB(116, 201, 238));
    draw_render_settings(ctx, texts, menu);
}

static void init_settings_texts(text_elemets_t *texts, sfFont *font,
    app_context_t *ctx)
{
    char volume_buf[13];
    char *resolutions_texts[2] = {"1920x1080", "1280x720"};

    texts->title = create_menu_text(font, "Settings Menu", (sfVector2f){0, 0});
    texts->back = create_menu_text(font, "Back", (sfVector2f){0, 0});
    texts->volume = sfText_create();
    texts->resolution = sfText_create();
    texts->fullscreen = create_menu_text(font,
        "Fullscreen Mode", (sfVector2f){0, 0});
    sfText_setFillColor(texts->fullscreen, sfWhite);
    sfText_setFont(texts->volume, font);
    sfText_setCharacterSize(texts->volume, 50);
    sfText_setFont(texts->resolution, font);
    sfText_setCharacterSize(texts->resolution, 50);
    snprintf(volume_buf, sizeof(volume_buf), "Volume: %d%%", *ctx->volume);
    sfText_setString(texts->volume, volume_buf);
    sfText_setString(texts->resolution, "Fullscreen Mode Activated");
    if (*ctx->fullscreen_status == 0)
        sfText_setString(texts->resolution,
            resolutions_texts[*ctx->res_index]);
}

static switch_window_state_t handle_event_loop(app_context_t *ctx,
    text_elemets_t *texts, sfEvent *event, menu_t *menu)
{
    sfVector2i px;
    input_context_t input;

    if (event->type == sfEvtClosed)
        return STATE_EXIT;
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        return STATE_MENU;
    if (event->type == sfEvtMouseButtonPressed) {
        px = sfMouse_getPositionRenderWindow(*ctx->window);
        input.event = event;
        input.mouse_pos =
        sfRenderWindow_mapPixelToCoords(*ctx->window, px, *ctx->view);
        return handle_mouse_events(ctx, texts, &input, menu);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyX) {
        return STATE_EXIT;
    }
    return STATE_SETTINGS;
}

void display_settings_loop(app_context_t *ctx, game_t *game,
    text_elemets_t *texts, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(*ctx->window, game->event)
        && game->state == STATE_SETTINGS)
        game->state = handle_event_loop(ctx, texts, game->event, menu);
}

switch_window_state_t display_settings(app_context_t *ctx, game_t *game)
{
    text_elemets_t texts;
    menu_t menu = { .window = game->window, .font = game->app.font,
        .view = game->app.view};

    init_settings_texts(&texts, game->app.font, ctx);
    init_settings_background(&menu);
    while (game->state == STATE_SETTINGS) {
        display_settings_loop(ctx, game, &texts, &menu);
        update_text_positions(&texts, ctx->view);
        render_settings(ctx, &texts, &menu);
        sfRenderWindow_display(game->window);
    }
    destroy_texts(&texts);
    return game->state;
}
