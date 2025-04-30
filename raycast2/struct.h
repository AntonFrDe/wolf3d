/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "wolf.h"
typedef struct ray_s {
    sfVertexArray *vertex;
    sfVector2f start;
    sfVector2f end;
    float len;
    float angle;
} ray_t;

typedef struct window {
    sfRenderWindow *win;
    sfEvent event;
    sfVector2i size;
    sfColor color;
} window_t;

typedef struct map_s {
    sfVector2i size;
    sfVector2f wall_size;
    int **wall;
    sfVertexArray ***vertex;
    sfVertexArray *ground;
    sfColor ground_color;
} map_t;

typedef struct player_s {
    sfVector2f loc;
    sfCircleShape *circle;
    float angle;
    ray_t *rays;
} player_t;

typedef struct game_s {
    window_t window;
    map_t map;
    player_t player;
    bool show_map;
} game_t;

#endif /* !STRUCT_H_ */
