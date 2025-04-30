/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** main
*/

#include "include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "include/struct.h"

int main(int argc, char **argv)
{
    map_t map;
    int break_status = 0;
    int volume = 50;

    if (argc != 2)
        return 84;
    sfMusic *music = sfMusic_createFromFile("../Game/Menu/Assets/halo_music.ogg");
    if (music != NULL) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_setVolume(music, volume);
        sfMusic_play(music);
    }
    while (1) {
        switch (display_menu()) {
            case 84:
                return 84;
            case 1:
                return 0;
            case 2:
                display_settings(music, &volume);
                break;
            default:
                break_status = 1;
                break;
        }
        if (break_status == 1)
            break;
    }

    map = init_map(argv[1]);
    if (map.map == NULL)
        return 84;
    return display_window(map);
}
