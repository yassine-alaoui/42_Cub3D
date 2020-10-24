make re
gcc -I /usr/local/include m.c lib.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g -Ofast -fsanitize=address
./a.out map.cub
 