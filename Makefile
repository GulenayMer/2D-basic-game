
NAME 	= 	so_long

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror -g

SRCS 	=	so_long.c \
			utils.c \

LIBFT		= libft/libft.a

SRC_OBJS	=	$(SRCS:%.c=%.o)

RM          =	rm -f

$(NAME): $(SRC_OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJS) $(LIBFT)

all : $(NAME)

clean:
		$(RM) $(SRC_OBJS)
		make clean -C libft/

fclean:		clean
				$(RM) $(NAME)
				make fclean -C libft/

re: 		fclean all

.PHONY: all clean fclean re