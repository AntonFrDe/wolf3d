/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

static int event_handling(sfRenderWindow *window, sfEvent event,
    player_t *player, map_t *map, a3d_t *a3d)
{
    sfVector2f new_loc = angle_coor(player->loc, player->angle,
        sfKeyboard_isKeyPressed(sfKeyZ) * 10 -
        sfKeyboard_isKeyPressed(sfKeyS) * 10);

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyM))
        map->bool_map = (int)(map->bool_map == 0);
    if (event.type == sfEvtKeyPressed && is_loc_in_map(new_loc, *map) == 0) {
        player->angle += sfKeyboard_isKeyPressed(sfKeyD) * 5
            - sfKeyboard_isKeyPressed(sfKeyQ) * 5;
        player->angle = float_modulo(player->angle, 360);
        player->loc = new_loc;
        new_loc.x -= player->dot.radius;
        new_loc.y -= player->dot.radius;
        sfCircleShape_setPosition(player->dot.circle, new_loc);
    }
}

static void draw_minimap(player_t *player, map_t map, sfRenderWindow *window)
{
    display_square(map.squares, window, map.len);
    sfRenderWindow_drawCircleShape(window, player->dot.circle, NULL);
    draw_line(window, player->loc, angle_coor(player->loc, player->angle, 30),
        sfGreen);
}

int display_window(map_t map)
{
    sfRenderWindow *window = window_create();
    player_t *player = create_player((sfVector2f){360, 280}, RAY);
    sfEvent event;
    a3d_t *a3d = init_3d((sfVector2f){0, 0}, RAY, 1700, 890);

    if (map.map == NULL)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        if (sfRenderWindow_pollEvent(window, &event))
            event_handling(window, event, player, &map, a3d);
        sfRenderWindow_clear(window, sfColor_fromRGB(0, 232, 203));
        display_3d(map, player, window, a3d);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            draw_minimap(player, map, window);
        sfRenderWindow_display(window);
    }
    sfCircleShape_destroy(player->dot.circle);
    sfRenderWindow_destroy(window);
    return 0;
}
