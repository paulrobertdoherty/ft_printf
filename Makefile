# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 20:41:43 by pdoherty          #+#    #+#              #
#    Updated: 2018/11/14 19:23:42 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OUT = $(SRCS:%.c=%.o)

LIB = libft/libft.a

FLAGS = -Wall -Werror -Wextra

INCLUDES = printf.h

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft && make -C libft/ clean
	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	@gcc -o $(NAME) $(OUT) $(LIB)

clean:
	@rm -f $(OUT)

fclean:
	@rm -f $(OUT)
	@rm -f $(NAME)

re: fclean all
