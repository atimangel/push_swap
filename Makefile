
SRC = swap.c\
      push.c\
      reverse_rotate.c\
      rotate.c\
	  make_list.c\
	  node.c\
	check_order.c\
	sort.c


NAME = push_swap
libft = -I libft libft/libft.a
CFLAG = -Wall -Werror -Wextra

all : $(NAME)
	
$(NAME) : $(SRC)
	make -C ./libft
	gcc -I libft main.c $(SRC) libft/libft.a -o push_swap

test :
	make -C ./libft
	gcc -g3 -I libft main.c $(SRC) libft/libft.a -o push_swap

clean :
	rm *.o
	rm */*.o

fclean : 
	rm $(NAME)

re : fclean $(NAME)
