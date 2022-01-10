# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 09:27:40 by bagovic           #+#    #+#              #
#    Updated: 2022/01/10 16:39:04 by bagovic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
SRC = ft_printf.c\
	ft_putnumber.c\
	ft_puthex.c

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) -c $(SRC)
	ar r $(NAME) $(SRC:.c=.o) $(LIBFT_DIR)*.o


clean:
	rm -f *.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
