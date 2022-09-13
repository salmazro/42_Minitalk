# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 21:58:46 by salmazro          #+#    #+#              #
#    Updated: 2022/07/18 16:14:29 by salmazro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRC = client.c server.c error.c
OBJ = ${SRC:.c=.o}

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
		${CC} ${CFLAGS} -o ${SERVER} server.o

$(CLIENT): client.o error.o
		${CC} ${CFLAGS} -o ${CLIENT} client.o error.o

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${SERVER} $(CLIENT)

re: fclean all


