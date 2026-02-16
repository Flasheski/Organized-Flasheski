/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

typedef struct infos_s {
    char *type;
    int id;
    char *name;
    struct infos_s *next;
} infos_t;

typedef struct crit_s {
    char *str;
    int rev;
} crit_t;

typedef struct sort_params_s {
    crit_t *crit;
    int nb_crit;
} sort_params_t;

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

// functions add
void print_add(infos_t *elements);
infos_t *create_node(int id, char *type, char *name);
// functions delete
void print_delete_node(char *name, int id, char *type);
void free_delete(infos_t *deleted);
// functions display
void print_display(char *type, int id, char *name);
// functions sort
infos_t **list_to_array(infos_t *list, int len);
void array_to_list(infos_t **array, int len, infos_t **all_elms);
int count_elms(infos_t *list);
int compare_elements(infos_t *a, infos_t *b, crit_t *crit, int nb_crit);
int parse_crit(char **args, crit_t **crit);
int exec_sort(infos_t **all_elms, crit_t *crit, int nb_crit, int len);
void quick_sort(infos_t **array, int min_low, int max_high,
    sort_params_t *params);
// free
void free_list(infos_t *free_buffer);
void clean_sort(infos_t **array, crit_t *crit);

#endif /* SHELL_H */
