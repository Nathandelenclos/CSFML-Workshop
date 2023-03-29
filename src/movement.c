/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement
*/

#include "shapes.h"
#include "mat4x4.h"

void move_player(mat4x4 **mat_world, double factor)
{
    mat4x4 *mat_mov;
    mat4x4 *tmp;
    float vec[3] = {0, 0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        // vec[?] = factor;
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
    !sfKeyboard_isKeyPressed(sfKeyLControl) && !sfKeyboard_isKeyPressed(sfKeyRControl))
        // vec[?] = -factor;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        // vec[?] = -factor;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        // vec[?] = factor;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        // vec[?] = factor;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        // vec[?] = -factor;
    mat_mov = mat4x4_t(vec);
    tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
    free(mat_mov);
    free(*mat_world);
    *mat_world = tmp;
}

void move_cam(mat4x4 **mat_world, double factor)
{
    mat4x4 *tmp;
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyJ))
        // mat_mov = mat4x4_ry(???);
    if (sfKeyboard_isKeyPressed(sfKeyL))
        // mat_mov = mat4x4_ry(???);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        // mat_mov = mat4x4_rx(???);
    if (sfKeyboard_isKeyPressed(sfKeyK))
        // mat_mov = mat4x4_rx(???);
    if (mat_mov) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        free(mat_mov);
        free(*mat_world);
        *mat_world = tmp;
    }
}

void move_angle(mat4x4 **mat_world, double factor)
{
    mat4x4 *mat_mov = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyW))
        // mat_mov = mat4x4_rz(???);
    if (sfKeyboard_isKeyPressed(sfKeyX))
        // mat_mov = mat4x4_rz(???);
    if (mat_mov != NULL) {
        *mat_world = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        free(mat_mov);
    }
}

void move(mat4x4 **matrix, sfClock *clock)
{
    double factor = sfClock_getElapsedTime(clock).microseconds;

    factor /= 30000.0;
    move_player(matrix, factor);
    move_cam(matrix, factor);
    move_angle(matrix, factor);
    sfClock_restart(clock);
}
