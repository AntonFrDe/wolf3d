/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** key_event
*/

#include "../include/wolf.h"

int key_evt(sfEvent event, sfKeyCode key, int pressed)
{
    if (pressed) {
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return 1;
        return 0;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == key)
        return 1;
    return 0;
}
