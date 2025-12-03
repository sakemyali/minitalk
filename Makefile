# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 14:51:35 by mosakura          #+#    #+#              #
#    Updated: 2025/12/02 15:03:51 by mosakura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER = ./files/server.c ./files/utils.c ./files/minitalk.c
SRCS_CLIENT = ./files/client.c ./files/utils.c ./files/minitalk.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./files

PRINTF_LIB = ./printf/libprintf.a

all: server client

bonus: server client

server: $(OBJS_SERVER) $(PRINTF_LIB)
	$(CC) -o $@ $(OBJS_SERVER) -Lprintf -lprintf

client: $(OBJS_CLIENT) $(PRINTF_LIB)
	$(CC) -o $@ $(OBJS_CLIENT) -Lprintf -lprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(PRINTF_LIB):
	make -C printf

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C printf clean

fclean: clean
	rm -f server client $(PRINTF_LIB)

re: fclean all

.PHONY: all bonus clean fclean re
