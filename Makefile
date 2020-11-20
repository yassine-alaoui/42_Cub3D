# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 18:43:39 by yaalaoui          #+#    #+#              #
#    Updated: 2020/11/16 12:35:57 by yaalaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub3d.c ft_strtrim.c get_next_line_utils.c m.c manage1.c mapstuff.c screenshot.c tools.c buildwall.c ft_split.c get_next_line.c helptools.c lil.c manage.c ohoplayer.c raycats.c sprite.c textures.c

BONUS = $(SRC:.c=.o)

NAME = lib.a

all:	$(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar -rc  lib.a $(SRC:.c=.o)
	ranlib lib.a
	gcc -Wall -Werror -Wextra -I /usr/local/include lib.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -Ofast -o cub3D

bonus:
	gcc -Wall -Werror -Wextra -c $(SRC) $(BONUS)
	ar -rc  lib.a $(SRC:.c=.o) $(BONUS:.c=.o)
	ranlib lib.a

clean:
		rm -f $(SRC:.c=.o) $(BONUS:.c=.o) cub3D

fclean:	clean
		rm -f $(NAME)

re:		fclean all