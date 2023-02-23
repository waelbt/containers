# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:01:46 by waboutzo          #+#    #+#              #
#    Updated: 2023/02/23 18:05:54 by waboutzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers
CPPFLAGS = --std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.cpp
	c++ $(CPPFLAGS) $^ -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re