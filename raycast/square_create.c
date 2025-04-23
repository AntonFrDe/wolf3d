/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** create_square
*/

#include "include/my.h"
#include "include/struct.h"

void display_square(square_t **squares, sfRenderWindow *window, int len)
{
    for (int i = 0; i != len; i++)
        for (int j = 0; j != len; j++)
            sfRenderWindow_drawRectangleShape(window,
                squares[i][j].rectangle, NULL);
}

square_t **init_squares(const map_t map)
{
    square_t **squares = malloc(sizeof(square_t *) * map.len);

    for (int i = 0; i != map.len; i++) {
        squares[i] = malloc(sizeof(square_t) * map.len);
        for (int j = 0; j != map.len; j++)
        squares[i][j] = create_square((sfVector2f){map.square_l, map.square_w},
            (sfVector2f){map.square_l * j, map.square_w * i},
            (map.map[i][j] == 1) ? sfWhite : sfBlack, 5);
    }
    return squares;
}

square_t create_square(sfVector2f size, sfVector2f location,
    sfColor fill_color, float outline_thickness)
{
    square_t square;

    square.rectangle = sfRectangleShape_create();
    if (!square.rectangle)
        return square;
    sfRectangleShape_setSize(square.rectangle, size);
    sfRectangleShape_setFillColor(square.rectangle, fill_color);
    sfRectangleShape_setOutlineColor(square.rectangle, sfBlack);
    sfRectangleShape_setOutlineThickness(square.rectangle, outline_thickness);
    sfRectangleShape_setPosition(square.rectangle, location);
    square.size = size;
    square.location = location;
    square.fill_color = fill_color;
    square.outline_thickness = outline_thickness;
    square.outline_color = sfGreen;
    return square;
}
