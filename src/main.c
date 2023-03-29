/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "mat4x4.h"
#include "shapes.h"

int main(void)
{
    sfRenderWindow *window =
    sfRenderWindow_create((sfVideoMode){1000, 1000, 32}, "Workshop 3D", sfClose, NULL);
    mat4x4 *matrix = mat4x4_create();
    sfClock *clock = sfClock_create();
    // créer un vetex array

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        // move(&matrix, clock); // Uncomment this line to move the shapes
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        // draw your shapes here
        sfRenderWindow_display(window);
    }
}
