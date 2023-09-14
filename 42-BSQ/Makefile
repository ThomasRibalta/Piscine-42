NAME = bsq

SRC =  srcs/*.c

OBJ =    *.o

FLAG = -Wall -Werror -Wextra

$(NAME) :
	gcc $(FLAG) $(SRC) -o $(NAME) -I includes

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
