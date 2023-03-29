/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** triangle
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "mat4x4.h"

typedef struct vertex {
    float pos[3]; // 0 = x, 1 = y, 2 = z
} vertex_t;

typedef struct triangle {
    vertex_t vec[3];
    sfColor color;
} triangle_t;

typedef struct cube {
    vertex_t vec[8];
} cube_t;

void add_triangle(sfVertexArray *array, triangle_t *triangle, mat4x4 *matrix, sfRenderWindow *window);
void move(mat4x4 **matrix, sfClock *clock);
triangle_t project_triangle(mat4x4 *matrix, triangle_t *triangle);

cube_t create_cube(void);
void draw_cube(sfVertexArray *array, cube_t *cube, mat4x4 *matrix, sfRenderWindow *window);

// @brief center the vertexes in the window
void center_vertxs(vertex_t *vertxs, sfRenderWindow *window);
