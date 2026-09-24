# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/24 21:16:20 by sywee             #+#    #+#              #
#    Updated: 2026/09/24 21:28:26 by sywee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
SERVER_FILES = server.c
SERVER_OBJS = $(SERVER_FILES:%.c=%.o)

LIBFT = libft/libft.a
MINITALK = minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(MINITALK)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(SERVER)

$(LIBFT):
	$(MAKE) -C libft

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -Llibft -lft -o $(SERVER)
