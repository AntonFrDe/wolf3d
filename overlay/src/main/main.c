/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/context.h"


static void destroy_all(context_t *ctx,
    sfSound *fire, sfSoundBuffer *fbuf, sfSound *reload, sfSoundBuffer *rbuf)
{
    sfSound_destroy(fire);
    sfSoundBuffer_destroy(fbuf);
    sfSound_destroy(reload);
    sfSoundBuffer_destroy(rbuf);
    destroy_hud(&ctx->hud);
    sfRenderWindow_destroy(ctx->window);
}

static void game_loop(context_t *ctx, sfSound *fire, sfSound *reload)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(ctx->window)) {
        while (sfRenderWindow_pollEvent(ctx->window, &event))
            handle_events(ctx, event, fire, reload);
        update_weapon(&ctx->weapon, &ctx->ammo,
        sfRenderWindow_getSize(ctx->window));
        display_all(ctx);
        sfSleep(sfMilliseconds(16));
    }
}

int main(void)
{
    context_t ctx;
    sfSoundBuffer *fire_buf = sfSoundBuffer_createFromFile("src/assets/19103_b.wav");
    sfSound *fire = sfSound_create();
    sfSoundBuffer *reload_buf = sfSoundBuffer_createFromFile("src/assets/br_reload_full1.wav");
    sfSound *reload = sfSound_create();

    sfSound_setBuffer(fire, fire_buf);
    sfSound_setBuffer(reload, reload_buf);
    init_all(&ctx);
    game_loop(&ctx, fire, reload);
    destroy_all(&ctx, fire, fire_buf, reload, reload_buf);
    return 0;
}
