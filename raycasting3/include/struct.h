/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** struct
*/

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Window.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct player_s {
    sfVector2f loc;
    sfVector2f dir;
    sfVector2f plane;
    int angle;
} player_t;

typedef struct game_s {
    player_t player;
    int **map;
    sfRenderWindow *window;
    sfEvent *event;
    sfVideoMode video;
    sfVector2f map_size;
} game_t;

typedef struct raycast_s {
    int hit;
    int side;
    sfVector2f cam;
    sfVector2f ray_dir;
    sfVector2f delta_dist;
    sfVector2i steps;
    sfVector2f side_dist;
} raycast_t;

#endif /* !STRUCT_H_ */
