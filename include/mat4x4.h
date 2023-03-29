/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** mat4x4
*/

#pragma once

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct mat4x4 {
    float val[16];
} mat4x4;

#define PI 3.14159265359

mat4x4 *mat4x4_create(void);

mat4x4 *mat4x4_multiplymat4x4(mat4x4 *mat1, mat4x4 *mat2);
float *mat4x4_multiplyvector4(mat4x4 *mat, float *vector);
float *mat4x4_multiplyvector3(mat4x4 *mat, float *vector, float *res);

mat4x4 *mat4x4_rx(float a);
mat4x4 *mat4x4_ry(float a);
mat4x4 *mat4x4_rz(float a);
mat4x4 *mat4x4_t(float *vector);
