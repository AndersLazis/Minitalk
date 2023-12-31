# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 17:24:13 by aputiev           #+#    #+#              #
#    Updated: 2023/04/22 17:24:17 by aputiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERV = server

NAMECLIENT = client

PRINTF = libftprintf.a

INCLUDE = -I include

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCSERV =	server.c

SRCCLIENT = client.c client_utils.c \

OBJSERV =	server.o

OBJCLIENT = client.o client_utils.o \

all: $(NAMESERV) $(NAMECLIENT)

$(NAMESERV): $(OBJSERV)
	make -C printf
	$(CC) $(CFLAGS) $(OBJSERV) printf/$(PRINTF) -o $(NAMESERV)

$(NAMECLIENT): $(OBJCLIENT)
	make -C printf
	$(CC) $(CFLAGS) $(OBJCLIENT) printf/$(PRINTF) -o $(NAMECLIENT)

clean:
	make clean -C printf
	$(RM) $(OBJCLIENT)
	$(RM) $(OBJSERV)

fclean: clean
	make fclean -C printf
	$(RM) $(NAMECLIENT)
	$(RM) $(NAMESERV)

re: fclean all

.PHONY:	all clean fclean re