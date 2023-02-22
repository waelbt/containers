# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:01:46 by waboutzo          #+#    #+#              #
#    Updated: 2023/02/22 10:27:37 by waboutzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS = --std=c++98 -Wall -Wextra -Werror

vector:
	c++ $(CPPFLAGS) vector/vector_tests.cpp -o vector.out


map:
	c++ $(CPPFLAGS)	map/map_tests.cpp -o map.out


stack:
	c++ $(CPPFLAGS)	stack/stack_tests.cpp -o stack.out


set:
	c++ $(CPPFLAGS)	set/set_tests.cpp -o set.out


clean:
	rm -f vector.out  map.out  stack.out  set.out 
	
.PHONY: vector map stack set clean