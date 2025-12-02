# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 23:09:13 by mosakura          #+#    #+#              #
#    Updated: 2025/12/02 12:43:15 by mvrm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libprintf.a

SRCS		= ft_printf.c \
			  print.c \
			  print2.c \
			  utils.c

OBJS		= $(SRCS:.c=.o)

CC			= cc

FLAGS		= -Wall -Werror -Wextra -I ./

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
