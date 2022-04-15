
NAME 	= 	so_long

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror -g

SRCS 	=	so_long.c \


SRC_OBJS	=	$(SRCS:%.c=%.o)

RM          =	rm -f

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME) $(SRC_OBJS)

all : $(NAME)

clean:
		$(RM) $(SRC_OBJS)
		
fclean:		clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re