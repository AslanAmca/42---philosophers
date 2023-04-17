# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/04/17 23:27:00 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo_bonus
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
SRC			:= $(wildcard *.c)
OBJS		:= $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@clear

re: fclean all

norm:
	@norminette *.h *.c

.PHONY: all clean fclean re
