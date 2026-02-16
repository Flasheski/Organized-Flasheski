/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** main
*/

#include "shell.h"
#include "my.h"

int main(void)
{
    infos_t *list = NULL;
    int status = 0;

    status = workshop_shell(&list);
    free_list(list);
    return status;
}
