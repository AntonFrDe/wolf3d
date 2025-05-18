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

static void render_menu_fillcolor(text_elemets_t *texts)
{
    sfText_setFillColor(texts->save, sfWhite);
    sfText_setFillColor(texts->play, sfWhite);
    sfText_setFillColor(texts->exit, sfWhite);
    sfText_setFillColor(texts->volume, sfWhite);
}

static void change_button_color(text_elemets_t *texts, app_context_t *ctx)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(*ctx->window);
    sfVector2f mouse_coordinates =
    sfRenderWindow_mapPixelToCoords(*ctx->window, mouse_position, *ctx->view);
    sfFloatRect save = sfText_getGlobalBounds(texts->save);
    sfFloatRect play = sfText_getGlobalBounds(texts->play);
    sfFloatRect exit = sfText_getGlobalBounds(texts->exit);
    sfFloatRect volume = sfText_getGlobalBounds(texts->volume);

    render_menu_fillcolor(texts);
    if (sfFloatRect_contains(&save, mouse_coordinates.x, mouse_coordinates.y))
        sfText_setFillColor(texts->save, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&play, mouse_coordinates.x, mouse_coordinates.y))
        sfText_setFillColor(texts->play, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&exit, mouse_coordinates.x, mouse_coordinates.y))
        sfText_setFillColor(texts->exit, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&volume, mouse_coordinates.x,
        mouse_coordinates.y))
        sfText_setFillColor(texts->volume, sfColor_fromRGB(116, 201, 238));
}

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

void init_in_game_background(menu_t *menu)
{
    menu->settings_background_texture =
        sfTexture_createFromFile("../Game/Menu/Assets/halo_settings.jpg",
            NULL);
    menu->settings_background_sprite = sfSprite_create();
    sfSprite_setTexture(menu->settings_background_sprite,
        menu->settings_background_texture, sfTrue);
    resize_background_in_game(menu);
}

static void write_volume_on_window(sfText *text, int volume)
{
    char buf[13];

    snprintf(buf, sizeof(buf), "Volume: %d%%", volume);
    sfText_setString(text, buf);
}

void init_menu_in_game_texts(text_elemets_t *texts,
    sfFont *font, app_context_t *ctx)
{
    texts->save = create_menu_text(font, "Save", (sfVector2f){0, 0});
    texts->play = create_menu_text(font, "Play", (sfVector2f){0, 0});
    texts->exit = create_menu_text(font,
        "Exit to Main Menu", (sfVector2f){0, 0});
    texts->volume = sfText_create();
    sfText_setFont(texts->volume, font);
    sfText_setCharacterSize(texts->volume, 50);
    write_volume_on_window(texts->volume, *ctx->volume);
}

void change_button_pos(text_elemets_t *texts, sfView **view)
{
    sfVector2f center = sfView_getCenter(*view);
    sfFloatRect save = sfText_getGlobalBounds(texts->save);
    sfFloatRect play = sfText_getGlobalBounds(texts->play);
    sfFloatRect exit = sfText_getGlobalBounds(texts->exit);
    sfFloatRect volume = sfText_getGlobalBounds(texts->volume);

    sfText_setPosition(texts->save,
        (sfVector2f){center.x - save.width / 2, center.y - 150});
    sfText_setPosition(texts->play,
        (sfVector2f){center.x - play.width / 2, center.y - 50});
    sfText_setPosition(texts->exit,
        (sfVector2f){center.x - exit.width / 2, center.y + 50});
    sfText_setPosition(texts->volume,
        (sfVector2f){center.x - volume.width / 2, center.y + 150});
}

void draw_all_in_menu(app_context_t *ctx, text_elemets_t *texts, menu_t *menu)
{
    sfRenderWindow_clear(*ctx->window, sfBlack);
    sfRenderWindow_drawSprite(*ctx->window,
        menu->settings_background_sprite, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->save, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->play, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->exit, NULL);
    sfRenderWindow_drawText(*ctx->window, texts->volume, NULL);
    sfRenderWindow_display(*ctx->window);
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

switch_window_state_t handle_mouse_click(text_elemets_t *texts,
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

static void resize_everything_in_window(sfEvent event,
    app_context_t *ctx, menu_t *menu)
{
    sfVector2u size = {event.size.width, event.size.height};

    sfView_setSize(*ctx->view, (sfVector2f){size.x, size.y});
    sfView_setCenter(*ctx->view, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfRenderWindow_setView(*ctx->window, *ctx->view);
    resize_background_in_game(menu);
}

static int handle_event(sfEvent event, app_context_t *ctx, game_t *game,
    text_elemets_t *texts, menu_t *menu)
{
    sfVector2i mouse_position;
    sfVector2f mouse_coordinates;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse_position = sfMouse_getPositionRenderWindow(*ctx->window);
        mouse_coordinates =
        sfRenderWindow_mapPixelToCoords(*ctx->window,
            mouse_position, *ctx->view);
        game->state =
        handle_mouse_click(texts, mouse_coordinates,
            event.mouseButton.button, ctx);
        if (game->state != STATE_MENU_IN_GAME)
            return 0;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        game->state = STATE_MENU;
        return 0;
    }
    if (event.type == sfEvtResized)
        resize_everything_in_window(event, ctx, menu);
    return 1;
}

switch_window_state_t display_menu_in_game(app_context_t *ctx, game_t *game)
{
    text_elemets_t texts;
    sfEvent event;
    menu_t menu = { .window = game->window };

    init_menu_in_game_texts(&texts, game->app.font, ctx);
    init_in_game_background(&menu);
    while (game->state == STATE_MENU_IN_GAME) {
        while (sfRenderWindow_pollEvent(*ctx->window, &event))
            if (handle_event(event, ctx, game, &texts, &menu) == 0)
                return game->state;
        change_button_pos(&texts, ctx->view);
        change_button_color(&texts, ctx);
        draw_all_in_menu(ctx, &texts, &menu);
    }
    return game->state;
}
