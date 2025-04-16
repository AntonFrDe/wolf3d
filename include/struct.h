/*
** EPITECH PROJECT, 2024
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** struct.h
*/

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
} image_t;

typedef struct params {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
}params_t;

#endif