NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = src/push_swap/
BONUS_DIR = src/bonus/

SRC =	$(SRC_DIR)main.c \
        $(SRC_DIR)in_cleaning.c \
        $(SRC_DIR)utils1.c \
        $(SRC_DIR)sort_big.c \
        $(SRC_DIR)sort_main.c \
        $(SRC_DIR)sort_three.c \
        $(SRC_DIR)sort_four.c \
        $(SRC_DIR)inspct_list.c

BONUS_SRC = $(BONUS_DIR)checker.c

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
    ${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
    make -C $(LIBFTDIR)
    ${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ} ${BONUS_OBJ}
    make -C $(LIBFTDIR)
    ${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
    ${RM} ${OBJ} ${BONUS_OBJ} ${NAME} ${BONUS}
    @cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
    ${RM} ${NAME}
    @cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus