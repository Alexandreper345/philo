NAME = philosophers
CC = cc -g
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c philo_routine.c utils.c
SRCS = $(addprefix  src/, $(SRC_FILES))
OBJ_SRC = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ_SRC}
	@make -C libft
	${CC} ${FLAGS} ${OBJ_SRC} libft/libft.a -o ${NAME}

clean:
	@make clean -C libft
	rm -rf ${OBJ_SRC}

fclean: clean
	@make clean -C libft
	rm -rf ${NAME}
	rm -rf libft/libft.a

re: fclean all
