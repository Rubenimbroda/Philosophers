# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruben <ruben@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 13:05:38 by rnuno-im          #+#    #+#              #
#    Updated: 2026/02/12 00:20:37 by ruben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= srcs/main.c \
			  srcs/parsing.c \
			  srcs/simulation.c \
			  srcs/threads.c \
			  srcs/utils/utils.c \
			  srcs/utils/str_utils.c \
			  srcs/init.c

OBJ_DIR = obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
INCLUDES	= -I includes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "✅ Compilation complete: $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️  All cleaned."

re: fclean all

.PHONY: all clean fclean re
