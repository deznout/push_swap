PUSH_SWAP = push_swap
CHECKER	 = checker
CFLAGS = -Wall -Wextra -Werror

CC	 = gcc

HEADER = push_swap.h

RM = rm -f

SRC =	main.c	ft_split.c	markup.c	parsing.c	sorting.c	libft.c	operUtils.c \
		utils_4_sort.c	from_B_to_A.c	init.c	operations.c	rot_actions.c

CH_SRC =	gnl/get_next_line.c	gnl/get_next_line_utils.c	checker.c	init.c	ft_split.c	markup.c \
			libft.c	parsing.c	utils_4_sort.c	operations.c	operUtils.c	sorting.c	from_B_to_A.c	rot_actions.c

OBJS	= ${SRC:.c=.o}
CH_OBJS	= ${CH_SRC:.c=.o}

all:	${PUSH_SWAP}

.c.o:
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

$(PUSH_SWAP):	$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) -g -o $(PUSH_SWAP)

$(CHECKER):	$(CH_OBJS)
				$(CC) $(CH_OBJS) $(CFLAGS) -g -o $(CHECKER)

bonus:	${PUSH_SWAP} ${CHECKER}

clean:
	${RM} ${OBJS} ${CH_OBJS}

fclean:	 clean
		${RM} ${PUSH_SWAP} ${CHECKER}

re: 	fclean all

.PHONY:  all clean fclean re