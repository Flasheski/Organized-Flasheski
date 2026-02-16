/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** clean_sort
*/

#include "shell.h"
#include "my.h"

void clean_sort(infos_t **array, crit_t *crit)
{
    if (array != NULL)
        free(array);
    if (crit != NULL)
        free(crit);
}
