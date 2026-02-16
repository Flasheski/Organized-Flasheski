/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** sort
*/

#include "shell.h"
#include "my.h"

int check_sort_params(infos_t **all_elms, char **args)
{
    if (all_elms == NULL || *all_elms == NULL)
        return 84;
    if (args == NULL || args[0] == NULL)
        return 84;
    return 0;
}

int sort(void *data, char **args)
{
    infos_t **all_elms = (infos_t **)data;
    crit_t *crit = NULL;
    int len;
    int nb_crit;

    if (check_sort_params(all_elms, args) == 84)
        return 84;
    nb_crit = parse_crit(args, &crit);
    if (nb_crit == 0) {
        if (crit != NULL)
            free(crit);
        return 84;
    }
    len = count_elms(*all_elms);
    if (len <= 1) {
        free(crit);
        return 0;
    }
    return exec_sort(all_elms, crit, nb_crit, len);
}
