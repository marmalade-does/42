# Variables
Library     = libft
files       = ft_strlen ft_memmove ft_memcpy ft_strlcpy ft_strlcat ft_isalpha ft_isdigit \
              ft_isalnum ft_isascii ft_isprint ft_memset ft_bzero ft_toupper ft_tolower \
              ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi \
              ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa \
              ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
lst_files 	= ft_lstadd_back_bonus ft_lstadd_front_bonus ft_lstclear_bonus ft_lstdelone_bonus ft_lstiter_bonus \
              ft_lstlast_bonus ft_lstmap_bonus ft_lstnew_bonus ft_lstsize_bonus
CC          = gcc
CFLAGS      = -Wall -Wextra
NAME        = $(Library).a
SRC         = $(files:%=%.c)
OBJ         = $(files:%=%.o)
BONUS_CFILES = $(lst_files:%=%.c)
BONUS_OFILES = $(lst_files:%=%.o)

# Build the library
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OFILES)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OFILES)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OFILES)

# Clean all files, including the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus