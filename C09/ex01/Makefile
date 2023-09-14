SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ = $(SRCS:.c=.o)
GCC = gcc -Wall -Wextra -Werror

all : libft.a

libft.a : $(OBJ) 
	ar -rc libft.a $(OBJ)
	ranlib libft.a

%.o : %.c
	$(GCC) -c $< -o $@ -I includes

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f libft.a

re: fclean all
