NAME = philosophers
CC = cc -g
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c init_table.c philo_routine.c utils.c
SRCS = $(addprefix  src/, $(SRC_FILES))
OBJ_SRC = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ_SRC}
	${CC} ${FLAGS} ${OBJ_SRC} -o ${NAME}

clean:
	rm -rf ${OBJ_SRC}

fclean: clean
	rm -rf ${NAME}

re: fclean all
