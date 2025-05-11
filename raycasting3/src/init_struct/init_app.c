/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_app
*/

#include "../../include/wolf.h"

static void init_font(app_t *app)
{
    app->font = sfFont_createFromFile("Assets/Halo.ttf");
    app->view = sfView_create();
}

static void init_view(app_t *app)
{
    sfVector2u size = {1920, 1080};

    sfView_setSize(app->view, (sfVector2f){size.x, size.y});
    sfView_setCenter(app->view, (sfVector2f){size.x / 2.f, size.y / 2.f});
}

static void init_music(app_t *app)
{
    app->music = sfMusic_createFromFile("Assets/halo_music.ogg");
    sfMusic_setLoop(app->music, sfTrue);
    sfMusic_setVolume(app->music, app->volume);
    sfMusic_play(app->music);
}

app_t init_app(void)
{
    app_t app;

    app.volume = 50;
    init_font(&app);
    init_view(&app);
    init_music(&app);
    app.fullscreen_status = 0;
    return app;
}
