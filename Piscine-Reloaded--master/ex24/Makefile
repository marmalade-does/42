
NAME = libft.a
SRCS_DIR = srcs
INCLUDES_DIR = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES_DIR)

# Source files and object files
SRCS = $(addprefix $(SRCS_DIR)/, ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c)
OBJS = $(SRCS:.c=.o)

# Rules

all: $(NAME)

# Compile the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re