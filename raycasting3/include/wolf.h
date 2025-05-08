/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** wolf
*/

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Window.h"

#ifndef WOLF_H_
    #include "struct.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define WOLF_H_
int main(void);
player_t init_player(void);
game_t *init_game(void);
int **make_map(game_t *game);
void display_game(game_t *game);
void cast_ray(game_t *game);
raycast_t calc_dda(game_t *game, raycast_t raycast);
void draw_ray(game_t *game, raycast_t raycast, int i);
char *remove_bsn(char *str);
void event_handling(game_t *game);
void print_2fv(sfVector2f vec);
void print_2iv(sfVector2i vec);
void print_raycast(char *str, raycast_t ray);
void draw_minimap(game_t *game);
switch_window_state_t display_menu(sfRenderWindow *window, sfFont *font, sfView *view);
switch_window_state_t display_settings(app_context_t *ctx, sfFont *font, sfView *view, sfRenderWindow *window);
void resize_background(menu_t *menu);
sfText *create_menu_text(sfFont *menu_text_font, const char *str,
    sfVector2f pos);
switch_window_state_t handle_mouse_events(app_context_t *ctx,
        text_elemets_t *texts, input_context_t *input, menu_t *menu);
void resize_settings_background(menu_t *menu);
void destroy_texts(text_elemets_t *texts);

#endif /* !WOLF_H_ */
