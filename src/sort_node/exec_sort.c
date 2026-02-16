/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** exec_sort
*/

#include "shell.h"
#include "my.h"

int exec_sort(infos_t **all_elms, crit_t *crit, int nb_crit, int len)
{
    infos_t **array = list_to_array(*all_elms, len);
    sort_params_t params;

    if (array == NULL) {
        free(crit);
        return 84;
    }
    params.crit = crit;
    params.nb_crit = nb_crit;
    quick_sort(array, 0, len - 1, &params);
    array_to_list(array, len, all_elms);
    clean_sort(array, crit);
    return 0;
}
