# Variables
Library     = libft
files       = get_next_line get_next_line_utils
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = $(Library).a
SRC         = $(files:%=%.c)
OBJ         = $(files:%=%.o)

# Build the library
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean all files, including the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re