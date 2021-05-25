
SRC = swap.c\

NAME = push_swap
libft = -I libft libft/libft.a
CFLAG = -Wall -Werror -Wextra

all : $(NAME)
	
$(NAME) : $(SRC)
	gcc -I libft main.c $(SRC) libft/libft.a -o push_swap

clean :
	rm *.o
	rm */*.o

fclean : 
	rm $(NAME)

re : fclean $(NAME)
