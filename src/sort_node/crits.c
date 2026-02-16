/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** crits
*/

#include "shell.h"
#include "my.h"

int is_valid_crit(char *str)
{
    if (my_strcmp(str, "TYPE") == 0)
        return 1;
    if (my_strcmp(str, "NAME") == 0)
        return 1;
    if (my_strcmp(str, "ID") == 0)
        return 1;
    return 0;
}

int count_crit(char **args)
{
    int count = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "-r") != 0)
            count++;
    }
    return count;
}

void fill_crit(char **args, crit_t *crit)
{
    int j = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "-r") != 0) {
            crit[j].str = args[i];
            crit[j].rev = (args[i + 1] != NULL &&
                my_strcmp(args[i + 1], "-r") == 0) ? 1 : 0;
            j++;
        }
    }
}

int parse_crit(char **args, crit_t **crit)
{
    int count = count_crit(args);

    if (count == 0)
        return 0;
    *crit = malloc(sizeof(crit_t) * count);
    if (*crit == NULL)
        return 0;
    fill_crit(args, *crit);
    for (int i = 0; i < count; i++) {
        if (is_valid_crit((*crit)[i].str) == 0) {
            free(*crit);
            *crit = NULL;
            return 0;
        }
    }
    return count;
}
