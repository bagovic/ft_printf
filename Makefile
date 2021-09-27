# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 09:27:40 by bagovic           #+#    #+#              #
#    Updated: 2021/09/27 09:41:38 by bagovic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_SRC = libft/
SRC = ft_printf.c

all: $(NAME)

$(NAME):
	make --directory=$(LIBFT_SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar r $(NAME) $(SRC:.c=.o)

clean:
	rm -f *.o
	make -C $(LIBFT_SRC) clean

fclean: clean
	rm -f $(NAME)
	make --directory=$(LIBFT_SRC) fclean

re: fclean all