Library		= libft
files 	   = ft_strlen \
			 ft_memmove \
			 ft_memcpy \
			 ft_strlcpy \
			 ft_strlcat \
			 ft_isalpha \
			 ft_isdigit \
			 ft_isalnum \
			 ft_isascii \
			 ft_isprint \
			 ft_memset \
			 ft_bzero \
			 ft_toupper \
			 ft_tolower \
			 ft_strchr \
			 ft_strrchr \
			 ft_strncmp \
			 ft_memchr \
			 ft_memcmp \
			 ft_strnstr \
			 ft_atoi \
			 ft_calloc \
			 ft_strdup \
			 ft_substr \
			 ft_strjoin \
			 ft_strtrim \
			 ft_split \
			 ft_itoa \
			 ft_strmapi \
			 ft_striteri \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putendl_fd \
			 ft_putnbr_fd \
			 ft_lstadd_back \
			 ft_lstadd_front \
			 ft_lstclear \
			 ft_lstdelone \
			 ft_lstiter \
			 ft_lstlast \
			 ft_lstmap \
			 ft_lstnew \
			 ft_lstsize \

compiler	= gcc
cmpFlags	= -Wall -Wextra -Werror
LIBN	= $(Library).a
CFILES	= $(files:%=%.c)
OFILES	= $(files:%=%.o)
NAME	= $(LIBN)

$(NAME): $(OFILES)
	$(compiler) $(cmpFlags) -c $(CFILES) -I./
	ar -rc $(LIBN) $(OFILES)

%.o: %.c
    $(compiler) $(cmpFlags) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
