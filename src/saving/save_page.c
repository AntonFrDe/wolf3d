/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** save_page
*/

#include "../../include/wolf.h"

static sfText *create_slot(const char *label, sfFont *font, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, label);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    return text;
}

static void init_save_menu(save_menu_t *menu)
{
    const char *labels[3] = {"SAVE 1", "SAVE 2", "SAVE 3"};
    sfVector2f pos[3] = {
        {300, 150},
        {300, 250},
        {300, 350}
    };
    int i = 0;

    while (i < 3) {
        menu->slots[i] = create_slot(labels[i], menu->font, pos[i]);
        i++;
    }
    menu->selected = -1;
}

static void draw_save_menu(save_menu_t *menu)
{
    int i = 0;

    while (i < 3) {
        sfText_setFillColor(menu->slots[i],
            (i == menu->selected) ? sfBlue : sfWhite);
        sfRenderWindow_drawText(menu->window, menu->slots[i], NULL);
        i++;
    }
}

static sfBool is_clicked(sfText *text, sfVector2f mouse)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    return sfFloatRect_contains(&bounds, mouse.x, mouse.y);
}

static void save_selected_file(int index, game_t *game)
{
    const char *files[3] = {
        "save/save1.halosave",
        "save/save2.halosave",
        "save/save3.halosave"
    };

    save_file(my_superstrcat(1, files[index]), game);
}

static switch_window_state_t check_window_close(sfEvent *event)
{
    if (event->type == sfEvtClosed)
        return STATE_EXIT;
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        return STATE_EXIT;
    return STATE_MENU;
}

switch_window_state_t handle_mouse_click(save_menu_t *menu, game_t *game)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(menu->window);
    sfVector2f mf = {m.x, m.y};
    int i = 0;

    while (i < 3) {
        if (is_clicked(menu->slots[i], mf)) {
            menu->selected = i;
            save_selected_file(i, game);
            return STATE_GAME;
        }
        i++;
    }
    return STATE_MENU;
}

static switch_window_state_t save_events(save_menu_t *menu, game_t *game)
{
    sfEvent event;
    switch_window_state_t state;

    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        state = check_window_close(&event);
        if (state != STATE_MENU)
            return state;
        if (event.type == sfEvtMouseButtonPressed)
            return handle_mouse_click(menu, game);
    }
    return STATE_MENU;
}

switch_window_state_t display_savepage(game_t *game)
{
    save_menu_t menu = {
        .window = game->window,
        .font = game->app.font,
        .selected = -1
    };

    init_save_menu(&menu);
    while (game->state == STATE_MENU) {
        sfRenderWindow_clear(menu.window, sfBlack);
        game->state = save_events(&menu, game);
        draw_save_menu(&menu);
        sfRenderWindow_display(menu.window);
    }
    for (int i = 0; i < 3; i++)
        sfText_destroy(menu.slots[i]);
    return game->state;
}
