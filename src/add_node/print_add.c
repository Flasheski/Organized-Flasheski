/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** print_add
*/

#include "my.h"
#include "shell.h"

void print_add(infos_t *elements)
{
    my_putstr(elements->type);
    my_putstr(" n°");
    my_put_nbr(elements->id);
    my_putstr(" - ");
    my_putchar('"');
    my_putstr(elements->name);
    my_putchar('"');
    my_putstr(" added.\n");
}
