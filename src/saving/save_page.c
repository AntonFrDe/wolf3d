/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** save_page
*/

#include "../../include/wolf.h"

switch_window_state_t display_savepage(game_t *game)
{
    char *txt;
    
    // Display text and write box
    // put textbox output in txt string

    save_file(my_superstrcat(3, "save/", txt, ".halosave"), game);
}
