CC = gcc

RM = rm -rf

NAME = get_next_line.a

MANDATORY = get_next_line.c\
			get_next_line_utils\

MANDATORY_SRCS	=	${MANDATORY}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${MANDATORY_OBJS}
			ar rc ${NAME} ${MANDATORY_OBJS}
			ranlib ${NAME}

all: ${NAME}

bonus:	 ${NAME}
			ar rc ${NAME} ${MANDATORY_OBJS}
			ranlib ${NAME}
clean:
	${RM} ${MANDATORY_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re