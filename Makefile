# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 16:23:43 by pdoherty          #+#    #+#              #
#    Updated: 2018/11/30 22:11:55 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OUT = $(SRCS:%.c=%.o)

INCLUDES = libft/libft.h printf.h

all: $(NAME)

$(NAME):
	@make -C libft
	@cp libft/libft.a $(NAME)
	@gcc -c $(SRCS) -I $(INCLUDES)
	@ar rcs $(NAME) $(OUT)
	@ranlib $(NAME)
	
clean:
	@rm -f $(OUT)
	@make clean -C libft

fclean:
	@rm -f $(OUT)
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean $(NAME)
