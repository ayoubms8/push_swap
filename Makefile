# -*- Makefile -*-

SRCS = parse.c utils.c utils2.c \
instructions.c instructions_2.c algos.c checker_utils.c push_swap.c

BONUS_SRCS = parse.c utils.c utils2.c instructions_c.c instructions_c2.c \
instructions.c instructions_2.c algos.c checker_utils.c checker.c

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(BONUS_OBJS))

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c push_swap.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

NAME = push_swap

BONUS = checker

all: $(NAME)

$(NAME): $(OBJECTS_PREFIXED) libft/libft.a
	$(CC) $(OBJECTS_PREFIXED) libft/libft.a -o $(NAME)

libft/libft.a:
	make --directory=libft

bonus: $(OBJECTS_BONUS_PREFIXED) libft/libft.a
	$(CC) $(OBJECTS_BONUS_PREFIXED) libft/libft.a -o $(BONUS)

clean:
	rm -rf $(OBJS_DIR)
	make --directory=libft fclean

fclean: clean
	rm -rf $(NAME) $(BONUS)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus