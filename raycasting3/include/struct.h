/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** struct
*/

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Window.h"
#include <stdbool.h>
#include <SFML/Audio.h>

#ifndef STRUCT_H_
    #include "overlay.h"
    #define STRUCT_H_
typedef struct player_s {
    sfVector2f loc;
    sfVector2f dir;
    sfVector2f plane;
    int angle;
} player_t;

typedef struct raycast_s {
    int hit;
    int side;
    float len;
    sfVector2f cam;
    sfVector2f ray_dir;
    sfVector2f delta_dist;
    sfVector2i steps;
    sfVector2f side_dist;
} raycast_t;

typedef enum switch_window_state_s {
    STATE_MENU,
    STATE_SETTINGS,
    STATE_GAME,
    STATE_EXIT
} switch_window_state_t;

typedef struct app_s {
    sfRenderWindow *window;
    sfFont *font;
    sfView *view;
    int volume;
    int res_index;
    sfMusic *music;
    int fullscreen_status;
} app_t;

typedef struct menu_s {
    sfText *start;
    sfText *load;
    sfText *settings;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfRenderWindow *window;
    sfFont *font;
    sfView *view;
    sfTexture *settings_background_texture;
    sfSprite *settings_background_sprite;
} menu_t;

typedef struct app_context_s {
    sfRenderWindow **window;
    sfView **view;
    sfMusic *music;
    int *volume;
    int *res_index;
    bool is_fullscreen;
    int *fullscreen_status;
} app_context_t;

typedef struct text_elemets_s {
    sfText *title;
    sfText *volume;
    sfText *resolution;
    sfText *back;
    sfText *fullscreen;
    sfText *save;
    int fullscreen_status;
} text_elemets_t;

typedef struct input_context_s {
    sfEvent *event;
    sfVector2f mouse_pos;
} input_context_t;

typedef struct game_txtr_s {
    sfTexture **wall;
    sfSprite *skybg;
    sfRenderTexture *walltx;
    sfSprite *wallsp;
    sfImage *floor;
    sfRenderTexture *flashlight;
} game_txtr_t;

typedef struct floor_cast_s {
    sfVector2f ray_dir0;
    sfVector2f ray_dir1;
    sfVector2f step;
    sfVector2f floor;
    sfVector2i tex_coords;
    sfColor color;
    float row_distance;
} floor_cast_t;

typedef struct game_s {
    game_txtr_t gmtx;
    player_t player;
    int **map;
    sfRenderWindow *window;
    sfEvent *event;
    sfVideoMode video;
    sfVector2f map_size;
    sfClock *time;
    app_t app;
    switch_window_state_t state;
    context_t context;
} game_t;


#endif /* !STRUCT_H_ */
