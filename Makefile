NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -L ./libft/
INCLUDES = -I ./includes/ -I ./libft/includes/
LIBFT = ./libft/libft.a
HEADERS = ./includes/push_swap.h
SOURCES_LIST = main.c cmds_a.c cmds_utils.c print_stack.c \
	find_min_max.c radix_sort.c convert_argv.c \
	size.c hard_sort_a.c hard_sort_b.c \
	check_input.c init_check.c \
	free_mem.c
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBFT) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : ./sources/%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC ./libft/
clean:
	@$(MAKE) -sC ./libft/ clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
