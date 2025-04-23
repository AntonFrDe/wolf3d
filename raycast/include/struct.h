/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** struct
*/


#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

typedef struct circle_s {
    sfCircleShape *circle;
    int radius;
    sfVector2f location;
    sfColor color;
}circle_t;

typedef struct square_s {
    sfRectangleShape *rectangle;
    sfVector2f size;
    sfVector2f location;
    sfColor fill_color;
    float outline_thickness;
    sfColor outline_color;
} square_t;

typedef struct line_s {
    sfVector2f p1;
    sfVector2f p2;
    sfVertexArray *varr;
    sfColor color;
    float lenght;
    float angle;
} line_t;

typedef struct player_s {
    circle_t dot;
    sfVector2f loc;
    float angle;
    int nb_ray;
} player_t;

typedef struct a3d_s {
    int lenght;
    int height;
    sfVector2f loc;
    line_t *lines;
    sfColor br_color;
    int nb_lines;
    sfVertexArray *border;
} a3d_t;

typedef struct map_s {
    int **map;
    int len;
    int square_w;
    int square_l;
    int bool_map;
    square_t **squares;
}map_t;

#endif /* !STRUCT_H_ */
