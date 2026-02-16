/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** print_delete
*/

#include "shell.h"
#include "my.h"

void print_delete_node(char *name, int id, char *type)
{
    my_putstr(type);
    my_putstr(" n°");
    my_put_nbr(id);
    my_putstr(" - ");
    my_putchar('"');
    my_putstr(name);
    my_putchar('"');
    my_putstr(" deleted.\n");
}
