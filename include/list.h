/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/

#pragma once

typedef struct list {
    struct list *next;
    struct list *prev;
    void *data;
} list_t;

void append_node(list_t **begin, void *data);
void remove_node(list_t **begin, unsigned offset, void (*freer)(void *));
