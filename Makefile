
NAME = push_swap
libft = -I libft libft/libft.a
CFLAG = -Wall -Werror -Wextra

all : $(NAME)
	
$(NAME) :
	gcc -I libft main.c libft/libft.a
