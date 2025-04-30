/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>

sfText *create_menu_text(sfFont *menu_text_font, const char *str, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, menu_text_font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 80);
    sfText_setPosition(text, pos);
    return text;
}

void display_settings_window_loop(sfMusic *music, int *volume_ref, int *resolution_index,
    sfRenderWindow *window, sfView *view, sfEvent event,
    sfText *back_button_text, sfText *volume_text, sfText *resolution_text, char **resolutions_texts)
{
    char volume_string_text[50];
    sfVector2u resolutions[2] = {{1280, 720}, {1920, 1080}};
    sfVector2i pixelPos;
    sfVector2f mouse;
    sfFloatRect back_button_bounds;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        pixelPos = sfMouse_getPositionRenderWindow(window);
        mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, view);
        back_button_bounds = sfText_getGlobalBounds(back_button_text);
        if (sfFloatRect_contains(&back_button_bounds, mouse.x, mouse.y)) {
            sfRenderWindow_close(window);
        }
        if (mouse.y >= 300 && mouse.y <= 350) {
            if (event.mouseButton.button == sfMouseLeft && *volume_ref < 100)
                *volume_ref += 10;
            if (event.mouseButton.button == sfMouseRight && *volume_ref > 0)
                *volume_ref -= 10;
            snprintf(volume_string_text, sizeof(volume_string_text), "Volume: %d%%", *volume_ref);
            sfText_setString(volume_text, volume_string_text);
            if (music != NULL)
                sfMusic_setVolume(music, *volume_ref);
        }
        if (mouse.y >= 400 && mouse.y <= 450) {
            *resolution_index = (*resolution_index + 1) % 2;
            sfRenderWindow_setSize(window, resolutions[*resolution_index]);
            sfRenderWindow_setView(window, view);
            sfText_setString(resolution_text, resolutions_texts[*resolution_index]);
        }
    }
}

void display_settings(sfMusic *music, int *volume_ref)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Settings", sfClose | sfResize, NULL);
    sfView *view = sfView_create();
    sfEvent event;
    int resolution_index = 0;
    int volume = *volume_ref;
    sfFont *menu_text_font = sfFont_createFromFile("../Game/Menu/Assets/horrendo.ttf");
    sfText *settings_text = create_menu_text(menu_text_font, "Settings", (sfVector2f){500, 100});
    sfText *volume_text = sfText_create();
    sfText *resolution_text = sfText_create();
    sfText *back_button_text = create_menu_text(menu_text_font, "Back", (sfVector2f){50, 600});
    char *resolutions_texts[2] = {"1280x720", "1920x1080"};
    char volume_string_text[50];

    snprintf(volume_string_text, sizeof(volume_string_text), "Volume: %d%%", volume);
    sfView_setSize(view, (sfVector2f){1280, 720});
    sfView_setCenter(view, (sfVector2f){640, 360});
    sfRenderWindow_setView(window, view);
    sfText_setFont(volume_text, menu_text_font);
    sfText_setString(volume_text, volume_string_text);
    sfText_setCharacterSize(volume_text, 50);
    sfText_setPosition(volume_text, (sfVector2f){500, 300});
    sfText_setFont(resolution_text, menu_text_font);
    sfText_setString(resolution_text, resolutions_texts[resolution_index]);
    sfText_setCharacterSize(resolution_text, 50);
    sfText_setPosition(resolution_text, (sfVector2f){500, 400});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            display_settings_window_loop(music, &volume, &resolution_index, window, view, event,
                back_button_text, volume_text, resolution_text, resolutions_texts);
        }
        *volume_ref = volume;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, settings_text, NULL);
        sfRenderWindow_drawText(window, volume_text, NULL);
        sfRenderWindow_drawText(window, resolution_text, NULL);
        sfRenderWindow_drawText(window, back_button_text, NULL);
        sfRenderWindow_display(window);
    }
    sfText_destroy(settings_text);
    sfText_destroy(volume_text);
    sfText_destroy(resolution_text);
    sfText_destroy(back_button_text);
    sfFont_destroy(menu_text_font);
    sfRenderWindow_destroy(window);
}

int display_menu(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    int status = 0;
    sfTexture *background_texture = sfTexture_createFromFile("../Game/Menu/Assets/Whalobackground.jpeg", NULL);
    sfSprite *background_sprite = sfSprite_create();
    sfFont *menu_text_font = sfFont_createFromFile("../Game/Menu/Assets/horrendo.ttf");
    sfText *start_text = create_menu_text(menu_text_font, "Start the Game", (sfVector2f){550, 500});
    sfText *settings_text = create_menu_text(menu_text_font, "Settings", (sfVector2f){550, 650});
    sfVector2i mouse;
    sfFloatRect hitbox_start_button;
    sfFloatRect hitbox_setting_button;

    window = sfRenderWindow_create(mode, "Menu Woke3D", sfClose | sfResize, NULL);
    sfSprite_setTexture(background_sprite, background_texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                status = 1;
            }
            if (event.type == sfEvtMouseButtonPressed) {
                mouse = sfMouse_getPositionRenderWindow(window);
                hitbox_start_button = sfText_getGlobalBounds(start_text);
                hitbox_setting_button = sfText_getGlobalBounds(settings_text);
                if (sfFloatRect_contains(&hitbox_start_button, mouse.x, mouse.y)) {
                    sfRenderWindow_close(window);
                    status = 0;
                }
                if (sfFloatRect_contains(&hitbox_setting_button, mouse.x, mouse.y)) {
                    sfRenderWindow_close(window);
                    status = 2;
                }
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        sfRenderWindow_drawText(window, start_text, NULL);
        sfRenderWindow_drawText(window, settings_text, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(background_sprite);
    sfTexture_destroy(background_texture);
    sfText_destroy(start_text);
    sfText_destroy(settings_text);
    sfFont_destroy(menu_text_font);
    sfRenderWindow_destroy(window);
    return status;
}
