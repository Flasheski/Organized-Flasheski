##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for setting_up
##

CC = epiclang

SRC		=	src/add_node/add_node.c \
			src/add_node/print_add.c \
			src/delete_node/delete.c \
			src/delete_node/print_delete.c \
			src/delete_node/free_delete.c \
			src/display_node/display_node.c \
			src/display_node/print_disp.c \
			src/sort_node/clean_sort.c \
			src/sort_node/comp_elements.c \
			src/sort_node/crits.c \
			src/sort_node/exec_sort.c \
			src/sort_node/get_lists_array.c \
			src/sort_node/quick_sort.c \
			src/sort_node/sort.c \
			src/nodes/create_node.c \
			src/free_list/free_list.c \
			src/main.c

OBJ		= 	$(SRC:.c=.o)

NAME	=	organized

CFLAGS	= 	-Wall -Wextra -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	cc -o $(NAME) $(OBJ) -L./lib/my -lmy ./lib/libshell.a $(CFLAGS)

clean:
	$(MAKE) -C ./lib/my clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all
