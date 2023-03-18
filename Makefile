# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:38:48 by eamghar           #+#    #+#              #
#    Updated: 2023/03/18 15:24:52 by eamghar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = philosophers.h

NAME = philo

SRC =	mandatory/ft_libft_functions.c \
		mandatory/ft_split.c \
		mandatory/ft_threads.c \
		mandatory/philo.c \

CC = cc

CFLAGS = -Wall -Werror -Wextra 

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(SRC)  -o $(NAME)

clean : 
		rm -rf $(NAME)

fclean : clean

re : fclean all