# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 14:00:04 by mgulenay          #+#    #+#              #
#    Updated: 2022/05/25 14:00:07 by mgulenay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	so_long

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror -g

SRCS 	=	so_long.c \
			readmap.c \
			map_img.c \
			errorcheck.c \
			errorcheck2.c \
			errorcheck3.c \
			moves.c \

LIBFT		= libft/libft.a

SRC_OBJS	=	$(SRCS:%.c=%.o)

RM          =	rm -f

$(NAME): $(SRC_OBJS)
	make -C libft/
	$(CC) $(CFLAGS)  mlx/libmlx.a  -framework OpenGL -framework AppKit -o $(NAME) $(SRC_OBJS) $(LIBFT)

all : $(NAME)

clean:
		$(RM) $(SRC_OBJS)
		make clean -C libft/

fclean:		clean
				$(RM) $(NAME)
				make fclean -C libft/

re: 		fclean all

.PHONY: all clean fclean re