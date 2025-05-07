/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** main_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "../../raycasting3/include/wolf.h"
#include "../../raycasting3/include/struct.h"
#include <stdbool.h>

void destroy_texts(text_elemets_t *texts)
{
    sfText_destroy(texts->title);
    sfText_destroy(texts->back);
    sfText_destroy(texts->volume);
    sfText_destroy(texts->resolution);
    sfText_destroy(texts->fullscreen);
}

void resize_background(menu_t *menu)
{
    sfVector2u win_size = sfRenderWindow_getSize(menu->window);
    sfVector2u tex_size;
    float scale_x;
    float scale_y;

    if (menu->background_texture != NULL) {
        tex_size = sfTexture_getSize(menu->background_texture);
        scale_x = (float)win_size.x / (float)tex_size.x;
        scale_y = (float)win_size.y / (float)tex_size.y;
    } else {
        return;
    }
    if (menu->background_sprite != NULL) {
        sfSprite_setScale(menu->background_sprite,
            (sfVector2f){scale_x, scale_y});
    }
}

sfText *create_menu_text(sfFont *menu_text_font, const char *str,
    sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, menu_text_font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 80);
    sfText_setPosition(text, pos);
    return text;
}

sfText *create_centered_text(sfFont *font, const char *str,
    sfVector2f center, float y_offset)
{
    sfText *text = create_menu_text(font, str, (sfVector2f){0, 0});
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    sfText_setPosition(text, (sfVector2f){
        center.x - bounds.width / 2,
        center.y + y_offset
    });
    return text;
}

static void init_menu(menu_t *menu)
{
    sfVector2f center = sfView_getCenter(menu->view);

    menu->background_texture =
    sfTexture_createFromFile("../Game/Menu/Assets/Whalobackground.jpeg", NULL);
    menu->background_sprite = sfSprite_create();
    sfSprite_setTexture(menu->background_sprite,
        menu->background_texture, sfTrue);
    resize_background(menu);
    menu->start =
    create_centered_text(menu->font, "Start the Game", center, -100);
    menu->settings = create_centered_text(menu->font, "Settings", center, 100);
    menu->load = create_centered_text(menu->font, "Load Game", center, 0);
}

static void draw_menu_sprites_and_texts(menu_t *menu)
{
    sfRenderWindow_setView(menu->window, menu->view);
    sfRenderWindow_clear(menu->window, sfBlack);
    sfRenderWindow_drawSprite(menu->window, menu->background_sprite, NULL);
    sfRenderWindow_drawText(menu->window, menu->start, NULL);
    sfRenderWindow_drawText(menu->window, menu->settings, NULL);
    sfRenderWindow_drawText(menu->window, menu->load, NULL);
    sfRenderWindow_display(menu->window);
}

static void draw_menu(menu_t *menu)
{
    sfVector2i mouse_px = sfMouse_getPositionRenderWindow(menu->window);
    sfVector2f mouse_pos =
    sfRenderWindow_mapPixelToCoords(menu->window, mouse_px, menu->view);
    sfFloatRect start_bounds = sfText_getGlobalBounds(menu->start);
    sfFloatRect settings_bounds = sfText_getGlobalBounds(menu->settings);
    sfFloatRect load_bounds = sfText_getGlobalBounds(menu->load);

    sfText_setFillColor(menu->start, sfWhite);
    sfText_setFillColor(menu->settings, sfWhite);
    sfText_setFillColor(menu->load, sfWhite);
    if (sfFloatRect_contains(&start_bounds, mouse_pos.x, mouse_pos.y))
        sfText_setFillColor(menu->start, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&settings_bounds, mouse_pos.x, mouse_pos.y))
        sfText_setFillColor(menu->settings, sfColor_fromRGB(116, 201, 238));
    if (sfFloatRect_contains(&load_bounds, mouse_pos.x, mouse_pos.y))
        sfText_setFillColor(menu->load, sfColor_fromRGB(116, 201, 238));
    draw_menu_sprites_and_texts(menu);
}

static switch_window_state_t handle_menu_events_condition(menu_t *menu,
    sfEvent event)
{
    sfFloatRect start_bounds;
    sfFloatRect settings_bounds;
    sfFloatRect load_bounds;
    sfVector2i pix;
    sfVector2f pos;

    if (event.type == sfEvtMouseButtonPressed) {
        pix = sfMouse_getPositionRenderWindow(menu->window);
        pos = sfRenderWindow_mapPixelToCoords(menu->window, pix, menu->view);
        start_bounds = sfText_getGlobalBounds(menu->start);
        settings_bounds = sfText_getGlobalBounds(menu->settings);
        load_bounds = sfText_getGlobalBounds(menu->load);
        if (sfFloatRect_contains(&start_bounds, pos.x, pos.y))
            return STATE_GAME;
        if (sfFloatRect_contains(&settings_bounds, pos.x, pos.y))
            return STATE_SETTINGS;
        if (sfFloatRect_contains(&load_bounds, pos.x, pos.y))
            printf("Game loaded!\n");
    }
    return STATE_MENU;
}

static switch_window_state_t menu_events(menu_t *menu)
{
    sfEvent event;
    switch_window_state_t new_state;

    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            return STATE_EXIT;
        new_state = handle_menu_events_condition(menu, event);
        if (new_state != STATE_MENU)
            return new_state;
    }
    return STATE_MENU;
}

switch_window_state_t display_menu(sfRenderWindow *window,
    sfFont *font, sfView *view)
{
    menu_t menu = { .window = window, .font = font, .view = view };
    switch_window_state_t result;

    init_menu(&menu);
    while (sfRenderWindow_isOpen(window)) {
        draw_menu(&menu);
        result = menu_events(&menu);
        if (result != STATE_MENU)
            break;
    }
    sfText_destroy(menu.start);
    sfText_destroy(menu.settings);
    sfText_destroy(menu.load);
    sfSprite_destroy(menu.background_sprite);
    sfTexture_destroy(menu.background_texture);
    return result;
}
