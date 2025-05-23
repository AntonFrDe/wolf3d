/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** load_page
*/

#include "../../include/wolf.h"

switch_window_state_t display_loadpage(game_t *game)
{
    char *txt;

    game = load_file(my_superstrcat(3, "save/", txt, ".halosave"), game);
}
