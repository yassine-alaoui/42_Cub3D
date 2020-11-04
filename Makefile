# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 18:43:39 by yaalaoui          #+#    #+#              #
#    Updated: 2020/02/14 18:47:06 by yaalaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#pls add the code srcs explicitly
SRC = $(wildcard *.c)

BONUS = $(wildcard *.o)

NAME = lib.a

all:	$(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar -rc  lib.a $(SRC:.c=.o)
	ranlib lib.a
	gcc -I /usr/local/include m.c lib.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -Ofast -o cub3D

bonus:
	gcc -Wall -Werror -Wextra -c $(SRC) $(BONUS)
	ar -rc  lib.a $(SRC:.c=.o) $(BONUS:.c=.o)
	ranlib lib.a

clean:
		rm -f $(SRC:.c=.o) $(BONUS:.c=.o)

fclean:	clean
		rm -f $(NAME)

re:		fclean all