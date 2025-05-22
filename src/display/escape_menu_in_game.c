/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** escape_menu_in_game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../include/wolf.h"
#include "../../include/struct.h"
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

static void init_in_game_background(menu_t *menu)
{
    menu->settings_background_texture =
        sfTexture_createFromFile("../Game/Menu/Assets/halo_settings.jpg",
            NULL);
    menu->settings_background_sprite = sfSprite_create();
    sfSprite_setTexture(menu->settings_background_sprite,
        menu->settings_background_texture, sfTrue);
    resize_background_in_game(menu);
}

static void init_menu_in_game_texts(text_elemets_t *texts,
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

static void change_button_pos(text_elemets_t *texts, sfView **view)
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

int display_menu_in_game_events(game_t *game,
    event_ctx_t event_ctx, text_elemets_t texts, menu_t menu)
{
    while (sfRenderWindow_pollEvent(*event_ctx.ctx->window,
        &event_ctx.event)) {
        if (handle_event(&event_ctx, game, &texts, &menu) == 0)
            return 1;
    }
    return 0;
}

switch_window_state_t display_menu_in_game(app_context_t *ctx, game_t *game)
{
    text_elemets_t texts;
    menu_t menu = { .window = game->window };
    event_ctx_t event_ctx;

    event_ctx.ctx = ctx;
    init_menu_in_game_texts(&texts, game->app.font, event_ctx.ctx);
    init_in_game_background(&menu);
    while (game->state == STATE_MENU_IN_GAME) {
        if (display_menu_in_game_events(game, event_ctx, texts, menu) == 1)
            return game->state;
        change_button_pos(&texts, event_ctx.ctx->view);
        change_button_color(&texts, event_ctx.ctx);
        draw_all_in_menu(event_ctx.ctx, &texts, &menu);
    }
    return game->state;
}
