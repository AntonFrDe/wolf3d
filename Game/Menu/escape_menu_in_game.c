/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** escape_menu_in_game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../raycasting3/include/wolf.h"
#include "../../raycasting3/include/struct.h"
#include <stdbool.h>

void destroy_texts_in_game(text_elemets_t *texts)
{
    sfText_destroy(texts->title);
    sfText_destroy(texts->volume);
    sfText_destroy(texts->play);
    sfText_destroy(texts->save);
    sfText_destroy(texts->back);
}

switch_window_state_t handle_mouse_events_in_game(app_context_t *ctx,
    text_elemets_t *texts, input_context_t *input, menu_t *menu)
{
    sfFloatRect play = sfText_getGlobalBounds(texts->play);
    sfFloatRect save = sfText_getGlobalBounds(texts->save);
    sfFloatRect back = sfText_getGlobalBounds(texts->back);

    if (sfFloatRect_contains(&play,
        input->mouse_pos.x, input->mouse_pos.y))
        return STATE_GAME;

    if (sfFloatRect_contains(&save,
        input->mouse_pos.x, input->mouse_pos.y)) {
        printf("The game is saved!\n");
        return STATE_SETTINGS_IN_GAME;
    }

    return STATE_SETTINGS_IN_GAME;
}

static void init_settings_background(menu_t *menu)
{
    menu->settings_background_texture =
    sfTexture_createFromFile("../Game/Menu/Assets/halo_settings.jpg", NULL);
    menu->settings_background_sprite = sfSprite_create();
    sfSprite_setTexture(menu->settings_background_sprite,
        menu->settings_background_texture, sfTrue);
    resize_settings_background(menu);
}

static void update_text_positions(text_elemets_t *texts, sfView **view)
{
    sfVector2f center = sfView_getCenter(*view);
    sfVector2f size = sfView_getSize(*view);
    sfFloatRect t = sfText_getGlobalBounds(texts->title);

    sfText_setPosition(texts->title,
        (sfVector2f){center.x - t.width / 2, center.y - size.y / 2 + 80});
    sfText_setPosition(texts->play,
        (sfVector2f){center.x - 100, center.y - 100});
    sfText_setPosition(texts->save,
        (sfVector2f){center.x - 100, center.y});
    sfText_setPosition(texts->volume,
        (sfVector2f){center.x - 100, center.y + 100});
    sfText_setPosition(texts->back,
        (sfVector2f){center.x - 100, center.y + 200});
}

static void draw_render_settings(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfRenderWindow_clear(*ctx->window, sfBlack);
    sfRenderWindow_drawSprite(*ctx->window,
        menu->settings_background_sprite, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->title, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->play, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->save, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->volume, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->back, NULL);
    sfRenderWindow_display(*ctx->window);
}

static void render_settings_fillcolor(text_elemets_t *texts)
{
    sfText_setFillColor(texts->play, sfWhite);
    sfText_setFillColor(texts->save, sfWhite);
    sfText_setFillColor(texts->volume, sfWhite);
    sfText_setFillColor(texts->back, sfWhite);
}

static void render_settings(app_context_t *ctx,
    text_elemets_t *texts, menu_t *menu)
{
    sfVector2i mouse_px = sfMouse_getPositionRenderWindow(menu->window);
    sfVector2f ms = sfRenderWindow_mapPixelToCoords(menu->window, mouse_px, menu->view);
    sfFloatRect play_bounds = sfText_getGlobalBounds(texts->play);
    sfFloatRect save_bounds = sfText_getGlobalBounds(texts->save);
    sfFloatRect volume_bounds = sfText_getGlobalBounds(texts->volume);
    sfFloatRect back_bounds = sfText_getGlobalBounds(texts->back);

    render_settings_fillcolor(texts);
    if (sfFloatRect_contains(&play_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->play, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&save_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->save, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&volume_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->volume, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&back_bounds, ms.x, ms.y))
        sfText_setFillColor(texts->back, sfColor_fromRGB(116, 201, 238));

    draw_render_settings(ctx, texts, menu);
}

static void init_settings_texts(text_elemets_t *texts, sfFont *font,
    int volume)
{
    char volume_buf[13];

    texts->title = create_menu_text(font, "Settings", (sfVector2f){0, 0});
    texts->back = create_menu_text(font, "Back to Main Menu", (sfVector2f){0, 0});
    texts->volume = sfText_create();
    texts->play = create_menu_text(font, "Play", (sfVector2f){0, 0});
    texts->save = create_menu_text(font, "Save", (sfVector2f){0, 0});

    sfText_setFont(texts->volume, font);
    sfText_setCharacterSize(texts->volume, 50);
    sfText_setFillColor(texts->volume, sfWhite);

    snprintf(volume_buf, sizeof(volume_buf), "Volume: %d%%", volume);
    sfText_setString(texts->volume, volume_buf);
}

static switch_window_state_t handle_event_loop(app_context_t *ctx,
    text_elemets_t *texts, sfEvent *event, menu_t *menu)
{
    sfVector2i px;
    input_context_t input;

    if (event->type == sfEvtClosed)
        return STATE_EXIT;
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        return STATE_GAME;
    if (event->type == sfEvtMouseButtonPressed) {
        px = sfMouse_getPositionRenderWindow(*ctx->window);
        input.event = event;
        input.mouse_pos =
        sfRenderWindow_mapPixelToCoords(*ctx->window, px, *ctx->view);
        return handle_mouse_events_in_game(ctx, texts, &input, menu);
    }
    return STATE_SETTINGS_IN_GAME;
}

static switch_window_state_t display_settings_loop(app_context_t *ctx,
    switch_window_state_t state,
    text_elemets_t *texts, sfEvent *event, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(*ctx->window, event)) {
        state = handle_event_loop(ctx, texts, event, menu);
        if (state != STATE_SETTINGS_IN_GAME) {
            destroy_texts_in_game(texts);
            return state;
        }
    }
    return state;
}

switch_window_state_t display_settings_in_game(app_context_t *ctx,
    sfFont *font, sfView *view, sfRenderWindow *window)
{
    text_elemets_t texts;
    sfEvent event;
    switch_window_state_t state = STATE_SETTINGS_IN_GAME;
    menu_t menu = { .window = window, .font = font, .view = view };

    init_settings_texts(&texts, font, *ctx->volume);
    init_settings_background(&menu);
    while (sfRenderWindow_isOpen(*ctx->window)) {
        state = display_settings_loop(ctx, state, &texts, &event, &menu);
        if (state != STATE_SETTINGS_IN_GAME) {
            return state;
        }
        update_text_positions(&texts, ctx->view);
        render_settings(ctx, &texts, &menu);
    }
    destroy_texts_in_game(&texts);
    return STATE_SETTINGS_IN_GAME;
}