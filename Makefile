# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 09:27:40 by bagovic           #+#    #+#              #
#    Updated: 2021/12/06 13:34:51 by berminagovi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
SRC = ft_printf.c\
	datas.c\
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
