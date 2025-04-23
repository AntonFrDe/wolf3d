/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** is_loc_in_map
*/

#include "include/my.h"
#include "include/struct.h"

int is_loc_in_square(sfVector2f loc, square_t square)
{
    if (loc.x < square.location.x ||
        loc.x > (square.location.x + square.size.x))
        return 0;
    if (loc.y < square.location.y ||
        loc.y > (square.location.y + square.size.y))
        return 0;
    return 1;
}

int is_loc_in_map(sfVector2f loc, const map_t map)
{
    int boool = 0;

    for (int i = 0; i != map.len; i++) {
        for (int j = 0; j != map.len; j++)
            boool += (is_loc_in_square(loc, map.squares[i][j]) == 1 &&
                map.map[i][j] == 1);
        if (boool > 0)
            return 1;
    }
    return 0;
}
