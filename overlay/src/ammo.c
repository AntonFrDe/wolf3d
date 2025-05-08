/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** ammo.c
*/

#include "../include/ammo.h"
#include <stdio.h>

ammo_display_t create_ammo_display(void)
{
    ammo_display_t display;

    display.ammo = 32;
    display.font = sfFont_createFromFile("src/assets/Starcraft Normal.ttf");
    display.text = sfText_create();
    sfText_setFont(display.text, display.font);
    sfText_setCharacterSize(display.text, 40);
    sfText_setFillColor(display.text, sfWhite);
    sfText_setPosition(display.text, (sfVector2f){1390.f, 135.f});
    return display;
}

void update_ammo_text(ammo_display_t *display)
{
    char buffer[64];

    snprintf(buffer, sizeof(buffer), "Ammo: %d", display->ammo);
    sfText_setString(display->text, buffer);
}
