# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruben <ruben@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 13:05:38 by rnuno-im          #+#    #+#              #
#    Updated: 2026/02/05 02:46:22 by ruben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= srcs/main.c \
			  srcs/parsing.c \
			  srcs/simulation.c \
			  srcs/threads.c \
			  srcs/utils/utils.c \
			  srcs/utils/init.c

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g
INCLUDES	= -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
