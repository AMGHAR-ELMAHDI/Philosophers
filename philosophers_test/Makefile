
HEADER = philosophers.h

NAME = philo

SRC =	mandatory/ft_libft_functions.c \
		mandatory/ft_split.c \
		mandatory/philo.c \
		mandatory/ft_strjoin.c \

CC = cc

CFLAGS = -Wall -Werror -Wextra 

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(SRC)  -o $(NAME)

clean : 
		rm -rf $(NAME)

fclean : clean

re : fclean all