make re
gcc -I /usr/local/include m.c lib.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g -Ofast
./a.out map.cub
 