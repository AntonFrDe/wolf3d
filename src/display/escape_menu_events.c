/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** escape_menu_events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../include/wolf.h"
#include "../../include/struct.h"
#include <stdbool.h>

void resize_background_in_game(menu_t *menu)
{
    sfVector2u win_size = sfRenderWindow_getSize(menu->window);
    sfVector2u tex_size;
    float scale_x;
    float scale_y;

    if (menu->settings_background_texture != NULL) {
        tex_size = sfTexture_getSize(menu->settings_background_texture);
        scale_x = (float)win_size.x / (float)tex_size.x;
        scale_y = (float)win_size.y / (float)tex_size.y;
    } else {
        return;
    }
    if (menu->settings_background_sprite != NULL) {
        sfSprite_setScale(menu->settings_background_sprite,
            (sfVector2f){scale_x, scale_y});
    }
}

void write_volume_on_window(sfText *text, int volume)
{
    char buf[13];

    snprintf(buf, sizeof(buf), "Volume: %d%%", volume);
    sfText_setString(text, buf);
}

static void change_volume(text_elemets_t *texts,
    sfMouseButton button, app_context_t *ctx)
{
    if (button == sfMouseRight && *ctx->volume > 0)
        *ctx->volume = *ctx->volume - 10;
    else if (button == sfMouseLeft && *ctx->volume < 100)
        *ctx->volume = *ctx->volume + 10;
    write_volume_on_window(texts->volume, *ctx->volume);
    if (ctx->music)
        sfMusic_setVolume(ctx->music, *ctx->volume);
}

static switch_window_state_t handle_mouse_click(text_elemets_t *texts,
    sfVector2f mouse_coordinates, sfMouseButton button, app_context_t *ctx)
{
    sfFloatRect save = sfText_getGlobalBounds(texts->save);
    sfFloatRect play = sfText_getGlobalBounds(texts->play);
    sfFloatRect exit = sfText_getGlobalBounds(texts->exit);
    sfFloatRect volume = sfText_getGlobalBounds(texts->volume);

    if (sfFloatRect_contains(&save, mouse_coordinates.x,
        mouse_coordinates.y)) {
        printf("the game is saved\n");
        return STATE_MENU_IN_GAME;
    }
    if (sfFloatRect_contains(&play, mouse_coordinates.x, mouse_coordinates.y))
        return STATE_GAME;
    if (sfFloatRect_contains(&exit, mouse_coordinates.x, mouse_coordinates.y))
        return STATE_MENU;
    if (sfFloatRect_contains(&volume, mouse_coordinates.x,
        mouse_coordinates.y)) {
        change_volume(texts, button, ctx);
    }
    return STATE_MENU_IN_GAME;
}

void resize_everything_in_window(sfEvent event,
    app_context_t *ctx, menu_t *menu)
{
    sfVector2u size = {event.size.width, event.size.height};

    sfView_setSize(*ctx->view, (sfVector2f){size.x, size.y});
    sfView_setCenter(*ctx->view, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfRenderWindow_setView(*ctx->window, *ctx->view);
    resize_background_in_game(menu);
}

int escape_resize_events(event_ctx_t *event_ctx, game_t *game, menu_t *menu)
{
    if (event_ctx->event.type ==
        sfEvtKeyReleased && event_ctx->event.key.code == sfKeyX) {
        game->state = STATE_EXIT;
        return 0;
    }
    if (event_ctx->event.type == sfEvtResized)
        resize_everything_in_window(event_ctx->event, event_ctx->ctx, menu);
    return 1;
}

int handle_event(event_ctx_t *event_ctx, game_t *game,
    text_elemets_t *texts, menu_t *menu)
{
    sfVector2i mouse_position;
    sfVector2f mouse_coordinates;

    if (event_ctx->event.type == sfEvtMouseButtonPressed) {
        mouse_position =
        sfMouse_getPositionRenderWindow(*event_ctx->ctx->window);
        mouse_coordinates =
        sfRenderWindow_mapPixelToCoords(*event_ctx->ctx->window,
            mouse_position, *event_ctx->ctx->view);
        game->state =
        handle_mouse_click(texts, mouse_coordinates,
            event_ctx->event.mouseButton.button, event_ctx->ctx);
        if (game->state != STATE_MENU_IN_GAME)
            return 0;
    }
    if (escape_resize_events(event_ctx, game, menu) == 0)
        return 0;
    return 1;
}
