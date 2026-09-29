# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/24 21:16:20 by sywee             #+#    #+#              #
#    Updated: 2026/09/29 19:35:24 by sywee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			= client
CLIENT_FILES	= client.c
CLIENT_OBJS		= $(CLIENT_FILES:%.c=%.o)

SERVER 			= server
SERVER_FILES 	= server.c
SERVER_OBJS 	= $(SERVER_FILES:%.c=%.o)

LIBFT = libft/libft.a
MINITALK = minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

%.o: %.c $(MINITALK)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C libft

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -Llibft -lft -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -Llibft -lft -o $(CLIENT)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C libft fclean

re: fclean all