
# Variables
NAME        = ft_printf

# Directories
SRC_DIR     = sources
INC_DIR     = includes
OBJ_DIR     = obj

# Compiler and Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR)

# Files and Object Management
SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OFILES)
	rm -rf $(OBJ_DIR)

# Clean all files, including the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
