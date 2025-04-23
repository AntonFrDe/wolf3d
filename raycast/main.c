/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

int main(int argc, char **argv)
{
    map_t map;

    if (argc != 2)
        return 84;
    map = init_map(argv[1]);
    if (map.map == NULL)
        return 84;
    return display_window(map);
}
